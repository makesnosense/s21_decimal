#include "../arithmetic.h"
// #include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

// START_TEST(test_div_simple) {
//   s21_decimal input_decimal1 = {0x0, 0x1, 0x0,
//                                 0b00000000000000000000000000000000};

//   s21_decimal input_decimal2 = {0x2, 0x0, 0x0,
//                                 0b00000000000000000000000000000000};
//   s21_decimal result_decimal = {0x0, 0x0, 0x0, 0x0};

//   s21_div(input_decimal1, input_decimal2, &result_decimal);

//   // debug_print_decimal_as_binary(result_decimal);
// }
// END_TEST

Suite* make_div_suite() {
  Suite* div_suite = suite_create("div");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  // tcase_add_test(tc_core, test_div_simple);

  suite_add_tcase(div_suite, tc_core);

  return div_suite;
}