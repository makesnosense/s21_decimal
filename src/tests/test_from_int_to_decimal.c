#include "../calculation.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_int_to_decimal_gen_0) {
  //   int input_int = -2147483647;

  //   printf("%d", )
  //   s21_decimal s21_result_decimal;

  //   s21_decimal expected_result = {{0x00000000, 0x00000000, 0x00000000,
  //   0x0}};

  //   CalculationResult s21_return_code =
  //       s21_from_int_to_decimal(input_int, &s21_result_decimal);

  //   ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result),
  //   TRUE); ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_int_to_decimal_suite() {
  Suite* from_int_to_decimal_suite = suite_create("from_int_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_0);

  suite_add_tcase(from_int_to_decimal_suite, tc_core);

  return from_int_to_decimal_suite;
}