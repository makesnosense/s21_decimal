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
