#include "../arithmetic.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_mul_simple) {
  s21_decimal input_decimal1 = {0x0, 0x1, 0x0,
                                0b00000000000000000000000000000000};

  s21_decimal input_decimal2 = {0x2, 0x0, 0x0,
                                0b00000000000000000000000000000000};
  s21_decimal result_decimal = {0x0, 0x0, 0x0, 0x0};

  s21_mul(input_decimal1, input_decimal2, &result_decimal);

  debug_print_decimal_as_binary(result_decimal);
}
END_TEST

Suite* make_mul_suite() {
  Suite* mul_suite = suite_create("mul");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mul_simple);

  suite_add_tcase(mul_suite, tc_core);

  return mul_suite;
}