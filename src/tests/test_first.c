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

START_TEST(get_power_test) {
  s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
                               0b00000000000000101000000000000000};

  print_decimal_as_binary(input_decimal);

  int power = get_power(input_decimal.bits[3]);
  printf("\n\n%d\n\n", power);

  set_power(&input_decimal.bits[3], 6);

  print_decimal_as_binary(input_decimal);

  power = get_power(input_decimal.bits[3]);
  printf("\n\n%d\n\n", power);
}
END_TEST

Suite* make_first_suite() {
  Suite* len_suite = suite_create("first");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  // tcase_add_test(tc_core, test_first);
  tcase_add_test(tc_core, mantissa_addition_test);
  // tcase_add_test(tc_core, get_power_test);

  suite_add_tcase(len_suite, tc_core);
  return len_suite;
}