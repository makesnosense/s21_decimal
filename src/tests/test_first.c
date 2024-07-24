#include "../utility.h"
#include "debug_funcs.h"
#include "run_tests.h"

START_TEST(test_first) {
  s21_decimal input_decimal = {0x123U, 0x123U, 0x123U, 0x0U};
  // print_decimal_as_binary(input_decimal);
  putchar('\n');
  // print_binary(-1024);
  print_binary(1111);
  putchar('\n');
  putchar('\n');
  // reset_decimal(&input_decimal);
  // print_decimal_as_binary(input_decimal);
  putchar('\n');
  putchar('\n');
  s21_from_int_to_decimal(1111, &input_decimal);

  print_decimal_as_binary(input_decimal);

  // // printf("%d", get_bit(29, 5555));
  // putchar('\n');
  // print_binary(set_bit(29, 1));
  // putchar('\n');
  // putchar('\n');
  // print_binary(reset_bit(set_bit(29, 1), 0));
  // putchar('\n');

  // print_decimal_as_binary(input_decimal);
  // putchar('\n');
  // set_sign(&input_decimal, MINUS);
  // print_decimal_as_binary(input_decimal);
  // print_decimal_as_binary(input_decimal);
}
END_TEST

START_TEST(mantissa_addition_test) {
  // 4573498578943759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b100000011111110010010, 0b0};
  // 3648576347873449873
  uint32_t term_2[3] = {0b01111110111000111001011110010001,
                        0b110010101000100101100011011011, 0b0};
  // 3 653 149 846 452 393 632
  uint32_t sum[3] = {0b0, 0b0, 0b0};
  mantissa_addition(term_1, term_2, sum);
  puts("\naddition\n");
  print_binary(sum[2]);
  puts("\n");
  print_binary(sum[1]);
  puts("\n");
  print_binary(sum[0]);
  puts("\n");
}
END_TEST
// 11 0010 1011 0010 1001 1000 0110 1110
// 0001 1101 0001 0001 0101 0110 1010 0000

START_TEST(set_power_test) {
  s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
                               0b00000000000000101000000000000000};
  // print_decimal_as_binary(input_decimal);
  int power_before = get_power(input_decimal.bits[3]);
  printf("\n\n%d\n\n", power_before);
  int power_to_set = 6;

  set_power(&input_decimal.bits[3], power_to_set);

  int power_after = get_power(input_decimal.bits[3]);

  printf("\n\n%d\n\n", power_after);

  ck_assert_int_ne(power_before, power_after);
  ck_assert_int_eq(power_after, power_to_set);
}
END_TEST

START_TEST(multiply_test) {
  // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000};
  uint32_t num_1[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t num_2[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t res[6] = {0};
  // print_decimal_as_binary(input_decimal);

  multiply_large_numbers(num_1, num_2, res);

  print_large_number(res, 6);

  // ck_assert_int_ne(power_before, power_after);
  // ck_assert_int_eq(power_after, power_to_set);
}
END_TEST

START_TEST(multiply_test_2) {
  // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000};
  uint32_t num_1[3] = {0x2, 0x0, 0x0};
  uint32_t num_2[3] = {0x3, 0x0, 0x6};
  uint32_t res[6] = {0};
  // print_decimal_as_binary(input_decimal);

  multiply_large_numbers(num_1, num_2, res);

  print_large_number(res, 6);

  // ck_assert_int_ne(power_before, power_after);
  // ck_assert_int_eq(power_after, power_to_set);
}
END_TEST

START_TEST(print_mantissa_as_binary_test) {
  // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000};
  uint32_t num_1[3] = {0x0, 0x0, 0x1869F};
  print_mantissa_as_binary(num_1, 3);
  // print_decimal_as_binary(input_decimal);

  // ck_assert_int_ne(power_before, power_after);
  // ck_assert_int_eq(power_after, power_to_set);
}
END_TEST

START_TEST(convert_arr_to_decimal) {
  // 4573498578943759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b10000001111111001001000001000010,
                        0b01010010001001001010101010100101};

  s21_decimal input_decimal1 = {0b10011110001011011011111100001111,
                                0b10000001111111001001000001000010,
                                0b01010010001001001010101010100101, 0x0U};
  s21_decimal input_decimal2 = {0x0U, 0x0U, 0x0U, 0x0U};

  write_in_mantissa_to_decimal(term_1, &input_decimal2);

  print_decimal_as_binary(input_decimal1);
  putchar('\n');
  print_decimal_as_binary(input_decimal2);
}
END_TEST

Suite* make_first_suite() {
  Suite* first_suite = suite_create("first");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  // tcase_add_test(tc_core, test_first);
  // tcase_add_test(tc_core, mantissa_addition_test);
  // tcase_add_test(tc_core, set_power_test);
  // tcase_add_test(tc_core, multiply_test);
  // tcase_add_test(tc_core, multiply_test_2);
  tcase_add_test(tc_core, print_mantissa_as_binary_test);
  tcase_add_test(tc_core, convert_arr_to_decimal);
  suite_add_tcase(first_suite, tc_core);
  return first_suite;
}