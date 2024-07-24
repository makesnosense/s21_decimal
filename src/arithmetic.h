#include <stdint.h>

typedef enum ArithmeticResult {
  OK = 0,
  TOO_BIG = 1,
  TOO_SMALL = 2,
  DIVISION_BY_ZERO = 3,
} ArithmeticResult;

void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result);