#include <stdbool.h>
#include <stdint.h>

#include "s21_decimal.h"

typedef enum ComparisonResult {
  FALSE = 0,
  TRUE = 1,
  COMPARISON_INPUT_ERROR = 2,
} ComparisonResult;

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2);

void invert_result_due_to_decimal_signs(bool both_are_negative, bool* result);
