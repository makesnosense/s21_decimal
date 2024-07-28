#ifndef SRC_HELPER_FUNCS_H_
#define SRC_HELPER_FUNCS_H_

#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

#define SIGN_BIT_POSITION 31U
#define BYTE_SIZE 8

#define BEGIN_SCALE_POSITION 16
#define END_SCALE_POSITION 23

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
int mantissa_addition(uint32_t* term_1, uint32_t* term_2, uint32_t* result);
int get_scale(uint32_t service_part);
void set_scale(uint32_t* service_part, int scale);
void* s21_memset(void* str, int c, int n);
void multiply_mantissas(uint32_t* mantissa_1, uint32_t* mantissa_2,
                        uint32_t* result);

void write_in_mantissa_to_decimal(uint32_t* mantissa,
                                  s21_decimal* destination_decimal);
void write_in_decimal_to_mantissa(uint32_t* mantissa,
                                  s21_decimal* destination_decimal);
void mantissa3_to_mantissa6(uint32_t* mantissa3, uint32_t* mantissa6);
uint32_t* get_mantissa_with_power_of_ten(int power);
bool is_zero_decimal(s21_decimal input_decimal);

#endif  // SRC_HELPER_FUNCS_H_