#include "helper_funcs.h"

int get_bit(uint32_t input_uint, size_t position) {
  return (input_uint >> position) & 1;
}

void set_bit(uint32_t* input_uint, size_t position) {
  *input_uint = *input_uint | (1 << position);
}

void reset_bit(uint32_t* input_uint, size_t position) {
  *input_uint = *input_uint & ~(1 << position);
}

void assign_bit(uint32_t* input_uint, size_t position, Binary value_to_assign) {
  if (value_to_assign == ZERO) {
    reset_bit(input_uint, position);
  } else {
    set_bit(input_uint, position);
  }
}

void set_sign(s21_decimal* input_decimal, Sign sign_to_set) {
  assign_bit(&input_decimal->bits[3], SIGN_BIT_POSITION, (Binary)sign_to_set);
}
