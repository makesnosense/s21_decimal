#include "arithmetic.h"

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);
  ArithmeticResult result_add = OK;

  uint32_t term_1_long_mantissa[6] = {0};
  uint32_t term_2_long_mantissa[6] = {0};
  uint32_t result_long_mantissa[6] = {0};

  int bigger_scale = cast_decimals_to_normalized_mantissas(
      value_1, term_1_long_mantissa, value_2, term_2_long_mantissa);

  int result_sign = PLUS;

  if (get_sign(value_1) == PLUS) {
    if (get_sign(value_2) == PLUS) {
      // (a) + (b) = a + b
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
    } else /* (a) + (- b) = a - b*/ {
      result_sign = subtract_long_mantissas(
          term_1_long_mantissa, term_2_long_mantissa, result_long_mantissa);
    }
  } else /* (-a) + (b) =  b - a */ {
    if (get_sign(value_2) == PLUS) {
      result_sign = subtract_long_mantissas(
          term_2_long_mantissa, term_1_long_mantissa, result_long_mantissa);
    } else /* (-a) + (-b) = - (a + b) */ {
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    }
  }
  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  compose_decimal(result_mantissa, bigger_scale, result_sign, result);
  result_add = catch_overflow(is_overflow, result_sign);
  return result_add;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);
  ArithmeticResult result_sub = OK;
  uint32_t minuend_normalized_long_mantissa[6] = {0};
  uint32_t subtrahend_normalized_long_mantissa[6] = {0};
  uint32_t result_long_mantissa[6] = {0};
  int bigger_scale = cast_decimals_to_normalized_mantissas(
      value_1, minuend_normalized_long_mantissa, value_2,
      subtrahend_normalized_long_mantissa);
  int result_sign = PLUS;
  if (get_sign(value_1) == PLUS) {
    if (get_sign(value_2) == PLUS) /* (a) - (b) = a - b */ {
      result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                            subtrahend_normalized_long_mantissa,
                                            result_long_mantissa);
    } else /* (a) - (- b) = a + b */ {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
    }
  } else /* (-a) - (b) =  - (a+b) */ {
    if (get_sign(value_2) == PLUS) {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    } else /* (-a) - (-b) = b - a */ {
      result_sign = subtract_long_mantissas(subtrahend_normalized_long_mantissa,
                                            minuend_normalized_long_mantissa,
                                            result_long_mantissa);
    }
  }
  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  compose_decimal(result_mantissa, bigger_scale, result_sign, result);
  result_sub = catch_overflow(is_overflow, result_sign);
  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  ArithmeticResult result_mul = OK;
  Sign result_sign = PLUS;

  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  if (get_sign(value_1) != get_sign(value_2)) {
    result_sign = MINUS;
  }

  uint32_t mantissa_value_1[3] = {0};
  uint32_t mantissa_value_2[3] = {0};
  uint32_t long_mantissa_result[6] = {0};
  uint32_t mantissa_result[3] = {0};

  get_mantissa_from_decimal(mantissa_value_1, value_1);
  get_mantissa_from_decimal(mantissa_value_2, value_2);

  multiply_mantissas(mantissa_value_1, mantissa_value_2, long_mantissa_result);

  uint32_t initital_long_result[6] = {0};

  copy_long_mantissa(initital_long_result, long_mantissa_result);

  int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);
  bool is_overflow =
      limit_precision(long_mantissa_result, &scale_result, mantissa_result);
  compose_decimal(mantissa_result, scale_result, result_sign, result);
  result_mul = catch_overflow(is_overflow, result_sign);
  return result_mul;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (is_zero_decimal(value_2)) {
    return DIVISION_BY_ZERO;
  }
  uint32_t temp_result[6] = {0};
  int result_scale = get_scale(value_1.bits[3]) - get_scale(value_2.bits[3]);

  if (is_zero_decimal(value_1)) {
    if (result_scale < 0) {
      result_scale = 0;
    }
  } else {
    uint32_t remainder[6] = {0};
    uint32_t divisor[6] = {0};
    copy_mantissa(divisor, value_2.bits);
    divide_mantissas(value_1.bits, value_2.bits, temp_result, remainder);
    uint32_t* ten = get_mantissa_with_power_of_ten(1);
    int result_digits;
    if (long_mantissa_is_zero(temp_result)) {
      result_digits = 0;
    } else {
      result_digits = count_long_mantissa_digits(temp_result);
    }
    uint32_t fractal_digit[6] = {0};
    while (result_digits < 30) {
      multiply_long_mantissas(remainder, ten, remainder);
      divide_long_mantissas(remainder, divisor, fractal_digit, remainder);
      multiply_long_mantissas(temp_result, ten, temp_result);
      add_long_mantissas(temp_result, fractal_digit, temp_result);
      result_scale += 1;
      if (result_digits != 0 || fractal_digit[0] != 0) {
        result_digits += 1;
      }
    }
  }
  uint32_t downsized_result[3] = {0};
  bool overflow = limit_precision(temp_result, &result_scale, downsized_result);
  normalize_division_result(downsized_result, &result_scale);
  Sign result_sign = PLUS;
  if (get_sign(value_1) != get_sign(value_2)) {
    result_sign = MINUS;
  }
  ArithmeticResult result_code = catch_overflow(overflow, result_sign);
  if (result_code == OK) {
    compose_decimal(downsized_result, result_scale, result_sign, result);
  }
  return result_code;
}

ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign) {
  ArithmeticResult arithmetic_result = OK;
  if (is_overflow) {
    if (result_sign == PLUS) {
      arithmetic_result = TOO_BIG;
    } else {
      arithmetic_result = TOO_SMALL;
    }
  }
  return arithmetic_result;
}

void compose_decimal(uint32_t* mantissa, int scale, Sign sign,
                     s21_decimal* decimal) {
  memset(decimal, 0, sizeof(s21_decimal));
  copy_mantissa(decimal->bits, mantissa);
  set_sign(decimal, sign);
  set_scale(&decimal->bits[3], scale);
}

bool limit_precision(uint32_t* long_mantissa, int* result_scale,
                     uint32_t* mantissa) {
  bool overflow = false;
  int removed_digits =
      downsize_mantissa(long_mantissa, result_scale, mantissa, &overflow);
  if (*result_scale > 28) {
    int digits_to_remove = (*result_scale - 28) + removed_digits;
    *result_scale = 28;
    remove_digits_rounding_to_even(long_mantissa, digits_to_remove, mantissa);
  }
  return overflow;
}

void normalize_division_result(uint32_t* result, int* scale) {
  uint32_t last_digit[3] = {0};
  uint32_t temp_result[3] = {0};
  uint32_t* ten = get_mantissa_with_power_of_ten(1);

  divide_mantissas(result, ten, temp_result, last_digit);
  while ((last_digit[0] == 0) && (*scale > 0)) {
    *scale -= 1;
    copy_mantissa(result, temp_result);
    divide_mantissas(result, ten, temp_result, last_digit);
  }
}
