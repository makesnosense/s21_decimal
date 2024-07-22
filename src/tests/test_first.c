#include "debug_funcs.h"
#include "run_tests.h"

START_TEST(test_first) { print_binary(4123123); }
END_TEST

Suite* make_first_suite() {
  Suite* len_suite = suite_create("first");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_first);

  suite_add_tcase(len_suite, tc_core);
  return len_suite;
}