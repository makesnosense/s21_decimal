#include <stdint.h>

#include "s21_decimal.h"


typedef enum CalculationResult {
  OK = 0,
  CALCULATION_ERROR = 1,
} CalculationResult;

uint64_t divide_decimal_by_10(s21_decimal* input_decimal);