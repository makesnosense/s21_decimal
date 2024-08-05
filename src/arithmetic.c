#include "arithmetic.h"

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (1 == 0) {
    printf("%d", value_1.bits[0]);
    printf("%d", value_2.bits[0]);
    printf("%d", result->bits[0]);
  }
  return 0;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  ArithmeticResult result_sub = OK;

  uint32_t minuend_normalized_long_mantissa[6] = {0};
  uint32_t subtrahend_normalized_long_mantissa[6] = {0};
  uint32_t result_long_mantissa[6] = {0};

  int bigger_scale = cast_decimals_to_normalized_mantissas(
      value_1, minuend_normalized_long_mantissa, value_2,
      subtrahend_normalized_long_mantissa);
  int result_sign = PLUS;

  // (a) - (b) = a - b
  if (get_sign(value_1) == PLUS && get_sign(value_2) == PLUS) {
    result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                          subtrahend_normalized_long_mantissa,
                                          result_long_mantissa);
    // (-a) - (b) =  - (a+b)
  } else if (get_sign(value_1) == MINUS && get_sign(value_2) == PLUS) {
    add_long_mantissas(minuend_normalized_long_mantissa,
                       subtrahend_normalized_long_mantissa,
                       result_long_mantissa);
    result_sign = MINUS;
    // (a) - (- b) = a + b
  } else if (get_sign(value_1) == PLUS && get_sign(value_2) == MINUS) {
    add_long_mantissas(minuend_normalized_long_mantissa,
                       subtrahend_normalized_long_mantissa,
                       result_long_mantissa);
    result_sign = PLUS;
    // (-a) - (-b) = b - a
  } else {
    result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                          subtrahend_normalized_long_mantissa,
                                          result_long_mantissa);
  }

  debug_print_mantissa_as_binary(result_long_mantissa, 6);

  uint32_t nn[6] = {0x00000000, 0x00000000, 0x00000000,
                    0x00000000, 0x00000000, 0x00000000};
  // printf("\n\n%ld\n\n",
  //        compare_long_mantissas(result_long_mantissa,
  //                               get_mantissa_with_power_of_ten(30)));

  int digits_count = 1;
  while (compare_long_mantissas(
             nn, get_mantissa_with_power_of_ten(digits_count)) >= 0) {
    digits_count++;
    // printf("\n\n%d %ld", digits_count,
    //        compare_long_mantissas(
    //            nn, get_mantissa_with_power_of_ten(digits_count)));
  }

  printf("digits count %d", digits_count);

  // if (compare_long_mantissas(result_long_mantissa,
  //                            get_mantissa_with_power_of_ten(28)) > 0) {
  //   printf("imhere");
  // }

  printf("\nscale: %d\n", bigger_scale);

  write_in_mantissa_to_decimal(result_long_mantissa, result);

  set_scale(&result->bits[3], bigger_scale);

  set_sign(result, (Sign)result_sign);

  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  ArithmeticResult result_funk = OK;

  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  uint32_t mantissa_value_1[3] = {0};
  uint32_t mantissa_value_2[3] = {0};
  uint32_t mantissa_result[6] = {0};

  get_mantissa_from_decimal(mantissa_value_1, &value_1);
  get_mantissa_from_decimal(mantissa_value_2, &value_2);

  if (mantissa_value_1[0] == 1 && mantissa_value_1[1] == 0 &&
      mantissa_value_1[2] == 0) {
    result->bits[0] = value_2.bits[0];
    result->bits[1] = value_2.bits[1];
    result->bits[2] = value_2.bits[2];
  } else if (mantissa_value_2[0] == 1 && mantissa_value_2[1] == 0 &&
             mantissa_value_2[2] == 0) {
    result->bits[0] = value_1.bits[0];
    result->bits[1] = value_1.bits[1];
    result->bits[2] = value_1.bits[2];
  } else {
    multiply_mantissas(mantissa_value_1, mantissa_value_2, mantissa_result);

    if (mantissa_result[3] != 0) {
      result_funk = TOO_BIG;
    }  // дописать функцию сравнения для доп условий!!!

    // write_in_mantissa_to_decimal(mantissa_result, result);

    result->bits[2] = mantissa_result[4];
    result->bits[1] = mantissa_result[3];
    result->bits[0] = mantissa_result[2];
  }

  int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);

  set_scale(&result->bits[3], scale_result);

  if (get_sign(value_1) > get_sign(value_2) ||
      get_sign(value_1) < get_sign(value_2)) {
    set_sign(result, 1);
  } else if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
    set_sign(result, 0);
  }

  return result_funk;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (1 == 0) {
    printf("%d", value_1.bits[0]);
    printf("%d", value_2.bits[0]);
    printf("%d", result->bits[0]);
  }
  return 0;
}
