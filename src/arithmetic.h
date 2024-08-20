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

bool input_is_correct(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal* result);

ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign);

void compose_decimal(uint32_t* mantissa, int scale, Sign sign,
                     s21_decimal* decimal);

bool multiply_division_result(uint32_t* result, uint32_t* remainder,
                              uint32_t* divisor, int multiplier_scale);

int downsize_division_result(uint32_t* upscaled_mantissa, uint32_t* remainder,
                             uint32_t* divisor, uint32_t* mantissa);

void round_division_result_to_even(uint32_t* result, uint32_t* remainder,
                                   uint32_t* divisor, uint32_t* rounded_result);

void normalize_division_result(uint32_t* result, int* scale,
                               int dividend_scale);

#endif  // SRC_ARITHMETIC_H_
