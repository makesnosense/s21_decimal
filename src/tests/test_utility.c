#include "../arithmetic.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(mantissa_addition_test) {
  // 4 573 498 578 943 759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b100000011111110010010, 0b0};
  // 3 648 576 347 873 449 873
  uint32_t term_2[3] = {0b01111110111000111001011110010001,
                        0b110010101000100101100011011011, 0b0};
  uint32_t sum[3] = {0b0, 0b0, 0b0};
  // 3 653 149 846 452 393 632
  uint32_t expected[3] = {0b00011101000100010101011010100000,
                          0b110010101100101001100001101110, 0b0};
  int overflow = mantissa_addition(term_1, term_2, sum);

  ck_assert_mem_eq(sum, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(overflow, 0);
}
END_TEST
// 11 0010 1011 0010 1001 1000 0110 1110
// 0001 1101 0001 0001 0101 0110 1010 0000

START_TEST(mantissa_addition_to_self_test) {
  // 4 573 498 578 943 759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b100000011111110010010, 0b0};
  uint32_t one[3] = {1, 0, 0};
  mantissa_addition(term_1, one, term_1);
}
END_TEST

START_TEST(mantissa_bitflip_test) {
  uint32_t number_1[3] = {0b00000000000000000000000000000000,
                          0b11111111111111111111111111111111,
                          0b00000000000000000000000000000000};
  uint32_t number_2[3] = {0b11111111111111111111111111111111,
                          0b00000000000000000000000000000000,
                          0b11111111111111111111111111111111};
  uint32_t result_1[3] = {0, 0, 0};
  uint32_t result_2[3] = {0, 0, 0};
  mantissa_bitflip(number_1, result_1);
  mantissa_bitflip(number_2, result_2);
  ck_assert_mem_eq(result_1, number_2, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(result_2, number_1, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(mantissa_copy_test) {
  uint32_t src[3] = {0b00011101000100010101011010100000,
                     0b110010101100101001100001101110, 0b0};
  uint32_t result[3] = {0, 0, 0};
  copy_mantissa(src, result);
  ck_assert_mem_eq(result, src, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(mantissa_zero_subtraction_test) {
  uint32_t minuend[3] = {0b00011101000100010101011010100000,
                         0b110010101100101001100001101110, 0b0};
  uint32_t subtrahend[3] = {0, 0, 0};
  uint32_t result[3] = {0, 0, 0};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, minuend, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_1) {
  uint32_t minuend[3] = {3, 0, 0};
  uint32_t subtrahend[3] = {10, 0, 0};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {7, 0, 0};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 1);
}
END_TEST

START_TEST(mantissa_subtraction_test_2) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU};
  uint32_t subtrahend[3] = {0xFFFFFFFEU, 0xFFFFFFFFU, 0x7FFFFFFFU};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0x1U, 0x0U, 0x80000000U};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_3) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0x0U, 0x0U};
  uint32_t subtrahend[3] = {0x55555554U, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xAAAAAAABU, 0x0U, 0x0U};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_4) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0x3FFFFU, 0x0U};
  uint32_t subtrahend[3] = {0x3U, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xFFFFFFFCU, 0x3FFFFU, 0x0U};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_5) {
  uint32_t minuend[3] = {0x55555554U, 0x0U, 0x0U};
  uint32_t subtrahend[3] = {0xFFFFFFFFU, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xAAAAAAABU, 0x0U, 0x0U};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 1);
}
END_TEST

START_TEST(mantissa_subtraction_test_6) {
  // 10^28
  uint32_t minuend[3] = {0x10000000, 0x3E250261, 0x204FCE5E};
  uint32_t subtrahend[3] = {0x1, 0x0, 0x0};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0x0FFFFFFF, 0x3E250261, 0x204FCE5E};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_7) {
  // 10^28
  uint32_t minuend[3] = {0x10000000, 0x3E250261, 0x204FCE5E};
  // 2166546186782710593811906561
  uint32_t subtrahend[3] = {0x1, 0x20000040, 0x7002000};
  uint32_t result[3] = {0, 0, 0};
  // 7833453813217289406188093439
  uint32_t expected[3] = {0x0FFFFFFF, 0x1E250221, 0x194FAE5E};
  int is_negaive = mantissa_subtraction(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_shift_left_test_1) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b11100000000000000000000000000111,
                          0b00000000000000000000000000000000};
  uint32_t expected[3] = {0b00000000000000000000000000111000,
                          0b00000000000000000000000000111000,
                          0b00000000000000000000000000000111};
  shift_mantissa_left(mantissa, 3);
  ck_assert_mem_eq(mantissa, expected, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(mantissa_shift_left_test_2) {
  uint32_t mantissa[3] = {0x107A4000, 0x5AF3, 0x0};
  uint32_t expected[3] = {0x0, 0x80000000, 0xB5E620F4};
  shift_mantissa_left(mantissa, 49);
  ck_assert_mem_eq(mantissa, expected, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_1) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b11100000000000000000000000000111,
                          0b00000000000000000000000000000111};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 66);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_2) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_3) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b00000000000000000000000000000010,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 33);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_4) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(mantissa_division_test_1) {
  uint32_t divident[3] = {0b00000000000000000000000000000100,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  int result = mantissa_division(divident, divisor, NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(mantissa_division_test_2) {
  uint32_t divident[3] = {0b00000000000000000000000000001011,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  uint32_t result[3];
  uint32_t remainder[3];
  uint32_t expected_result[3] = {2, 0, 0};
  uint32_t expected_remainder[3] = {3, 0, 0};
  int division_error = mantissa_division(divident, divisor, result, remainder);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_3) {
  uint32_t divident[3] = {0b00000000000000000000000000000000,
                          0b00000000000000000000000000000001,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  uint32_t result[3];
  uint32_t remainder[3];
  uint32_t expected_result[3] = {0x33333333, 0, 0};
  uint32_t expected_remainder[3] = {1, 0, 0};
  int division_error = mantissa_division(divident, divisor, result, remainder);
  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_4) {
  // 4398046511103
  uint32_t divident[3] = {0xFFFFFFFF, 0x3FF, 0x0};
  // 5452542852
  uint32_t divisor[3] = {0x44FF3384, 0x1, 0x0};
  uint32_t result[3];
  uint32_t remainder[3];
  // 806
  uint32_t expected_result[3] = {0x326, 0, 0};
  // 3296972391
  uint32_t expected_remainder[3] = {0xC483CE67, 0x0, 0x0};
  int division_error = mantissa_division(divident, divisor, result, remainder);
  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_5) {
  // 79228162514264337593543950335
  uint32_t divident[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  // 10^14 = 100000000000000
  uint32_t divisor[3] = {0x107A4000, 0x5AF3, 0x0};

  uint32_t result[3];
  uint32_t remainder[3];

  // 792281625142643
  uint32_t expected_result[3] = {0x70D42573, 0x2D093, 0x0};
  // 37593543950335
  uint32_t expected_remainder[3] = {0xEDD53FFF, 0x2230, 0x0};
  mantissa_division(divident, divisor, result, remainder);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
}

START_TEST(get_scale_test) {
  uint32_t scales[] = {
      0b00000000000000000000000000000000, 0b00000000000000010000000000000000,
      0b00000000000000100000000000000000, 0b00000000000000110000000000000000,
      0b00000000000001000000000000000000, 0b00000000000001010000000000000000,
      0b00000000000001100000000000000000, 0b00000000000001110000000000000000,
      0b00000000000010000000000000000000, 0b00000000000010010000000000000000,
      0b00000000000010100000000000000000, 0b00000000000010110000000000000000,
      0b00000000000011000000000000000000, 0b00000000000011010000000000000000,
      0b00000000000011100000000000000000, 0b00000000000011110000000000000000,
      0b00000000000100000000000000000000, 0b00000000000100010000000000000000,
      0b00000000000100100000000000000000, 0b00000000000100110000000000000000,
      0b00000000000101000000000000000000, 0b00000000000101010000000000000000,
      0b00000000000101100000000000000000, 0b00000000000101110000000000000000,
      0b00000000000110000000000000000000, 0b00000000000110010000000000000000,
      0b00000000000110100000000000000000, 0b00000000000110110000000000000000,
      0b00000000000111000000000000000000};

  // printf("\n%d\n", get_scale(scales[1]));
  for (int i = 0; i < 29; i++) {
    // printf("\n%d %d\n", i, get_scale(scales[i]));
    ck_assert_int_eq(get_scale(scales[i]), i);
  }

  //   s21_decimal input_decimal = {{0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000}};
  // int scale_before = get_scale(input_decimal.bits[3]);
  // int scale_to_set = 6;

  // set_scale(&input_decimal.bits[3], scale_to_set);
  // int scale_after = get_scale(input_decimal.bits[3]);
  // ck_assert_int_ne(scale_before, scale_after);
  // ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

START_TEST(set_scale_test) {
  s21_decimal input_decimal = {
      {0x123U, 0x123U, 0x123U, 0b00000000000000101000000000000000}};
  int scale_before = get_scale(input_decimal.bits[3]);
  int scale_to_set = 6;

  set_scale(&input_decimal.bits[3], scale_to_set);
  int scale_after = get_scale(input_decimal.bits[3]);
  ck_assert_int_ne(scale_before, scale_after);
  ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

START_TEST(multiply_test) {
  // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000};
  uint32_t num_1[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t num_2[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t res[6] = {0};
  // debug_print_decimal_as_binary(input_decimal);

  multiply_mantissas(num_1, num_2, res);

  // debug_print_mantissa_as_binary(res, 6);

  // ck_assert_int_ne(scale_before, scale_after);
  // ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

// START_TEST(multiply_test_2) {
//   // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
//   //                              0b00000000000000101000000000000000};
//   uint32_t num_1[3] = {0xF485787A, 0x7F29ABCA, 0x1AD};
//   uint32_t num_2[3] = {0xD83C94FB, 0x1, 0x0};
//   uint32_t res[6] = {0};
//   // debug_print_decimal_as_binary(input_decimal);

//   multiply_mantissas(num_1, num_2, res);

//   debug_print_mantissa_as_binary(res, 6);

//   // ck_assert_int_ne(scale_before, scale_after);
//   // ck_assert_int_eq(scale_after, scale_to_set);
// }
// END_TEST

// START_TEST(print_mantissa_as_binary_test) {
//   // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
//   //                              0b00000000000000101000000000000000};
//   uint32_t num_1[3] = {0x0, 0x0, 0x1869F};
//   debug_print_mantissa_as_binary(num_1, 3);
//   // debug_print_decimal_as_binary(input_decimal);

//   // ck_assert_int_ne(scale_before, scale_after);
//   // ck_assert_int_eq(scale_after, scale_to_set);
// }
// END_TEST

// START_TEST(convert_arr_to_decimal) {
//   // 4573498578943759
//   uint32_t term_1[3] = {0b10011110001011011011111100001111,
//                         0b10000001111111001001000001000010,
//                         0b01010010001001001010101010100101};

//   s21_decimal input_decimal1 = {0b10011110001011011011111100001111,
//                                 0b10000001111111001001000001000010,
//                                 0b01010010001001001010101010100101, 0x0U};
//   s21_decimal input_decimal2 = {0x0U, 0x0U, 0x0U, 0x0U};

//   write_in_mantissa_to_decimal(term_1, &input_decimal2);

//   debug_print_decimal_as_binary(input_decimal1);
//   putchar('\n');
//   debug_print_decimal_as_binary(input_decimal2);
// }
// END_TEST

// START_TEST(get_power_test) {
//   // print_mantissa_as_binary(get_power_of_ten(25), 3);
//   uint32_t* term_1 = get_mantissa_with_power_of_ten(28);
//   debug_print_mantissa_as_binary(term_1, 3);

//   putchar('\n');
// }
// END_TEST

Suite* make_utility_suite() {
  Suite* utility_suite = suite_create("utility");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, get_scale_test);
  tcase_add_test(tc_core, mantissa_addition_test);
  tcase_add_test(tc_core, mantissa_addition_to_self_test);
  tcase_add_test(tc_core, mantissa_bitflip_test);
  tcase_add_test(tc_core, mantissa_copy_test);
  tcase_add_test(tc_core, mantissa_zero_subtraction_test);
  tcase_add_test(tc_core, mantissa_subtraction_test_1);
  tcase_add_test(tc_core, mantissa_subtraction_test_2);
  tcase_add_test(tc_core, mantissa_subtraction_test_3);
  tcase_add_test(tc_core, mantissa_subtraction_test_4);
  tcase_add_test(tc_core, mantissa_subtraction_test_5);
  tcase_add_test(tc_core, mantissa_subtraction_test_6);
  tcase_add_test(tc_core, mantissa_subtraction_test_7);
  tcase_add_test(tc_core, mantissa_shift_left_test_1);
  tcase_add_test(tc_core, mantissa_shift_left_test_2);
  tcase_add_test(tc_core, mantissa_division_test_1);
  tcase_add_test(tc_core, mantissa_division_test_2);
  tcase_add_test(tc_core, mantissa_division_test_3);
  tcase_add_test(tc_core, mantissa_division_test_4);
  tcase_add_test(tc_core, mantissa_division_test_5);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_1);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_2);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_3);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_4);
  tcase_add_test(tc_core, set_scale_test);
  tcase_add_test(tc_core, multiply_test);
  // tcase_add_test(tc_core, multiply_test_2);
  // tcase_add_test(tc_core, get_power_test);
  // tcase_add_test(tc_core, print_mantissa_as_binary_test);
  // tcase_add_test(tc_core, convert_arr_to_decimal);
  // tcase_add_test(tc_core, comparison_eq_test);
  suite_add_tcase(utility_suite, tc_core);
  return utility_suite;
}