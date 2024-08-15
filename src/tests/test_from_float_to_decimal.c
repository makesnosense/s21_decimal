#include "../calculation.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

// START_TEST(test_from_float_to_decimal_gen_0) {
//   float input_int = 0.1;

//   s21_decimal s21_result_decimal;

//   s21_decimal expected_result = {{0x00000000, 0x00000000, 0x00000000, 0x0}};

//   int s21_return_code =
//       s21_from_float_to_decimal(input_int, &s21_result_decimal);

//   ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
//   ck_assert_int_eq(s21_return_code, OK);
// }
// END_TEST

START_TEST(test_from_float_to_decimal_ok) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -30.7339287
  float input_float = -30.7339287;
  // -30.73393

  s21_decimal expected_result = {{0x2EE571, 0x0, 0x0, 0x80050000}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  // debug_print_decimal_as_binary(expected_result);
  // putchar('\n');
  // debug_print_decimal_as_binary(s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);

  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_float_to_decimal_suite() {
  Suite* from_float_to_decimal_suite = suite_create("from_float_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  // tcase_add_test(tc_core, test_from_float_to_decimal_gen_0);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok);

  suite_add_tcase(from_float_to_decimal_suite, tc_core);

  return from_float_to_decimal_suite;
}