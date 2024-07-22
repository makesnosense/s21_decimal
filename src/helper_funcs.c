#include "helper_funcs.h"

int get_bit(uint32_t input_uint, size_t position) {
  return (input_uint >> position) & 1;
}

int set_bit(uint32_t input_uint, size_t position) {
  return input_uint | (1 << position);
}

int reset_bit(uint32_t input_uint, size_t position) {
  return input_uint & ~(1 << position);
}

int assign_bit(uint32_t input_uint, size_t position, Binary value_to_assign) {
  uint32_t result_uint = 0;
  if (value_to_assign == ZERO) {
    result_uint = reset_bit(input_uint, position);
  } else {
    result_uint = set_bit(input_uint, position);
  }
  return result_uint;
}

void set_sign(s21_decimal* input_decimal, Sign sign_to_set) {
  input_decimal->bits[3] =
      assign_bit(input_decimal->bits[3], 31U, (Binary)sign_to_set);
}
