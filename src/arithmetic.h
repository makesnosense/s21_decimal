#ifndef SRC_ARITHMETIC_H_
#define SRC_ARITHMETIC_H_

#include <stdbool.h>
#include <stdint.h>

#include "utility.h"

typedef enum ArithmeticResult {
  OK = 0,
  TOO_BIG = 1,
  TOO_SMALL = 2,
  DIVISION_BY_ZERO = 3
} ArithmeticResult;

ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign);

void compose_decimal(uint32_t* mantissa, int scale, Sign sign,
                     s21_decimal* decimal);

bool limit_precision(uint32_t* long_mantissa, int* result_scale,
                     uint32_t* mantissa);

void normalize_division_result(uint32_t* result, int* scale);

#endif  // SRC_ARITHMETIC_H_
