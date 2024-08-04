#include "utility.h"

#include "debug_funcs.h"

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
  *bits_array_index = position_in_mantissa / PART_SIZE;

  int position_in_part = position_in_mantissa % PART_SIZE;
  return position_in_part;
}

int get_mantissa_bit(uint32_t* mantissa_parts, int position_in_mantissa) {
  int part_index;
  int position_in_part =
      determine_bit_part_and_position(position_in_mantissa, &part_index);
  int bit_value = get_bit(mantissa_parts[part_index], position_in_part);
  return bit_value;
}

void assign_mantissa_bit(uint32_t* mantissa, unsigned position, Binary value) {
  int part_index;
  int part_position = determine_bit_part_and_position(position, &part_index);
  assign_bit(&mantissa[part_index], part_position, value);
}

int _add_mantissas(uint32_t* term_1, uint32_t* term_2, uint32_t* result,
                   int size) {
  int overflow = 0;
  uint32_t carry = 0;
  uint64_t part_sum;
  for (int i = 0; i < size; i++) {
    part_sum = (uint64_t)term_1[i] + term_2[i] + carry;
    result[i] = (uint32_t)part_sum;
    carry = part_sum >> 32;
  }
  if (carry > 0) {
    overflow = 1;
  }
  return overflow;
}

void _bitflip_mantissa(uint32_t* mantissa, uint32_t* result, int size) {
  for (int i = 0; i < size; i++) {
    result[i] = ~mantissa[i];
  }
}

bool _zero_check_mantissa(uint32_t* mantissa, int size) {
  bool is_zero = true;
  for (int i = 0; i < size && is_zero == true; i++) {
    if (mantissa[i] != 0) {
      is_zero = false;
    }
  }
  return is_zero;
}

void _copy_mantissa(uint32_t* dest, uint32_t* src, int size) {
  for (int i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}

int _subtract_mantissas(uint32_t* minuend, uint32_t* subtrahend,
                        uint32_t* result, int size) {
  int is_negative = 0;
  if (_zero_check_mantissa(subtrahend, size)) {
    // memmove instead of memcpy to handle same minuend and result case
    _copy_mantissa(result, minuend, size);
    // memmove(result, minuend, (PART_SIZE * size) / BYTE_SIZE);
  } else {
    uint32_t compliment[6] = {0, 0, 0, 0, 0, 0};
    uint32_t one[6] = {1, 0, 0, 0, 0, 0};
    _bitflip_mantissa(subtrahend, compliment, size);
    _add_mantissas(compliment, one, compliment, size);
    is_negative = !_add_mantissas(minuend, compliment, result, size);
    if (is_negative) {
      _bitflip_mantissa(result, result, size);
      _add_mantissas(result, one, result, size);
    }
  }
  return is_negative;
}

void _shift_mantissa_left(uint32_t* mantissa, unsigned shift, int size) {
  int bit_value;
  int mantissa_bits = PART_SIZE * size;
  int original_position = mantissa_bits - (shift + 1);
  int shifted_position = mantissa_bits - 1;
  while (original_position >= 0) {
    if (shifted_position < mantissa_bits) {
      bit_value = get_mantissa_bit(mantissa, original_position);
      assign_mantissa_bit(mantissa, shifted_position, bit_value);
      original_position--;
      shifted_position--;
    }
  }
  while (shifted_position >= 0) {
    assign_mantissa_bit(mantissa, shifted_position, ZERO);
    shifted_position--;
  }
}

int _find_highest_mantissa_bit(uint32_t* mantissa, int size) {
  int current_bit = 0;
  int part_index = size - 1;
  int part_position;
  while (part_index >= 0) {
    part_position = PART_SIZE - 1;
    while (part_position >= 0) {
      current_bit = get_bit(mantissa[part_index], part_position);
      if (current_bit == 1) {
        break;
      }
      part_position--;
    }
    if (current_bit == 1) {
      break;
    }
    part_index--;
  }
  int highest_bit;
  if (part_index < 0) {
    highest_bit = -1;
  } else {
    highest_bit = part_index * PART_SIZE + part_position;
  }
  return highest_bit;
}

int64_t _compare_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                           int size) {
  int64_t diff = 0;
  int i = size - 1;
  while (diff == 0 && i >= 0) {
    // type conversion avoids overflow errors with large negative difference
    diff = (int64_t)mantissa_1[i] - mantissa_2[i];
    i--;
  }
  return diff;
}

// TODO: allow passing NULL pointer as remainder
// TODO: refactor without copying (PART_SIZE * size) / BYTE_SIZE)
int _divide_mantissas(uint32_t* divident, uint32_t* divisor, uint32_t* result,
                      uint32_t* remainder, int size) {
  int division_by_zero = 0;
  if (_zero_check_mantissa(divisor, size)) {
    division_by_zero = 1;
  } else {
    int divident_bits = _find_highest_mantissa_bit(divident, size);
    int divisor_bits = _find_highest_mantissa_bit(divisor, size);
    memcpy(remainder, divident, (PART_SIZE * size) / BYTE_SIZE);
    memset(result, 0, (PART_SIZE * size) / BYTE_SIZE);
    int shift = divident_bits - divisor_bits;
    uint32_t shifted_divisor[6] = {0, 0, 0, 0, 0, 0};
    while (shift >= 0) {
      memcpy(shifted_divisor, divisor, (PART_SIZE * size) / BYTE_SIZE);
      _shift_mantissa_left(shifted_divisor, shift, size);
      if (_compare_mantissas(remainder, shifted_divisor, size) >= 0) {
        assign_mantissa_bit(result, shift, ONE);
        _subtract_mantissas(remainder, shifted_divisor, remainder, size);
      }
      shift--;
    }
  }
  return division_by_zero;
}

int get_scale(uint32_t service_part) {
  uint32_t result = 0;
  for (int i = 0; i < 8; i++) {
    if (get_bit(service_part, END_SCALE_POSITION - i)) {
      set_bit(&result, 7 - i);
    } else {
      reset_bit(&result, 7 - i);
    }
  }
  return result;
}

void set_scale(uint32_t* service_part, int scale_to_set) {
  for (int i = 0; i < 8; i++) {
    if (get_bit(scale_to_set, 7 - i)) {
      set_bit(service_part, END_SCALE_POSITION - i);
    } else {
      reset_bit(service_part, END_SCALE_POSITION - i);
    }
  }
}

void write_in_mantissa_to_decimal(uint32_t* mantissa,
                                  s21_decimal* destination_decimal) {
  destination_decimal->bits[0] = mantissa[0];
  destination_decimal->bits[1] = mantissa[1];
  destination_decimal->bits[2] = mantissa[2];
}

void get_mantissa_from_decimal(uint32_t* mantissa,
                               s21_decimal* source_decimal) {
  mantissa[0] = source_decimal->bits[0];
  mantissa[1] = source_decimal->bits[1];
  mantissa[2] = source_decimal->bits[2];
}

void mantissa3_to_mantissa6(uint32_t* mantissa3, uint32_t* mantissa6) {
  mantissa6[0] = mantissa3[0];
  mantissa6[1] = mantissa3[1];
  mantissa6[2] = mantissa3[2];
}

void shift_decimal_right(s21_decimal* d) {
  uint64_t carry = 0;
  for (int i = 2; i >= 0; i--) {
    uint64_t temp = ((uint64_t)d->bits[i] >> 1) | (carry << 31);
    carry = d->bits[i] & 1;
    d->bits[i] = (int)temp;
  }
}

void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result) {
  s21_memset(result, 0, sizeof(uint32_t) * 3);

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

bool is_zero_decimal(s21_decimal input_decimal) {
  bool is_zero = true;
  for (int i = 0; i < 3 && is_zero == true; i++) {
    if (input_decimal.bits[i] != 0) {
      is_zero = false;
    }
  }
  return is_zero;
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

  return (power >= 0 && power <= 28) ? powers_of_10[power] : NULL;
}

// void write_in_mantissa_to_decimal(uint32_t* mantissa, s21_decimal* result)
// {
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