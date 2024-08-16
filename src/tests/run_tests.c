#include "run_tests.h"

#include <stdio.h>

int main() {
  int total_number_run = 0;
  int total_number_failed = 0;

  Suite* suites[] = {
      make_add_suite(), make_sub_suite(), make_mul_suite(),
      //  make_div_suite(),
      make_is_less_suite(), make_is_less_or_equal_suite(),
      make_is_greater_suite(), make_is_greater_or_equal_suite(),
      make_is_equal_suite(), make_is_not_equal_suite(),
      make_from_int_to_decimal_suite(), make_from_float_to_decimal_suite(),
      make_from_decimal_to_int_suite(),
      // make_from_decimal_to_float_suite(),
      make_floor_suite(), make_round_suite(), make_truncate_suite(),
      make_negate_suite(), make_utility_suite(), NULL};

  for (Suite** current_suite = suites; *current_suite != NULL;
       current_suite++) {
    run_suite(*current_suite, &total_number_run, &total_number_failed);
  }

  printf("Total tests run:\t%d\nTotal tests failed:\t%d\n", total_number_run,
         total_number_failed);
  return (total_number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed) {
  SRunner* suite_runner;

  suite_runner = srunner_create(current_suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  *total_number_run += srunner_ntests_run(suite_runner);
  *total_number_failed += srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);
}