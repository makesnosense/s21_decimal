#ifndef SRC_TESTS_RUN_TESTS_H_
#define SRC_TESTS_RUN_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

void run_suite(Suite* current_suite, int* total_number_run,
               int* total_number_failed);

Suite* make_utility_suite();

Suite* make_is_less_suite();
Suite* make_is_less_or_equal_suite();
Suite* make_is_greater_suite();
Suite* make_is_greater_or_equal_suite();
Suite* make_is_equal_suite();
Suite* make_is_not_equal_suite();

Suite* make_add_suite();
Suite* make_sub_suite();
Suite* make_mul_suite();
Suite* make_div_suite();

Suite* make_from_int_to_decimal_suite();
Suite* make_from_float_to_decimal_suite();
Suite* make_from_decimal_to_int_suite();
Suite* make_from_decimal_to_float_suite();

Suite* make_truncate_suite();
Suite* make_negate_suite();
Suite* make_floor_suite();
Suite* make_round_suite();

#endif  // SRC_TESTS_RUN_TESTS_H_
