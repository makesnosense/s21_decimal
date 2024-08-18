#ifndef SRC_CONVERSION_H_
#define SRC_CONVERSION_H_

#include "s21_decimal.h"
#include "utility.h"

#define MAX_FLOAT_FITTING_INTO_DECIMAL 79228157791897854723898736640.0f
#define MIN_FLOAT_FITTING_INTO_DECIMAL \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

#define FLOAT_SIGNIFICANT_DIGITS 7
#define E_NOTATION_PRECISION 6

typedef enum ConversionResult {
  OK = 0,
  CONVERSION_ERROR = 1,
} ConversionResult;

bool float_is_special_value(float input_num);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int get_float_exponent_from_string(char* input);
s21_decimal float_string_to_decimal(char* str);
uint32_t* s21_decimal_get_from_char(char c);

#endif  // SRC_CONVERSION_H_