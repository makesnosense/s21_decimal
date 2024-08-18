#ifndef SRC_ARITHMETIC_H_
#define SRC_ARITHMETIC_H_

#include <stdbool.h>
#include <stdint.h>

#include "utility.h"

typedef enum ArithmeticResult {
  OK = 0,
  TOO_BIG = 1,
  TOO_SMALL = 2,
  DIVISION_BY_ZERO = 3,
  INPUT_ERROR = 4,
} ArithmeticResult;

ArithmeticResult actually_multiply(s21_decimal value_1, s21_decimal value_2,
                                   bool* is_overflow, Sign result_sign,
                                   s21_decimal* result);
ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign);

#endif  // SRC_ARITHMETIC_H_