#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

// START_TEST(test_from_float_to_decimal_gen_0) {
//   int input_int = -2147483640;
//   // -2147483640
//   s21_decimal expected_result =
//   { {0x7FFFFFF8, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}
//   }

//   s21_decimal s21_result_decimal;
//   ConversionResult s21_return_code =
//       s21_from_int_to_decimal(input_int, &s21_result_decimal);

//   ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
//   ck_assert_int_eq(s21_return_code, OK);
// }
// END_TEST

Suite* make_from_float_to_decimal_suite() {
  Suite* from_float_to_decimal_suite = suite_create("from_float_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  suite_add_tcase(from_float_to_decimal_suite, tc_core);

  return from_float_to_decimal_suite;
}