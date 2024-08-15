#include "s21_decimal.h"
#include "utility.h"

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

typedef enum ConversionResult {
  OK = 0,
  CONVERSION_ERROR = 1,
} ConversionResult;

int get_float_exponent_from_string(char* input);

s21_decimal s21_float_string_to_decimal(char* str);

uint32_t* s21_decimal_get_from_char(char c);