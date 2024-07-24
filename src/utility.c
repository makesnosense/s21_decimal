#include "utility.h"

int get_bit(uint32_t input_uint, int position) {
  return (input_uint >> position) & 1;
}

void set_bit(uint32_t* input_uint, int position) {
  *input_uint = *input_uint | (1 << position);
}

void reset_bit(uint32_t* input_uint, int position) {
  *input_uint = *input_uint & ~(1 << position);
}

void assign_bit(uint32_t* input_uint, int position, Binary value_to_assign) {
  if (value_to_assign == ZERO) {
    reset_bit(input_uint, position);
  } else {
    set_bit(input_uint, position);
  }
}

void set_sign(s21_decimal* input_decimal, Sign sign_to_set) {
  assign_bit(&input_decimal->bits[3], SIGN_BIT_POSITION, (Binary)sign_to_set);
}

int get_sign(s21_decimal input_decimal) {
  return get_bit(input_decimal.bits[3], SIGN_BIT_POSITION);
}

void reset_decimal(s21_decimal* input_decimal) {
  for (int i = 0; i < 4; i++) {
    input_decimal->bits[i] = 0U;
  }
}

void* s21_memset(void* str, int c, int n) {
  unsigned char* pointer = str;
  while (n > 0) {
    n--;
    *pointer++ = (unsigned char)c;
  }
  return str;
}

int determine_bit_part_and_position(int position_in_mantissa,
                                    int* bits_array_index) {
  *bits_array_index = position_in_mantissa / (sizeof(uint32_t) * BYTE_SIZE);

  int position_in_part = position_in_mantissa % (sizeof(uint32_t) * BYTE_SIZE);
  return position_in_part;
}

int get_mantissa_bit(uint32_t* mantissa_parts, int position_in_mantissa) {
  int part_index;
  int position_in_part =
      determine_bit_part_and_position(position_in_mantissa, &part_index);
  int bit_value = get_bit(mantissa_parts[part_index], position_in_part);
  return bit_value;
}

void assign_mantissa_bit(uint32_t* mantissa_parts,
                         unsigned position_in_mantissa, Binary value) {
  int part_index;
  int position_in_part =
      determine_bit_part_and_position(position_in_mantissa, &part_index);
  assign_bit(&mantissa_parts[part_index], position_in_part, value);
}

int mantissa_addition(uint32_t* term_1, uint32_t* term_2, uint32_t* result) {
  int overflow_error = 0;
  int carryover = 0;
  int bits_sum;
  for (int i = 0; i < (sizeof(uint32_t) * BYTE_SIZE * 3); i++) {
    bits_sum = carryover;
    bits_sum += get_mantissa_bit(term_1, i);
    bits_sum += get_mantissa_bit(term_2, i);
    if (bits_sum > 1) {
      bits_sum -= 2;
      carryover = 1;
    } else {
      carryover = 0;
    }
    assign_mantissa_bit(result, i, bits_sum);
  }
  if (carryover > 0) {
    overflow_error = 1;
  }
  return overflow_error;
}

// void matissa_multiplication(uint32_t *input, unsigned factor) {}

int get_power(uint32_t service_part) {
  uint32_t result = 0;
  for (int i = 0; i < 9; i++) {
    if (get_bit(service_part, END_POWER_POSITION - i)) {
      set_bit(&result, 8 - i);
    } else {
      reset_bit(&result, 8 - i);
    }
  }
  return result;
}

void set_power(uint32_t* service_part, int power_to_set) {
  for (int i = 0; i < 9; i++) {
    if (get_bit(power_to_set, 8 - i)) {
      set_bit(service_part, END_POWER_POSITION - i);
    } else {
      reset_bit(service_part, END_POWER_POSITION - i);
    }
  }
}

void print_large_number(uint32_t num[], int size) {
  for (int i = size - 1; i >= 0; i--) {
    printf("%08X ", num[i]);
  }
  printf("\n");
}

void write_in_mantissa_to_decimal(uint32_t* mantissa,
                                  s21_decimal* destination_decimal) {
  destination_decimal->bits[0] = mantissa[0];
  destination_decimal->bits[1] = mantissa[1];
  destination_decimal->bits[2] = mantissa[2];
}

void mantissa3_to_mantissa6(uint32_t* mantissa3, uint32_t* mantissa6) {
  mantissa6[0] = mantissa3[0];
  mantissa6[1] = mantissa3[1];
  mantissa6[2] = mantissa3[2];
}

uint32_t* get_mantissa_with_power_of_ten(int power) {
  static uint32_t powers_of_10[29][3] = {
      {0x1, 0x0, 0x0},                      // 10^0
      {0xA, 0x0, 0x0},                      // 10^1
      {0x64, 0x0, 0x0},                     // 10^2
      {0x3E8, 0x0, 0x0},                    // 10^3
      {0x2710, 0x0, 0x0},                   // 10^4
      {0x186A0, 0x0, 0x0},                  // 10^5
      {0xF4240, 0x0, 0x0},                  // 10^6
      {0x989680, 0x0, 0x0},                 // 10^7
      {0x5F5E100, 0x0, 0x0},                // 10^8
      {0x3B9ACA00, 0x0, 0x0},               // 10^9
      {0x540BE400, 0x2, 0x0},               // 10^10
      {0x4876E800, 0x17, 0x0},              // 10^11
      {0xD4A51000, 0xE8, 0x0},              // 10^12
      {0x4E72A000, 0x918, 0x0},             // 10^13
      {0x107A4000, 0x5AF3, 0x0},            // 10^14
      {0xA4C68000, 0x38D7E, 0x0},           // 10^15
      {0x6FC10000, 0x2386F2, 0x0},          // 10^16
      {0x5D8A0000, 0x1634578, 0x0},         // 10^17
      {0xA7640000, 0xDE0B6B3, 0x0},         // 10^18
      {0x89E80000, 0x8AC72304, 0x0},        // 10^19
      {0x63100000, 0x6BC75E2D, 0x5},        // 10^20
      {0xDEA00000, 0x35C9ADC5, 0x36},       // 10^21
      {0xB2400000, 0x19E0C9BA, 0x21E},      // 10^22
      {0xF6800000, 0x2C7E14A, 0x152D},      // 10^23
      {0xA1000000, 0x1BCECCED, 0xD3C2},     // 10^24
      {0x4A000000, 0x16140148, 0x84595},    // 10^25
      {0xE4000000, 0xDCC80CD2, 0x52B7D2},   // 10^26
      {0xE8000000, 0x9FD0803C, 0x33B2E3C},  // 10^27
      {0x10000000, 0x3E250261, 0x204FCE5E}  // 10^28
  };

  if (power >= 0 && power <= 28) {
    return powers_of_10[power];
  }
  return NULL;  // Возвращаем NULL для недопустимых значений power
}

void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result) {
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

// void write_in_mantissa_to_decimal(uint32_t* mantissa, s21_decimal* result) {
//   int position = 0;
//   int mantissa_part = 0;
//   for (int i = 0; i < 96; i++) {
//     if (position > 31) {
//       position = 0;
//       mantissa_part++;
//     }
//     if (get_bit(mantissa[mantissa_part], position)) {
//       set_bit(&result->bits[mantissa_part], position);
//       position++;
//     } else {
//       reset_bit(&result->bits[mantissa_part], position);
//       position++;
//     }
//   }
// }