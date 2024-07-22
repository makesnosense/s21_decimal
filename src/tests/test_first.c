#include "../helper_funcs.h"
#include "debug_funcs.h"
#include "run_tests.h"

START_TEST(test_first) {
  s21_decimal input_decimal = {0x123U, 0x123U, 0x123U, 0x0};
  print_binary(29);
  putchar('\n');
  // printf("%d", get_bit(29, 5555));
  putchar('\n');
  print_binary(set_bit(29, 1));
  putchar('\n');
  putchar('\n');
  print_binary(reset_bit(set_bit(29, 1), 0));
  putchar('\n');
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