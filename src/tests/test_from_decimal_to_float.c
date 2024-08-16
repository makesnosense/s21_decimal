#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_decimal_to_float_gen_0) {
  // 1234567800000000
  s21_decimal input_decimal = {
      {0x372B8E00, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  // 1234567813922816
  uint32_t expected_result = 0b01011000100011000101101010100111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_decimal_to_float_suite() {
  Suite* from_decimal_to_float_suite = suite_create("from_decimal_to_float");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_float_gen_0);
  suite_add_tcase(from_decimal_to_float_suite, tc_core);

  return from_decimal_to_float_suite;
}