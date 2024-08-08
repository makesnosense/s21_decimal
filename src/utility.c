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
    // needs to be before memset to work correctly in case when divident and
    // result pointers are the same
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

int get_scale_difference_from_decimals(s21_decimal decimal_1,
                                       s21_decimal decimal_2) {
  int decimal_1_scale = get_scale(decimal_1.bits[3]);
  int decimal_2_scale = get_scale(decimal_2.bits[3]);
  int result = 0;
  if (decimal_1_scale > decimal_2_scale) {
    result = decimal_1_scale - decimal_2_scale;
  } else if (decimal_1_scale < decimal_2_scale) {
    result = decimal_2_scale - decimal_1_scale;
  }
  return result;
}

int cast_decimals_to_normalized_mantissas(s21_decimal decimal_1,
                                          uint32_t* normalized_mantissa_1,
                                          s21_decimal decimal_2,
                                          uint32_t* normalized_mantissa_2) {
  int bigger_scale = 0;
  int scale_difference =
      get_scale_difference_from_decimals(decimal_1, decimal_2);

  if (scale_difference == 0) {
    mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);
    mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
    bigger_scale = get_scale(decimal_1.bits[3]);
  } else if (get_scale(decimal_1.bits[3]) > get_scale(decimal_2.bits[3])) {
    multiply_mantissas(decimal_2.bits,
                       get_mantissa_with_power_of_ten(scale_difference),
                       normalized_mantissa_2);
    bigger_scale = get_scale(decimal_1.bits[3]);
    mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);

  } else if (get_scale(decimal_1.bits[3]) < get_scale(decimal_2.bits[3])) {
    multiply_mantissas(decimal_1.bits,
                       get_mantissa_with_power_of_ten(scale_difference),
                       normalized_mantissa_1);
    mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
    bigger_scale = get_scale(decimal_2.bits[3]);
  }

  return bigger_scale;
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

int count_long_mantissa_digits(uint32_t* input_mantissa) {
  int digits_count = 1;
  while (compare_long_mantissas(input_mantissa, get_mantissa_with_power_of_ten(
                                                    digits_count)) >= 0) {
    digits_count++;
  }
  return digits_count;
}

uint32_t* get_max_mantissa() {
  static uint32_t max_mantissa[6] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                                     0x0,        0x0,        0x0};
  return max_mantissa;
}

bool downsize_mantissa(uint32_t* long_mantissa, int* scale,
                       uint32_t* mantissa) {
  bool is_overflow = false;
  uint32_t* max_mantissa = get_max_mantissa();

  int digits_to_remove = count_long_mantissa_digits(long_mantissa) - 29;
  int downsized_scale = *scale;
  if (digits_to_remove >= 0) {
    downsized_scale -= digits_to_remove;
    if (downsized_scale < 0) {
      is_overflow = true;
    } else {
      if (digits_to_remove > 0) {
        remove_digits_rounding_to_even(long_mantissa, digits_to_remove);
      }
      // if 29 decimal digit number in mantissa doesn't fit in 96
      // bits remove one more decimal digit
      if (compare_long_mantissas(long_mantissa, max_mantissa) > 0) {
        remove_digits_rounding_to_even(long_mantissa, 1);
        downsized_scale -= 1;
      }
      if (downsized_scale < 0) {
        is_overflow = true;
      }
    }
  }
  if (!is_overflow) {
    copy_mantissa(mantissa, long_mantissa);
    *scale = downsized_scale;
  }
  return is_overflow;
}

void remove_digits_rounding_to_even(uint32_t* long_mantissa,
                                    int digits_to_remove) {
  uint32_t removed_digits[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  divide_long_mantissas(long_mantissa,
                        get_mantissa_with_power_of_ten(digits_to_remove),
                        long_mantissa, removed_digits);

  uint32_t first_removed_digit[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  uint32_t rest_removed_digits[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  divide_long_mantissas(removed_digits,
                        get_mantissa_with_power_of_ten(digits_to_remove - 1),
                        first_removed_digit, rest_removed_digits);

  uint32_t* one = get_mantissa_with_power_of_ten(0);
  if (first_removed_digit[0] == 5) {
    if (zero_check_long_mantissa(rest_removed_digits) == false) {
      add_long_mantissas(long_mantissa, one, long_mantissa);
    } else {
      if (long_mantissa[0] & 1) {
        add_long_mantissas(long_mantissa, one, long_mantissa);
      }
    }
  } else if (first_removed_digit[0] > 5) {
    add_long_mantissas(long_mantissa, one, long_mantissa);
  }
}

uint32_t* get_mantissa_with_power_of_ten(int power) {
  uint32_t* result = NULL;
  if (power >= 0 && power <= 28) {
    result = _get_mantissa_with_power_of_ten_powers_0_to_28(power);
  } else if (power > 28 && power <= 57) {
    result = _get_mantissa_with_power_of_ten_powers_29_to_57(power - 29);
  } else {
    result = NULL;
  }

  return result;
}

uint32_t* _get_mantissa_with_power_of_ten_powers_0_to_28(int power) {
  // first one is 10^0, last one is 10^28
  static uint32_t powers_of_10_first_part[29][6] = {
      {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x000003E8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x00002710, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x000186A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x000F4240, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x00989680, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x05F5E100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x3B9ACA00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x540BE400, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x4876E800, 0x00000017, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0xD4A51000, 0x000000E8, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x4E72A000, 0x00000918, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x107A4000, 0x00005AF3, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0xA4C68000, 0x00038D7E, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x6FC10000, 0x002386F2, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x5D8A0000, 0x01634578, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0xA7640000, 0x0DE0B6B3, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x89E80000, 0x8AC72304, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
      {0x63100000, 0x6BC75E2D, 0x00000005, 0x00000000, 0x00000000, 0x00000000},
      {0xDEA00000, 0x35C9ADC5, 0x00000036, 0x00000000, 0x00000000, 0x00000000},
      {0xB2400000, 0x19E0C9BA, 0x0000021E, 0x00000000, 0x00000000, 0x00000000},
      {0xF6800000, 0x02C7E14A, 0x0000152D, 0x00000000, 0x00000000, 0x00000000},
      {0xA1000000, 0x1BCECCED, 0x0000D3C2, 0x00000000, 0x00000000, 0x00000000},
      {0x4A000000, 0x16140148, 0x00084595, 0x00000000, 0x00000000, 0x00000000},
      {0xE4000000, 0xDCC80CD2, 0x0052B7D2, 0x00000000, 0x00000000, 0x00000000},
      {0xE8000000, 0x9FD0803C, 0x033B2E3C, 0x00000000, 0x00000000, 0x00000000},
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x00000000, 0x00000000, 0x00000000}};
  return powers_of_10_first_part[power];
}

uint32_t* _get_mantissa_with_power_of_ten_powers_29_to_57(int power) {
  // first one is 10^29, last one is 10^57
  static uint32_t powers_of_10_second_part[29][6] = {
      {0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x00000001, 0x00000000, 0x00000000},
      {0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0x0000000C, 0x00000000, 0x00000000},
      {0x80000000, 0xC0914B26, 0x37BE2022, 0x0000007E, 0x00000000, 0x00000000},
      {0x00000000, 0x85ACEF81, 0x2D6D415B, 0x000004EE, 0x00000000, 0x00000000},
      {0x00000000, 0x38C15B0A, 0xC6448D93, 0x0000314D, 0x00000000, 0x00000000},
      {0x00000000, 0x378D8E64, 0xBEAD87C0, 0x0001ED09, 0x00000000, 0x00000000},
      {0x00000000, 0x2B878FE8, 0x72C74D82, 0x00134261, 0x00000000, 0x00000000},
      {0x00000000, 0xB34B9F10, 0x7BC90715, 0x00C097CE, 0x00000000, 0x00000000},
      {0x00000000, 0x00F436A0, 0xD5DA46D9, 0x0785EE10, 0x00000000, 0x00000000},
      {0x00000000, 0x098A2240, 0x5A86C47A, 0x4B3B4CA8, 0x00000000, 0x00000000},
      {0x00000000, 0x5F655680, 0x8943ACC4, 0xF050FE93, 0x00000002, 0x00000000},
      {0x00000000, 0xB9F56100, 0x5CA4BFAB, 0x6329F1C3, 0x0000001D, 0x00000000},
      {0x00000000, 0x4395CA00, 0x9E6F7CB5, 0xDFA371A1, 0x00000125, 0x00000000},
      {0x00000000, 0xA3D9E400, 0x305ADF14, 0xBC627050, 0x00000B7A, 0x00000000},
      {0x00000000, 0x6682E800, 0xE38CB6CE, 0x5BD86321, 0x000072CB, 0x00000000},
      {0x00000000, 0x011D1000, 0xE37F2410, 0x9673DF52, 0x00047BF1, 0x00000000},
      {0x00000000, 0x0B22A000, 0xE2F768A0, 0xE086B93C, 0x002CD76F, 0x00000000},
      {0x00000000, 0x6F5A4000, 0xDDAA1640, 0xC5433C60, 0x01C06A5E, 0x00000000},
      {0x00000000, 0x59868000, 0xA8A4DE84, 0xB4A05BC8, 0x118427B3, 0x00000000},
      {0x00000000, 0x7F410000, 0x9670B12B, 0x0E4395D6, 0xAF298D05, 0x00000000},
      {0x00000000, 0xF88A0000, 0xE066EBB2, 0x8EA3DA61, 0xD79F8232, 0x00000006},
      {0x00000000, 0xB5640000, 0xC40534FD, 0x926687D2, 0x6C3B15F9, 0x00000044},
      {0x00000000, 0x15E80000, 0xA83411E9, 0xB8014E3B, 0x3A4EDBBF, 0x000002AC},
      {0x00000000, 0xDB100000, 0x9208B31A, 0x300D0E54, 0x4714957D, 0x00001ABA},
      {0x00000000, 0x8EA00000, 0xB456FF0C, 0xE0828F4D, 0xC6CDD6E3, 0x00010B46},
      {0x00000000, 0x92400000, 0x0B65F67D, 0xC5199909, 0xC40A64E6, 0x000A70C3},
      {0x00000000, 0xB6800000, 0x71FBA0E7, 0xB2FFFA5A, 0xA867F103, 0x006867A5},
      {0x00000000, 0x21000000, 0x73D4490D, 0xFDFFC788, 0x940F6A24, 0x04140C78},
      {0x00000000, 0x4A000000, 0x864ADA83, 0xEBFDCB54, 0xC89A2571, 0x28C87CB5}};

  return powers_of_10_second_part[power];
}
