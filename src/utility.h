#ifndef SRC_HELPER_FUNCS_H_
#define SRC_HELPER_FUNCS_H_

#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

#define SIGN_BIT_POSITION 31U
#define BYTE_SIZE 8

#define BEGIN_POWER 16
#define END_POWER 23

typedef enum Sign_t {
  PLUS = 0,
  MINUS = 1,
} Sign;
typedef enum Binary_t {
  ZERO = 0,
  ONE = 1,
} Binary;

int get_bit(uint32_t input_uint, int position);
void set_bit(uint32_t *input_uint, int position);
void reset_bit(uint32_t *input_uint, int position);
void assign_bit(uint32_t *input_uint, int position, Binary value_to_assign);
void set_sign(s21_decimal *input_decimal, Sign sign_to_set);
void reset_decimal(s21_decimal *input_decimal);
int determine_bit_part_and_position(int mantissa_position, int *part_index);
int get_mantissa_bit(uint32_t *mantissa, int position);
void assign_mantissa_bit(uint32_t *mantissa, unsigned position, Binary value);
int mantissa_addition(uint32_t *term_1, uint32_t *term_2, uint32_t *result);
int get_power(uint32_t options);
void set_power(uint32_t *options, int power);

#endif  // SRC_HELPER_FUNCS_H_