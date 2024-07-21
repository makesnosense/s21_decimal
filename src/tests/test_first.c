#include "run_tests.h"

START_TEST(test_first) {
  int s21_res = very_function();

  ck_assert_int_eq(s21_res, 0);
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