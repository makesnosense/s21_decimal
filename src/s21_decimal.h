#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct s21_decimal_t {
  uint32_t bits[4];
} s21_decimal;

typedef struct s21_two_decimals_t {
  s21_decimal decimals[2];
} s21_two_decimals;

typedef struct s21_big_decimal_t {
  uint32_t bits[7];
} s21_big_decimal;

// arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

// comparison
int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_less_or_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_greater_or_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_is_not_equal(s21_decimal decimal_1, s21_decimal decimal_2);

// conversion
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

// calculation
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

#endif  // SRC_S21_DECIMAL_H_
