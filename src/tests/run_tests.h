#ifndef SRC_TESTS_RUN_TESTS_H_
#define SRC_TESTS_RUN_TESTS_H_

#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed);

Suite* make_utility_suite();
Suite* make_is_equal_suite();
Suite* make_mul_suite();

#endif  // SRC_TESTS_RUN_TESTS_H_