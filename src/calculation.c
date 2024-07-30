#include <calculation.h>
#include <stdio.h>
#include <utility.h>

#include "s21_decimal.h"

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