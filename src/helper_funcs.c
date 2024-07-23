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

void reset_decimal(s21_decimal* input_decimal) {
  for (size_t i = 0; i < 4; i++) {
    input_decimal->bits[i] = 0U;
  }
}

int calc_mantissa_bit_position(int mantissa_position, int* part_index) {
  *part_index = mantissa_position / (sizeof(uint32_t) * BYTE_SIZE);
  int part_position = mantissa_position % (sizeof(uint32_t) * BYTE_SIZE);
  return part_position;
}

int get_matissa_bit(uint32_t* mantissa, int position) {
  int part_index;
  int part_position = calc_mantissa_bit_position(position, &part_index);
  int bit_value = get_bit(mantissa[part_index], part_position);
  return bit_value;
}

void assign_matissa_bit(uint32_t* mantissa, unsigned position, Binary value) {
  int part_index;
  int part_position = calc_mantissa_bit_position(position, &part_index);
  assign_bit(&mantissa[part_index], part_position, value);
}

int mantissa_addition(uint32_t* term_1, uint32_t* term_2, uint32_t* result) {
  int overflow_error = 0;
  int carryover = 0;
  int bits_sum;
  for (int i = 0; i < (sizeof(uint32_t) * BYTE_SIZE * 3); i++) {
    bits_sum = carryover;
    bits_sum += get_matissa_bit(term_1, i);
    bits_sum += get_matissa_bit(term_2, i);
    if (bits_sum > 1) {
      bits_sum -= 2;
      carryover = 1;
    } else {
      carryover = 0;
    }
    assign_matissa_bit(result, i, bits_sum);
  }
  if (carryover > 0) {
    overflow_error = 1;
  }
  return overflow_error;
}

// void matissa_multiplication(uint32_t *input, unsigned factor) {}