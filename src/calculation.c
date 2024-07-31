#include "calculation.h"

#include <stdio.h>

#include "s21_decimal.h"
#include "utility.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
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

void divide_by_10(s21_decimal* input_decimal) {
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
      divide_by_10(result);
    }

    result->bits[3] = 0;
    set_sign(result, sign);
    return_code = OK;
  }
  return return_code;
}