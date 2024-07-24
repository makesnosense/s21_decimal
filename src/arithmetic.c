#include "s21_decimal.h"
#include "utility.h"
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  return 0;
}

void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result) {
  // Очищаем результат
  s21_memset(result, 0, sizeof(uint32_t) * 6);

  for (int i = 0; i < 3; i++) {
    uint64_t carry = 0;
    for (int j = 0; j < 3; j++) {
      uint64_t product =
          (uint64_t)mantissa_1[i] * mantissa_2[j] + result[i + j] + carry;
      result[i + j] = (uint32_t)product;
      carry = product >> 32;
    }
    result[i + 3] = carry;
  }
}
