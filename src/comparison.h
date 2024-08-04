#include <stdbool.h>
#include <stdint.h>

#include "s21_decimal.h"

typedef enum ComparisonResult {
  FALSE = 0,
  TRUE = 1,
} ComparisonResult;

s21_two_decimals sort_decimals_ascending_by_scale(s21_decimal decimal_1,
                                                  s21_decimal decimal_2);

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2);
int get_scale_difference_from_decimals(s21_decimal decimal_1,
                                       s21_decimal decimal_2);
void cast_decimals_to_normalized_mantissas(s21_decimal decimal_1,
                                           uint32_t* normalized_mantissa_1,
                                           s21_decimal decimal_2,
                                           uint32_t* normalized_mantissa_2);
// void invert_result_due_to_sign(int is_negative, bool* result);
void invert_result_due_to_decimal_signs(bool both_are_negative, bool* result);
// 00000000000000010000000000000000

// 0 0 0 0 0 0 0 0 0 0  0  0  0  0  0  0
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 unused

//  0  0  0  0  0  0  0  0
// 16 17 18 19 20 21 22 23

// 0  0  0   0  0  0  0
// 24 25 26 27 28 29 30 unused
// 0
// 31 sign

// 00000000|00000001|0000000000000000