#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_greater_or_equal) {
  s21_decimal input_decimal1 = {0x0, 0x1, 0x0,
                                0b00000000000000000000000000000000};

  s21_decimal input_decimal2 = {0x2, 0x0, 0x0,
                                0b00000000000000000000000000000000};

  int result = s21_is_greater_or_equal(input_decimal1, input_decimal2);

  ck_assert_int_eq(result, TRUE);
}
END_TEST

Suite* make_is_greater_or_equal_suite() {
  Suite* is_greater_or_equal_suite = suite_create("is_greater_or_equal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_greater_or_equal);

  suite_add_tcase(is_greater_or_equal_suite, tc_core);

  return is_greater_or_equal_suite;
}