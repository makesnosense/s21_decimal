#include "calculation.h"

#include <stdio.h>

int s21_floor(s21_decimal value, s21_decimal* result) {
  CalculationResult return_code;
  if (result == NULL) {
    return_code = CALCULATION_ERROR;
  } else {
    if (zero_check_mantissa(value.bits)) {
      copy_mantissa(result->bits, value.bits);
    } else {
      int scale = get_scale(value.bits[3]);
      int is_negative = get_sign(value);
      uint32_t* scale_divisor = get_mantissa_with_power_of_ten(scale);
      uint32_t remainder[3];
      mantissa_division(value.bits, scale_divisor, result->bits, remainder);
      if (is_negative && !zero_check_mantissa(remainder)) {
        uint32_t* one = get_mantissa_with_power_of_ten(0);
        mantissa_addition(result->bits, one, result->bits);
      }
    }
    result->bits[3] = value.bits[3];
    set_scale(&result->bits[3], 0);
    return_code = OK;
  }
  return return_code;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  CalculationResult return_code;

  if (result == NULL) {
    return_code = CALCULATION_ERROR;
  } else {
    *result = value;
    get_sign(value) == PLUS ? set_sign(result, MINUS) : set_sign(result, PLUS);
    return_code = OK;
  }

  return return_code;
}

uint64_t divide_decimal_by_10(s21_decimal* input_decimal) {
  uint64_t remainder = 0;
  for (int i = 2; i >= 0; i--) {
    uint64_t temp = ((uint64_t)remainder << 32) | input_decimal->bits[i];
    input_decimal->bits[i] = (uint32_t)(temp / 10);
    remainder = temp % 10;
  }
  return remainder;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  CalculationResult return_code;

  if (result == NULL) {
    return_code = CALCULATION_ERROR;
  } else {
    *result = value;

    int scale = get_scale(value.bits[3]);
    int sign = get_sign(value);

    for (int i = 0; i < scale; i++) {
      divide_decimal_by_10(result);
    }

    set_scale(&result->bits[3], 0);
    set_sign(result, sign);
    return_code = OK;
  }
  return return_code;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  CalculationResult return_code;

  if (result == NULL) {
    return_code = CALCULATION_ERROR;
  } else {
    *result = value;
    uint64_t remainder = 0;
    int scale = get_scale(value.bits[3]);
    int sign = get_sign(value);

    for (int i = 0; i < scale; i++) {
      remainder = divide_decimal_by_10(result);
    }

    if (remainder >= 5) {
      uint32_t result_mantissa[3] = {0};
      uint32_t mantissa_containing_one[3] = {0x1, 0x0, 0x0};
      uint32_t result_mantissa_added_one[3] = {0};
      get_mantissa_from_decimal(result_mantissa, result);

      mantissa_addition(result_mantissa, mantissa_containing_one,
                        result_mantissa_added_one);
      write_in_mantissa_to_decimal(result_mantissa_added_one, result);
    }

    set_scale(&result->bits[3], 0);
    set_sign(result, sign);
    return_code = OK;
  }
  return return_code;
}