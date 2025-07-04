#ifndef SRC_HELPER_FUNCS_H_
#define SRC_HELPER_FUNCS_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "s21_decimal.h"

#define SIGN_BIT_POSITION 31U
#define BYTE_SIZE 8
#define PART_SIZE 32
#define MANTISSA_PARTS 3
#define LONG_MANTISSA_PARTS 6

#define BEGIN_SCALE_POSITION 16
#define END_SCALE_POSITION 23

#define MAX_SCALE 28

#define DECIMAL_ZERO ((s21_decimal){0})

// as per
// https://en.wikipedia.org/wiki/Decimal128_floating-point_format#Binary_integer_significand_field
#define DECIMAL_POSITIVE_INFINITY \
  ((s21_decimal){{0x0, 0x0, 0x0, 0b01111000000000000000000000000000}})
#define DECIMAL_NEGATIVE_INFINITY \
  ((s21_decimal){{0x0, 0x0, 0x0, 0b11111000000000000000000000000000}})
#define DECIMAL_POSITIVE_NAN \
  ((s21_decimal){{0x0, 0x0, 0x0, 0b01111100000000000000000000000000}})
#define DECIMAL_NEGATIVE_NAN \
  ((s21_decimal){{0x0, 0x0, 0x0, 0b11111100000000000000000000000000}})

#define SERVICE_PART_STRUCTURE_MASK 0b01111111111000001111111111111111

typedef enum Sign_t {
  PLUS = 0,
  MINUS = 1,
} Sign;
typedef enum Binary_t {
  ZERO = 0,
  ONE = 1,
} Binary;

int get_bit(uint32_t input_uint, int position);
void set_bit(uint32_t* input_uint, int position);
void reset_bit(uint32_t* input_uint, int position);
void assign_bit(uint32_t* input_uint, int position, Binary value_to_assign);
void set_sign(s21_decimal* input_decimal, Sign sign_to_set);
int get_sign(s21_decimal input_decimal);
void reset_decimal(s21_decimal* input_decimal);
int determine_bit_part_and_position(int mantissa_position, int* part_index);
int get_mantissa_bit(uint32_t* mantissa, int position);
void assign_mantissa_bit(uint32_t* mantissa, unsigned position, Binary value);

int get_scale(uint32_t service_part);
void set_scale(uint32_t* service_part, int scale);
void* s21_memset(void* str, int c, int n);

uint32_t* get_max_mantissa();

void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result);
void multiply_long_mantissas(uint32_t* factor_1, uint32_t* factor_2,
                             uint32_t* result);
void write_in_mantissa_to_decimal(uint32_t* mantissa,
                                  s21_decimal* destination_decimal);
void get_mantissa_from_decimal(uint32_t* mantissa, s21_decimal source_decimal);
void mantissa3_to_mantissa6(uint32_t* mantissa3, uint32_t* mantissa6);

bool is_zero_decimal(s21_decimal input_decimal);
bool is_one_decimal(s21_decimal input_decimal);

int cast_decimals_to_normalized_mantissas(s21_decimal decimal_1,
                                          uint32_t* normalized_mantissa_1,
                                          s21_decimal decimal_2,
                                          uint32_t* normalized_mantissa_2);
int get_scale_difference_from_decimals(s21_decimal decimal_1,
                                       s21_decimal decimal_2);

int count_long_mantissa_digits(uint32_t* input_mantissa);
int downsize_mantissa(uint32_t* long_mantissa, int* scale, uint32_t* mantissa,
                      bool* overflow);
void remove_digits_rounding_to_even(uint32_t* long_mantissa,
                                    int digits_to_remove, uint32_t* result);

bool decimal_service_part_structure_is_correct(s21_decimal input_decimal);
bool decimal_scale_is_within_bounds(s21_decimal input_decimal);
bool decimal_service_part_is_correct(s21_decimal input_decimal);
int service_part_structure_is_correct(uint32_t service_part);

uint32_t* get_mantissa_with_power_of_ten(int power);
uint32_t* _get_mantissa_with_power_of_ten_powers_0_to_28(int power);
uint32_t* _get_mantissa_with_power_of_ten_powers_29_to_57(int power);

int _add_mantissas(uint32_t* term_1, uint32_t* term_2, uint32_t* result,
                   int size);
void _bitflip_mantissa(uint32_t* number, uint32_t* result, int size);
bool _mantissa_is_zero(uint32_t* mantissa, int size);
void _copy_mantissa(uint32_t* dest, uint32_t* src, int size);
int _subtract_mantissas(uint32_t* minuend, uint32_t* subtrahend,
                        uint32_t* result, int size);
void _shift_mantissa_left(uint32_t* mantissa, unsigned shift, int size);
int _find_highest_mantissa_bit(uint32_t* mantissa, int size);
int64_t _compare_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                           int size);
int _divide_mantissas(uint32_t* dividend, uint32_t* divisor, uint32_t* result,
                      uint32_t* remainder, int size);

#define add_mantissas(term_1, term_2, result) \
  _add_mantissas(term_1, term_2, result, MANTISSA_PARTS)
#define add_long_mantissas(term_1, term_2, result) \
  _add_mantissas(term_1, term_2, result, LONG_MANTISSA_PARTS)

#define bitflip_mantissa(mantissa, result) \
  _bitflip_mantissa(mantissa, result, MANTISSA_PARTS)
#define bitflip_long_mantissa(mantissa, result) \
  _bitflip_mantissa(mantissa, result, LONG_MANTISSA_PARTS)

#define mantissa_is_zero(mantissa) _mantissa_is_zero(mantissa, MANTISSA_PARTS)
#define long_mantissa_is_zero(mantissa) \
  _mantissa_is_zero(mantissa, LONG_MANTISSA_PARTS)

#define copy_mantissa(dest, src) _copy_mantissa(dest, src, MANTISSA_PARTS)
#define copy_long_mantissa(dest, src) \
  _copy_mantissa(dest, src, LONG_MANTISSA_PARTS)

#define subtract_mantissas(minuend, subtrahend, result) \
  _subtract_mantissas(minuend, subtrahend, result, MANTISSA_PARTS)
#define subtract_long_mantissas(minuend, subtrahend, result) \
  _subtract_mantissas(minuend, subtrahend, result, LONG_MANTISSA_PARTS)

#define shift_mantissa_left(mantissa, shift) \
  _shift_mantissa_left(mantissa, shift, MANTISSA_PARTS)
#define shift_long_mantissa_left(mantissa, shift) \
  _shift_mantissa_left(mantissa, shift, LONG_MANTISSA_PARTS)

#define find_highest_mantissa_bit(mantissa) \
  _find_highest_mantissa_bit(mantissa, MANTISSA_PARTS)
#define find_highest_long_mantissa_bit(mantissa) \
  _find_highest_mantissa_bit(mantissa, LONG_MANTISSA_PARTS)

#define compare_mantissas(mantissa_1, mantissa_2) \
  _compare_mantissas(mantissa_1, mantissa_2, MANTISSA_PARTS)

#define compare_long_mantissas(mantissa_1, mantissa_2) \
  _compare_mantissas(mantissa_1, mantissa_2, LONG_MANTISSA_PARTS)

#define divide_mantissas(dividend, divisor, result, remainder) \
  _divide_mantissas(dividend, divisor, result, remainder, MANTISSA_PARTS)
#define divide_long_mantissas(dividend, divisor, result, remainder) \
  _divide_mantissas(dividend, divisor, result, remainder, LONG_MANTISSA_PARTS)

#endif  // SRC_HELPER_FUNCS_H_