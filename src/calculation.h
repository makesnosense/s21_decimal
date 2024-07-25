typedef enum CalculationResult {
  OK = 0,
  CONVERSION_ERROR = 1,
} CalculationResult;

int get_scale_difference_from_decimals(s21_decimal decimal_1,
                                       s21_decimal decimal_2);