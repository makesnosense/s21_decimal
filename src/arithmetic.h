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
} ArithmeticResult;

ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign);

#endif  // SRC_ARITHMETIC_H_