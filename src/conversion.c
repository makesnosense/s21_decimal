#include "conversion.h"

#include <ctype.h>
#include <math.h>

#include "debug_funcs.h"

int s21_from_int_to_decimal(int src, s21_decimal* dst) {
  ConversionResult result = OK;
  if (dst == NULL) {
    result = CONVERSION_ERROR;
  } else {
    reset_decimal(dst);
    if (src < 0) {
      set_sign(dst, MINUS);
      dst->bits[0] = -src;
    } else {
      dst->bits[0] = src;
    }
  }
  return result;
}

int from_float_special_values_to_decimal(float src, s21_decimal* dst) {
  ConversionResult code = OK;
  if (src == 0.0) {
    code = OK;
    *dst = DECIMAL_ZERO;
    if (signbit(src) != 0) {
      set_sign(dst, MINUS);
    }
  } else {
    code = CONVERSION_ERROR;
    if (fabsf(src) < MIN_FLOAT_FITTING_INTO_DECIMAL) {
      *dst = DECIMAL_ZERO;
    } else {
      if (isinf(src) == true) {
        *dst = DECIMAL_POSITIVE_INFINITY;
      } else if (isnan(src) == true) {
        *dst = DECIMAL_POSITIVE_NAN;
      } else /* fabsf(src) > MAX_FLOAT_FITTING_INTO_DECIMAL */ {
        *dst = DECIMAL_POSITIVE_INFINITY;
      }
      if (signbit(src) != 0) {
        set_sign(dst, MINUS);
      }
    }
  }
  return code;
}

bool float_is_special_value(float input_num) {
  return (input_num == 0.0) || (isinf(input_num) == true) ||
         (isnan(input_num) == true) ||
         (fabsf(input_num) > MAX_FLOAT_FITTING_INTO_DECIMAL) ||
         (fabsf(input_num) < MIN_FLOAT_FITTING_INTO_DECIMAL);
}

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  ConversionResult return_code = OK;
  if (dst == NULL) {
    return CONVERSION_ERROR;
  }
  if (float_is_special_value(src)) {
    return_code = from_float_special_values_to_decimal(src, dst);
  } else {
    *dst = DECIMAL_ZERO;
    s21_decimal result;
    result = DECIMAL_ZERO;

    char strinf_float[64] = {0};
    sprintf(strinf_float, "%.*E", E_NOTATION_PRECISION, fabsf(src));

    int exponent = get_float_exponent_from_string(strinf_float);

    int max_exponent_to_fit_in_decimal = MAX_SCALE - E_NOTATION_PRECISION + 1;

    if (exponent <= -max_exponent_to_fit_in_decimal) {
      int float_precision = exponent + MAX_SCALE;
      sprintf(strinf_float, "%.*E", float_precision, fabsf(src));
    }

    result = float_string_to_decimal(strinf_float);

    if (signbit(src) != 0) {
      set_sign(&result, MINUS);
    }

    *dst = result;
  }

  return return_code;
}

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  if (dst == NULL || decimal_service_part_is_correct(src) == false) {
    return CONVERSION_ERROR;
  }

  ConversionResult return_code = OK;
  s21_decimal temp_decimal;
  reset_decimal(&temp_decimal);
  s21_truncate(src, &temp_decimal);
  s21_decimal max_int = {{0x7FFFFFFF, 0x0, 0x0, 0b0}};
  s21_decimal min_int = {
      {0x80000000, 0x0, 0x0, 0b10000000000000000000000000000000}};
  if (s21_is_greater(temp_decimal, max_int) ||
      s21_is_less(temp_decimal, min_int)) {
    return_code = CONVERSION_ERROR;
  } else {
    // ꙳ ✯ LE EPIC CONVERT ✯ ⋆
    *dst = temp_decimal.bits[0];
    *dst = (get_sign(src) == MINUS) ? -*dst : *dst;
  }

  return return_code;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  ConversionResult conversion_result = OK;
  if (dst == NULL || decimal_service_part_is_correct(src) == false) {
    return CONVERSION_ERROR;
  }
  if (s21_is_equal(src, DECIMAL_ZERO)) {
    int sign = get_sign(src);
    if (sign == 0) {
      *dst = 0.0f;
    } else {
      *dst = -0.0f;
    }
    conversion_result = OK;
  } else {
    *dst = 0.0f;
    double temp = 0.0;
    int sign = get_sign(src) ? -1 : 1;
    int scale = get_scale(src.bits[3]);
    for (int i = 0; i < MANTISSA_PARTS; i++) {
      temp += src.bits[i] * pow(2.0, (PART_SIZE * i));
    }
    temp = temp / pow(10.0F, scale) * sign;
    *dst = (float)temp;
  }
  return conversion_result;
}

int get_float_exponent_from_string(char* str) {
  int result = 0;
  int sign = 1;
  while (*str != 'E') str++;
  str++;
  if (*str == '-') {
    sign = -1;
    str++;
  } else {
    sign = 1;
    str++;
  }
  while (isdigit(*str)) {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result * sign;
}

void write_in_string_significand_to_decimal(char* ptr,
                                            uint32_t* result_mantissa,
                                            s21_decimal* result) {
  int digits_counter = FLOAT_SIGNIFICANT_DIGITS - 1;
  while (*ptr != 'E') {
    if (*ptr == '.') {
      ++ptr;
      continue;
    } else {
      s21_decimal tmp = {{0x0, 0x0, 0x0, 0x0}};
      uint32_t tmp_mantissa[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
      multiply_mantissas(s21_decimal_get_from_char(*ptr),
                         get_mantissa_with_power_of_ten(digits_counter),
                         tmp_mantissa);

      add_mantissas(result_mantissa, tmp_mantissa, result_mantissa);
      write_in_mantissa_to_decimal(result_mantissa, &tmp);
      copy_mantissa(result->bits, result_mantissa);
      digits_counter--;
      ptr++;
    }
  }
}

s21_decimal float_string_to_decimal(char* str) {
  s21_decimal result = {{0x0, 0x0, 0x0, 0x0}};
  uint32_t result_mantissa[3] = {0};
  uint32_t remainder[3] = {0};

  int exp = get_float_exponent_from_string(str);

  write_in_string_significand_to_decimal(str, result_mantissa, &result);

  exp = exp - E_NOTATION_PRECISION;

  if (exp != 0) {
    if (exp > 0) {
      multiply_mantissas(result_mantissa, get_mantissa_with_power_of_ten(exp),
                         result.bits);
      copy_mantissa(result_mantissa, result.bits);
    } else {
      if (exp < -MAX_SCALE) {
        exp += MAX_SCALE;
        divide_mantissas(result_mantissa, get_mantissa_with_power_of_ten(-exp),
                         result.bits, remainder);
        copy_mantissa(result_mantissa, result.bits);
        exp = -MAX_SCALE;
      }
    }
  }

  if (exp > 0) {
    exp = 0;
  }

  if (exp < 0) {
    exp *= -1;
  }

  set_scale(&result.bits[3], exp);

  return result;
}

uint32_t* s21_decimal_get_from_char(char c) {
  static uint32_t result[3] = {0, 0, 0};

  result[0] = c - '0';

  return result;
}
