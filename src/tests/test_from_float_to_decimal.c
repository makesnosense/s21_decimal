#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

Suite* make_from_float_to_decimal_suite() {
  Suite* from_float_to_decimal_suite = suite_create("from_float_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  suite_add_tcase(from_float_to_decimal_suite, tc_core);

  return from_float_to_decimal_suite;
}