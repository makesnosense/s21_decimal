#include "../helper_funcs.h"
#include "debug_funcs.h"
#include "run_tests.h"

START_TEST(test_first) {
  s21_decimal input_decimal = {0x123U, 0x123U, 0x123U, 0x0U};
  // print_decimal_as_binary(input_decimal);
  putchar('\n');
  // print_binary(-1024);
  print_binary(-1);
  putchar('\n');
  putchar('\n');
  // reset_decimal(&input_decimal);
  // print_decimal_as_binary(input_decimal);
  putchar('\n');
  putchar('\n');
  s21_from_int_to_decimal(-1, &input_decimal);

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

Suite* make_first_suite() {
  Suite* len_suite = suite_create("first");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_first);

  suite_add_tcase(len_suite, tc_core);
  return len_suite;
}