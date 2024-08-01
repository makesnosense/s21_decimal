#include "calculation.h"

#include <stdio.h>

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

// TODO: remove remainder after mantissa_division refactor
/* int s21_truncate(s21_decimal value, s21_decimal* result) {
  int scale = get_scale(value.bits[3]);
  uint32_t* scale_divisor = get_mantissa_with_power_of_ten(scale);
  uint32_t remainder[3];
  mantissa_division(value.bits, scale_divisor, result->bits, remainder);
  result->bits[3] = value.bits[3];
  set_scale(&result->bits[3], 0);
  return 0;
} */

// TODO: remove remainder after mantissa_division refactor
/* int s21_round(s21_decimal value, s21_decimal* result) {
  int scale = get_scale(value.bits[3]);
  int sign = get_sign(value);
  uint32_t* scale_divisor = get_mantissa_with_power_of_ten(scale);
  uint32_t remainder[3];
  mantissa_division(value.bits, scale_divisor, result->bits, remainder);
  if (!zero_check_mantissa(value.bits)) {
    uint32_t* upscaled_remainder;
    uint32_t* first_fraction_digit;
    uint32_t* ten = get_mantissa_with_power_of_ten(1);
    uint32_t* one = get_mantissa_with_power_of_ten(0);
    multiply_mantissas(remainder, ten, upscaled_remainder);
    mantissa_division(upscaled_remainder, ten, first_fraction_digit, remainder);
    if (first_fraction_digit == 5) {
      if (zero_check_mantissa(remainder)) {
        mantissa_addition(result, one, result);
      } else {
        mantissa_subtraction(result, one, result);
      }
    } else if (first_fraction_digit > 5) {
      mantissa_addition(result, one, result);
    } else {
      mantissa_subtraction(result, one, result);
    }
  }
  result->bits[3] = value.bits[3];
  set_scale(&result->bits[3], 0);
  return 0;
} */

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
        mantissa_addition(result, one, result);
      }
    }
    result->bits[3] = value.bits[3];
    set_scale(&result->bits[3], 0);
    return_code = OK;
  }
  return return_code;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  if (1 == 0) {
    printf("%d", value.bits[0]);
    printf("%d", result->bits[0]);
  }
  return 0;
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

void divide_by_10_dropping_remainder(s21_decimal* input_decimal) {
  uint64_t remainder = 0;
  for (int i = 2; i >= 0; i--) {
    uint64_t temp = ((uint64_t)remainder << 32) | input_decimal->bits[i];
    input_decimal->bits[i] = (uint32_t)(temp / 10);
    remainder = temp % 10;
  }
}

int s21_truncate(s21_decimal input_decimal, s21_decimal* result) {
  CalculationResult return_code;

  if (result == NULL) {
    return_code = CALCULATION_ERROR;
  } else {
    *result = input_decimal;

    int scale = get_scale(input_decimal.bits[3]);
    int sign = get_sign(input_decimal);

    for (int i = 0; i < scale; i++) {
      divide_by_10_dropping_remainder(result);
    }

    set_scale(&result->bits[3], 0);
    set_sign(result, sign);
    return_code = OK;
  }
  return return_code;
}