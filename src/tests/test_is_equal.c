#include "../comparison.h"
#include "run_tests.h"

START_TEST(comparison_eq_test) {
  s21_decimal input_decimal_1 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000001010000000000000000};

  s21_decimal input_decimal_2 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000};

  ComparisonResult result_1 = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result_1, FALSE);

  // ck_assert_int_eq(s21_is_equal(input_decimal_1, input_decimal_2), 0);

  s21_decimal input_decimal_3 = {0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000};

  s21_decimal input_decimal_4 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_3, input_decimal_4), 0);

  // 999999999999 scale 0
  s21_decimal input_decimal_5 = {0xD4A50FFF, 0xE8, 0x0,
                                 0b00000000000000000000000000000000};
  // 999999999999000 scale 3
  s21_decimal input_decimal_6 = {0xA4C67C18, 0x38D7E, 0x0,
                                 0b00000000000000110000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_5, input_decimal_6), 1);

  // 2*(10**28) scale 28
  s21_decimal input_decimal_7 = {0x20000000, 0x7C4A04C2, 0x409F9CBC,
                                 0b00000000000111000000000000000000};

  // 2 scale 0
  s21_decimal input_decimal_8 = {0x2, 0x0, 0x0,
                                 0b00000000000000000000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_7, input_decimal_8), 1);

  s21_decimal input_decimal_9 = {0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000};

  s21_decimal input_decimal_10 = {0x124U, 0x123U, 0x123U,
                                  0b00000000000000101000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_9, input_decimal_10), TRUE);

  // 0
  s21_decimal input_decimal_11 = {0x0U, 0x0U, 0x0U,
                                  0b00000000000000101000000000000000};
  // -0
  s21_decimal input_decimal_12 = {0x0U, 0x0U, 0x0U,
                                  0b10000000000110110000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_11, input_decimal_12), 1);
}
END_TEST

START_TEST(comparison_test_auto_0) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_1) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_2) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_3) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_4) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_5) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_6) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_7) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_8) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_9) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_10) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_11) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_12) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_13) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_14) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_15) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_16) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_17) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_18) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_19) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_20) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_21) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_22) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_23) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_24) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_25) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_26) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_27) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_28) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_29) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_30) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_31) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_32) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_33) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_34) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_35) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_36) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_37) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_38) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_39) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_40) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_41) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_42) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_43) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_44) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_45) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_46) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_47) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_48) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_49) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_50) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_51) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_52) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_53) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_54) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_55) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_56) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_57) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_58) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_59) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_60) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_61) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_62) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_63) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_64) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_65) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_66) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_67) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_68) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_69) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_70) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_71) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_72) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_73) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_74) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_75) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_76) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_77) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_78) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_79) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_80) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_81) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_82) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_83) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_84) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_85) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_86) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_87) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_88) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_89) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_90) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_91) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_92) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_93) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_94) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_95) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_96) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_97) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_98) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_99) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_100) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_101) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_102) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_103) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_104) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_105) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_106) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_107) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_108) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_109) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_110) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_111) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_112) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_113) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_114) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_115) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_116) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_117) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_118) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_119) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_120) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_121) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_122) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_123) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_124) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_125) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_126) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_127) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_128) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_129) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_130) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_131) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_132) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_133) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_134) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_135) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_136) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_137) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_138) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_139) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_140) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_141) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_142) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_143) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_144) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_145) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_146) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_147) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_148) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_149) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_150) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_151) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_152) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_153) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_154) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_155) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_156) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_157) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_158) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_159) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_160) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_161) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_162) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_163) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_164) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_165) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_166) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_167) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_168) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_169) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_170) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_171) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_172) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_173) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_174) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_175) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_176) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_177) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_178) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_179) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_180) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_181) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_182) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_183) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_184) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_185) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_186) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_187) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_188) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_189) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_190) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_191) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_192) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_193) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_194) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_195) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_196) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_197) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_198) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_199) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_200) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_201) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_202) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_203) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_204) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_205) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_206) {
  // 1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_207) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_208) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_209) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_210) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_211) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_212) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_213) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_214) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_215) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_216) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_217) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_218) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_219) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_220) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_221) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_222) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_223) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_224) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_225) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_226) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_227) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_228) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_229) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_230) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_231) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_232) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_233) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_234) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_235) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_236) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_237) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_238) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_239) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_240) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_241) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_242) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_243) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_244) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_245) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_246) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_247) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_248) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_249) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(comparison_test_auto_250) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_251) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_252) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_253) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_254) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_255) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_256) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_257) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_258) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_259) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_260) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_261) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_262) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_263) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_264) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_265) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_266) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_267) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_268) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_269) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_270) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_271) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_272) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_273) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_274) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_275) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_276) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_277) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_278) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_279) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_280) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_281) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_282) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_283) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_284) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_285) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_286) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_287) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_288) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(comparison_test_auto_289) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_290) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_291) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_292) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_293) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_294) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_295) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_296) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_297) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_298) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_299) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_300) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_301) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_302) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_303) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_304) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_305) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_306) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_307) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_308) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_309) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_310) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_311) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(comparison_test_auto_312) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_313) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_314) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_315) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_316) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_317) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_318) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_319) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_320) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_321) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_322) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_323) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_324) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_325) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_326) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_327) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_328) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_329) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_330) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_331) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_332) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_333) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_334) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_335) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_336) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_337) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_338) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_339) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_340) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_341) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_342) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_343) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_344) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_345) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_346) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_347) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_348) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_349) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_350) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_351) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_352) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_353) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_354) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_355) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_356) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_357) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_358) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_359) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_360) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_361) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_362) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_363) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_364) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_365) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_366) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_367) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_368) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_369) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_370) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_371) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_372) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_373) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_374) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_375) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_376) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_377) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_378) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_379) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_380) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_381) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_382) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_383) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_384) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_385) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_386) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_387) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_388) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_389) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_390) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_391) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_392) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_393) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_394) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_395) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_396) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_397) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_398) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_399) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_400) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_401) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_402) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_403) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_404) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_405) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_406) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_407) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_408) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_409) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_410) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_411) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_412) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_413) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_414) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_415) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_416) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_417) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_418) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_419) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_420) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_421) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_422) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_423) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_424) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_425) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_426) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_427) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_428) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_429) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_430) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_431) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_432) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_433) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_434) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_435) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_436) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_437) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_438) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_439) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_440) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_441) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_442) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_443) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_444) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_445) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_446) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_447) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_448) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_449) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_450) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_451) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_452) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_453) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_454) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_455) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_456) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_457) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_458) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_459) {
  // -1E-28
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_460) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_461) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_462) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_463) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_464) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_465) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_466) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_467) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_468) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_469) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_470) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, TRUE);
}
END_TEST

START_TEST(comparison_test_auto_471) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_472) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_473) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_474) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_475) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_476) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_477) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_478) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_479) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_480) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_481) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_482) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_483) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_484) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_485) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_486) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_487) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_488) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_489) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_490) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_491) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_492) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_493) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_494) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_495) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_496) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_497) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_498) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_499) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_500) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_501) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_502) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_503) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_504) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_505) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_506) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_507) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_508) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_509) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_510) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_511) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_512) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_513) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_514) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_515) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_516) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_517) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_518) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_519) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_520) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_521) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_522) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_523) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_524) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_525) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_526) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_527) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_528) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_529) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_530) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_531) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_532) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_533) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_534) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_535) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_536) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_537) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_538) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_539) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_540) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_541) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_542) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_543) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_544) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_545) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_546) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_547) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_548) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -1E-28
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_549) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_550) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

START_TEST(comparison_test_auto_551) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result, FALSE);
}
END_TEST

Suite* make_is_equal_suite() {
  Suite* is_equal_suite = suite_create("is_equal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, comparison_eq_test);
  tcase_add_test(tc_core, comparison_test_auto_0);
  tcase_add_test(tc_core, comparison_test_auto_1);
  tcase_add_test(tc_core, comparison_test_auto_2);
  tcase_add_test(tc_core, comparison_test_auto_3);
  tcase_add_test(tc_core, comparison_test_auto_4);
  tcase_add_test(tc_core, comparison_test_auto_5);
  tcase_add_test(tc_core, comparison_test_auto_6);
  tcase_add_test(tc_core, comparison_test_auto_7);
  tcase_add_test(tc_core, comparison_test_auto_8);
  tcase_add_test(tc_core, comparison_test_auto_9);
  tcase_add_test(tc_core, comparison_test_auto_10);
  tcase_add_test(tc_core, comparison_test_auto_11);
  tcase_add_test(tc_core, comparison_test_auto_12);
  tcase_add_test(tc_core, comparison_test_auto_13);
  tcase_add_test(tc_core, comparison_test_auto_14);
  tcase_add_test(tc_core, comparison_test_auto_15);
  tcase_add_test(tc_core, comparison_test_auto_16);
  tcase_add_test(tc_core, comparison_test_auto_17);
  tcase_add_test(tc_core, comparison_test_auto_18);
  tcase_add_test(tc_core, comparison_test_auto_19);
  tcase_add_test(tc_core, comparison_test_auto_20);
  tcase_add_test(tc_core, comparison_test_auto_21);
  tcase_add_test(tc_core, comparison_test_auto_22);
  tcase_add_test(tc_core, comparison_test_auto_23);
  tcase_add_test(tc_core, comparison_test_auto_24);
  tcase_add_test(tc_core, comparison_test_auto_25);
  tcase_add_test(tc_core, comparison_test_auto_26);
  tcase_add_test(tc_core, comparison_test_auto_27);
  tcase_add_test(tc_core, comparison_test_auto_28);
  tcase_add_test(tc_core, comparison_test_auto_29);
  tcase_add_test(tc_core, comparison_test_auto_30);
  tcase_add_test(tc_core, comparison_test_auto_31);
  tcase_add_test(tc_core, comparison_test_auto_32);
  tcase_add_test(tc_core, comparison_test_auto_33);
  tcase_add_test(tc_core, comparison_test_auto_34);
  tcase_add_test(tc_core, comparison_test_auto_35);
  tcase_add_test(tc_core, comparison_test_auto_36);
  tcase_add_test(tc_core, comparison_test_auto_37);
  tcase_add_test(tc_core, comparison_test_auto_38);
  tcase_add_test(tc_core, comparison_test_auto_39);
  tcase_add_test(tc_core, comparison_test_auto_40);
  tcase_add_test(tc_core, comparison_test_auto_41);
  tcase_add_test(tc_core, comparison_test_auto_42);
  tcase_add_test(tc_core, comparison_test_auto_43);
  tcase_add_test(tc_core, comparison_test_auto_44);
  tcase_add_test(tc_core, comparison_test_auto_45);
  tcase_add_test(tc_core, comparison_test_auto_46);
  tcase_add_test(tc_core, comparison_test_auto_47);
  tcase_add_test(tc_core, comparison_test_auto_48);
  tcase_add_test(tc_core, comparison_test_auto_49);
  tcase_add_test(tc_core, comparison_test_auto_50);
  tcase_add_test(tc_core, comparison_test_auto_51);
  tcase_add_test(tc_core, comparison_test_auto_52);
  tcase_add_test(tc_core, comparison_test_auto_53);
  tcase_add_test(tc_core, comparison_test_auto_54);
  tcase_add_test(tc_core, comparison_test_auto_55);
  tcase_add_test(tc_core, comparison_test_auto_56);
  tcase_add_test(tc_core, comparison_test_auto_57);
  tcase_add_test(tc_core, comparison_test_auto_58);
  tcase_add_test(tc_core, comparison_test_auto_59);
  tcase_add_test(tc_core, comparison_test_auto_60);
  tcase_add_test(tc_core, comparison_test_auto_61);
  tcase_add_test(tc_core, comparison_test_auto_62);
  tcase_add_test(tc_core, comparison_test_auto_63);
  tcase_add_test(tc_core, comparison_test_auto_64);
  tcase_add_test(tc_core, comparison_test_auto_65);
  tcase_add_test(tc_core, comparison_test_auto_66);
  tcase_add_test(tc_core, comparison_test_auto_67);
  tcase_add_test(tc_core, comparison_test_auto_68);
  tcase_add_test(tc_core, comparison_test_auto_69);
  tcase_add_test(tc_core, comparison_test_auto_70);
  tcase_add_test(tc_core, comparison_test_auto_71);
  tcase_add_test(tc_core, comparison_test_auto_72);
  tcase_add_test(tc_core, comparison_test_auto_73);
  tcase_add_test(tc_core, comparison_test_auto_74);
  tcase_add_test(tc_core, comparison_test_auto_75);
  tcase_add_test(tc_core, comparison_test_auto_76);
  tcase_add_test(tc_core, comparison_test_auto_77);
  tcase_add_test(tc_core, comparison_test_auto_78);
  tcase_add_test(tc_core, comparison_test_auto_79);
  tcase_add_test(tc_core, comparison_test_auto_80);
  tcase_add_test(tc_core, comparison_test_auto_81);
  tcase_add_test(tc_core, comparison_test_auto_82);
  tcase_add_test(tc_core, comparison_test_auto_83);
  tcase_add_test(tc_core, comparison_test_auto_84);
  tcase_add_test(tc_core, comparison_test_auto_85);
  tcase_add_test(tc_core, comparison_test_auto_86);
  tcase_add_test(tc_core, comparison_test_auto_87);
  tcase_add_test(tc_core, comparison_test_auto_88);
  tcase_add_test(tc_core, comparison_test_auto_89);
  tcase_add_test(tc_core, comparison_test_auto_90);
  tcase_add_test(tc_core, comparison_test_auto_91);
  tcase_add_test(tc_core, comparison_test_auto_92);
  tcase_add_test(tc_core, comparison_test_auto_93);
  tcase_add_test(tc_core, comparison_test_auto_94);
  tcase_add_test(tc_core, comparison_test_auto_95);
  tcase_add_test(tc_core, comparison_test_auto_96);
  tcase_add_test(tc_core, comparison_test_auto_97);
  tcase_add_test(tc_core, comparison_test_auto_98);
  tcase_add_test(tc_core, comparison_test_auto_99);
  tcase_add_test(tc_core, comparison_test_auto_100);
  tcase_add_test(tc_core, comparison_test_auto_101);
  tcase_add_test(tc_core, comparison_test_auto_102);
  tcase_add_test(tc_core, comparison_test_auto_103);
  tcase_add_test(tc_core, comparison_test_auto_104);
  tcase_add_test(tc_core, comparison_test_auto_105);
  tcase_add_test(tc_core, comparison_test_auto_106);
  tcase_add_test(tc_core, comparison_test_auto_107);
  tcase_add_test(tc_core, comparison_test_auto_108);
  tcase_add_test(tc_core, comparison_test_auto_109);
  tcase_add_test(tc_core, comparison_test_auto_110);
  tcase_add_test(tc_core, comparison_test_auto_111);
  tcase_add_test(tc_core, comparison_test_auto_112);
  tcase_add_test(tc_core, comparison_test_auto_113);
  tcase_add_test(tc_core, comparison_test_auto_114);
  tcase_add_test(tc_core, comparison_test_auto_115);
  tcase_add_test(tc_core, comparison_test_auto_116);
  tcase_add_test(tc_core, comparison_test_auto_117);
  tcase_add_test(tc_core, comparison_test_auto_118);
  tcase_add_test(tc_core, comparison_test_auto_119);
  tcase_add_test(tc_core, comparison_test_auto_120);
  tcase_add_test(tc_core, comparison_test_auto_121);
  tcase_add_test(tc_core, comparison_test_auto_122);
  tcase_add_test(tc_core, comparison_test_auto_123);
  tcase_add_test(tc_core, comparison_test_auto_124);
  tcase_add_test(tc_core, comparison_test_auto_125);
  tcase_add_test(tc_core, comparison_test_auto_126);
  tcase_add_test(tc_core, comparison_test_auto_127);
  tcase_add_test(tc_core, comparison_test_auto_128);
  tcase_add_test(tc_core, comparison_test_auto_129);
  tcase_add_test(tc_core, comparison_test_auto_130);
  tcase_add_test(tc_core, comparison_test_auto_131);
  tcase_add_test(tc_core, comparison_test_auto_132);
  tcase_add_test(tc_core, comparison_test_auto_133);
  tcase_add_test(tc_core, comparison_test_auto_134);
  tcase_add_test(tc_core, comparison_test_auto_135);
  tcase_add_test(tc_core, comparison_test_auto_136);
  tcase_add_test(tc_core, comparison_test_auto_137);
  tcase_add_test(tc_core, comparison_test_auto_138);
  tcase_add_test(tc_core, comparison_test_auto_139);
  tcase_add_test(tc_core, comparison_test_auto_140);
  tcase_add_test(tc_core, comparison_test_auto_141);
  tcase_add_test(tc_core, comparison_test_auto_142);
  tcase_add_test(tc_core, comparison_test_auto_143);
  tcase_add_test(tc_core, comparison_test_auto_144);
  tcase_add_test(tc_core, comparison_test_auto_145);
  tcase_add_test(tc_core, comparison_test_auto_146);
  tcase_add_test(tc_core, comparison_test_auto_147);
  tcase_add_test(tc_core, comparison_test_auto_148);
  tcase_add_test(tc_core, comparison_test_auto_149);
  tcase_add_test(tc_core, comparison_test_auto_150);
  tcase_add_test(tc_core, comparison_test_auto_151);
  tcase_add_test(tc_core, comparison_test_auto_152);
  tcase_add_test(tc_core, comparison_test_auto_153);
  tcase_add_test(tc_core, comparison_test_auto_154);
  tcase_add_test(tc_core, comparison_test_auto_155);
  tcase_add_test(tc_core, comparison_test_auto_156);
  tcase_add_test(tc_core, comparison_test_auto_157);
  tcase_add_test(tc_core, comparison_test_auto_158);
  tcase_add_test(tc_core, comparison_test_auto_159);
  tcase_add_test(tc_core, comparison_test_auto_160);
  tcase_add_test(tc_core, comparison_test_auto_161);
  tcase_add_test(tc_core, comparison_test_auto_162);
  tcase_add_test(tc_core, comparison_test_auto_163);
  tcase_add_test(tc_core, comparison_test_auto_164);
  tcase_add_test(tc_core, comparison_test_auto_165);
  tcase_add_test(tc_core, comparison_test_auto_166);
  tcase_add_test(tc_core, comparison_test_auto_167);
  tcase_add_test(tc_core, comparison_test_auto_168);
  tcase_add_test(tc_core, comparison_test_auto_169);
  tcase_add_test(tc_core, comparison_test_auto_170);
  tcase_add_test(tc_core, comparison_test_auto_171);
  tcase_add_test(tc_core, comparison_test_auto_172);
  tcase_add_test(tc_core, comparison_test_auto_173);
  tcase_add_test(tc_core, comparison_test_auto_174);
  tcase_add_test(tc_core, comparison_test_auto_175);
  tcase_add_test(tc_core, comparison_test_auto_176);
  tcase_add_test(tc_core, comparison_test_auto_177);
  tcase_add_test(tc_core, comparison_test_auto_178);
  tcase_add_test(tc_core, comparison_test_auto_179);
  tcase_add_test(tc_core, comparison_test_auto_180);
  tcase_add_test(tc_core, comparison_test_auto_181);
  tcase_add_test(tc_core, comparison_test_auto_182);
  tcase_add_test(tc_core, comparison_test_auto_183);
  tcase_add_test(tc_core, comparison_test_auto_184);
  tcase_add_test(tc_core, comparison_test_auto_185);
  tcase_add_test(tc_core, comparison_test_auto_186);
  tcase_add_test(tc_core, comparison_test_auto_187);
  tcase_add_test(tc_core, comparison_test_auto_188);
  tcase_add_test(tc_core, comparison_test_auto_189);
  tcase_add_test(tc_core, comparison_test_auto_190);
  tcase_add_test(tc_core, comparison_test_auto_191);
  tcase_add_test(tc_core, comparison_test_auto_192);
  tcase_add_test(tc_core, comparison_test_auto_193);
  tcase_add_test(tc_core, comparison_test_auto_194);
  tcase_add_test(tc_core, comparison_test_auto_195);
  tcase_add_test(tc_core, comparison_test_auto_196);
  tcase_add_test(tc_core, comparison_test_auto_197);
  tcase_add_test(tc_core, comparison_test_auto_198);
  tcase_add_test(tc_core, comparison_test_auto_199);
  tcase_add_test(tc_core, comparison_test_auto_200);
  tcase_add_test(tc_core, comparison_test_auto_201);
  tcase_add_test(tc_core, comparison_test_auto_202);
  tcase_add_test(tc_core, comparison_test_auto_203);
  tcase_add_test(tc_core, comparison_test_auto_204);
  tcase_add_test(tc_core, comparison_test_auto_205);
  tcase_add_test(tc_core, comparison_test_auto_206);
  tcase_add_test(tc_core, comparison_test_auto_207);
  tcase_add_test(tc_core, comparison_test_auto_208);
  tcase_add_test(tc_core, comparison_test_auto_209);
  tcase_add_test(tc_core, comparison_test_auto_210);
  tcase_add_test(tc_core, comparison_test_auto_211);
  tcase_add_test(tc_core, comparison_test_auto_212);
  tcase_add_test(tc_core, comparison_test_auto_213);
  tcase_add_test(tc_core, comparison_test_auto_214);
  tcase_add_test(tc_core, comparison_test_auto_215);
  tcase_add_test(tc_core, comparison_test_auto_216);
  tcase_add_test(tc_core, comparison_test_auto_217);
  tcase_add_test(tc_core, comparison_test_auto_218);
  tcase_add_test(tc_core, comparison_test_auto_219);
  tcase_add_test(tc_core, comparison_test_auto_220);
  tcase_add_test(tc_core, comparison_test_auto_221);
  tcase_add_test(tc_core, comparison_test_auto_222);
  tcase_add_test(tc_core, comparison_test_auto_223);
  tcase_add_test(tc_core, comparison_test_auto_224);
  tcase_add_test(tc_core, comparison_test_auto_225);
  tcase_add_test(tc_core, comparison_test_auto_226);
  tcase_add_test(tc_core, comparison_test_auto_227);
  tcase_add_test(tc_core, comparison_test_auto_228);
  tcase_add_test(tc_core, comparison_test_auto_229);
  tcase_add_test(tc_core, comparison_test_auto_230);
  tcase_add_test(tc_core, comparison_test_auto_231);
  tcase_add_test(tc_core, comparison_test_auto_232);
  tcase_add_test(tc_core, comparison_test_auto_233);
  tcase_add_test(tc_core, comparison_test_auto_234);
  tcase_add_test(tc_core, comparison_test_auto_235);
  tcase_add_test(tc_core, comparison_test_auto_236);
  tcase_add_test(tc_core, comparison_test_auto_237);
  tcase_add_test(tc_core, comparison_test_auto_238);
  tcase_add_test(tc_core, comparison_test_auto_239);
  tcase_add_test(tc_core, comparison_test_auto_240);
  tcase_add_test(tc_core, comparison_test_auto_241);
  tcase_add_test(tc_core, comparison_test_auto_242);
  tcase_add_test(tc_core, comparison_test_auto_243);
  tcase_add_test(tc_core, comparison_test_auto_244);
  tcase_add_test(tc_core, comparison_test_auto_245);
  tcase_add_test(tc_core, comparison_test_auto_246);
  tcase_add_test(tc_core, comparison_test_auto_247);
  tcase_add_test(tc_core, comparison_test_auto_248);
  tcase_add_test(tc_core, comparison_test_auto_249);
  tcase_add_test(tc_core, comparison_test_auto_250);
  tcase_add_test(tc_core, comparison_test_auto_251);
  tcase_add_test(tc_core, comparison_test_auto_252);
  tcase_add_test(tc_core, comparison_test_auto_253);
  tcase_add_test(tc_core, comparison_test_auto_254);
  tcase_add_test(tc_core, comparison_test_auto_255);
  tcase_add_test(tc_core, comparison_test_auto_256);
  tcase_add_test(tc_core, comparison_test_auto_257);
  tcase_add_test(tc_core, comparison_test_auto_258);
  tcase_add_test(tc_core, comparison_test_auto_259);
  tcase_add_test(tc_core, comparison_test_auto_260);
  tcase_add_test(tc_core, comparison_test_auto_261);
  tcase_add_test(tc_core, comparison_test_auto_262);
  tcase_add_test(tc_core, comparison_test_auto_263);
  tcase_add_test(tc_core, comparison_test_auto_264);
  tcase_add_test(tc_core, comparison_test_auto_265);
  tcase_add_test(tc_core, comparison_test_auto_266);
  tcase_add_test(tc_core, comparison_test_auto_267);
  tcase_add_test(tc_core, comparison_test_auto_268);
  tcase_add_test(tc_core, comparison_test_auto_269);
  tcase_add_test(tc_core, comparison_test_auto_270);
  tcase_add_test(tc_core, comparison_test_auto_271);
  tcase_add_test(tc_core, comparison_test_auto_272);
  tcase_add_test(tc_core, comparison_test_auto_273);
  tcase_add_test(tc_core, comparison_test_auto_274);
  tcase_add_test(tc_core, comparison_test_auto_275);
  tcase_add_test(tc_core, comparison_test_auto_276);
  tcase_add_test(tc_core, comparison_test_auto_277);
  tcase_add_test(tc_core, comparison_test_auto_278);
  tcase_add_test(tc_core, comparison_test_auto_279);
  tcase_add_test(tc_core, comparison_test_auto_280);
  tcase_add_test(tc_core, comparison_test_auto_281);
  tcase_add_test(tc_core, comparison_test_auto_282);
  tcase_add_test(tc_core, comparison_test_auto_283);
  tcase_add_test(tc_core, comparison_test_auto_284);
  tcase_add_test(tc_core, comparison_test_auto_285);
  tcase_add_test(tc_core, comparison_test_auto_286);
  tcase_add_test(tc_core, comparison_test_auto_287);
  tcase_add_test(tc_core, comparison_test_auto_288);
  tcase_add_test(tc_core, comparison_test_auto_289);
  tcase_add_test(tc_core, comparison_test_auto_290);
  tcase_add_test(tc_core, comparison_test_auto_291);
  tcase_add_test(tc_core, comparison_test_auto_292);
  tcase_add_test(tc_core, comparison_test_auto_293);
  tcase_add_test(tc_core, comparison_test_auto_294);
  tcase_add_test(tc_core, comparison_test_auto_295);
  tcase_add_test(tc_core, comparison_test_auto_296);
  tcase_add_test(tc_core, comparison_test_auto_297);
  tcase_add_test(tc_core, comparison_test_auto_298);
  tcase_add_test(tc_core, comparison_test_auto_299);
  tcase_add_test(tc_core, comparison_test_auto_300);
  tcase_add_test(tc_core, comparison_test_auto_301);
  tcase_add_test(tc_core, comparison_test_auto_302);
  tcase_add_test(tc_core, comparison_test_auto_303);
  tcase_add_test(tc_core, comparison_test_auto_304);
  tcase_add_test(tc_core, comparison_test_auto_305);
  tcase_add_test(tc_core, comparison_test_auto_306);
  tcase_add_test(tc_core, comparison_test_auto_307);
  tcase_add_test(tc_core, comparison_test_auto_308);
  tcase_add_test(tc_core, comparison_test_auto_309);
  tcase_add_test(tc_core, comparison_test_auto_310);
  tcase_add_test(tc_core, comparison_test_auto_311);
  tcase_add_test(tc_core, comparison_test_auto_312);
  tcase_add_test(tc_core, comparison_test_auto_313);
  tcase_add_test(tc_core, comparison_test_auto_314);
  tcase_add_test(tc_core, comparison_test_auto_315);
  tcase_add_test(tc_core, comparison_test_auto_316);
  tcase_add_test(tc_core, comparison_test_auto_317);
  tcase_add_test(tc_core, comparison_test_auto_318);
  tcase_add_test(tc_core, comparison_test_auto_319);
  tcase_add_test(tc_core, comparison_test_auto_320);
  tcase_add_test(tc_core, comparison_test_auto_321);
  tcase_add_test(tc_core, comparison_test_auto_322);
  tcase_add_test(tc_core, comparison_test_auto_323);
  tcase_add_test(tc_core, comparison_test_auto_324);
  tcase_add_test(tc_core, comparison_test_auto_325);
  tcase_add_test(tc_core, comparison_test_auto_326);
  tcase_add_test(tc_core, comparison_test_auto_327);
  tcase_add_test(tc_core, comparison_test_auto_328);
  tcase_add_test(tc_core, comparison_test_auto_329);
  tcase_add_test(tc_core, comparison_test_auto_330);
  tcase_add_test(tc_core, comparison_test_auto_331);
  tcase_add_test(tc_core, comparison_test_auto_332);
  tcase_add_test(tc_core, comparison_test_auto_333);
  tcase_add_test(tc_core, comparison_test_auto_334);
  tcase_add_test(tc_core, comparison_test_auto_335);
  tcase_add_test(tc_core, comparison_test_auto_336);
  tcase_add_test(tc_core, comparison_test_auto_337);
  tcase_add_test(tc_core, comparison_test_auto_338);
  tcase_add_test(tc_core, comparison_test_auto_339);
  tcase_add_test(tc_core, comparison_test_auto_340);
  tcase_add_test(tc_core, comparison_test_auto_341);
  tcase_add_test(tc_core, comparison_test_auto_342);
  tcase_add_test(tc_core, comparison_test_auto_343);
  tcase_add_test(tc_core, comparison_test_auto_344);
  tcase_add_test(tc_core, comparison_test_auto_345);
  tcase_add_test(tc_core, comparison_test_auto_346);
  tcase_add_test(tc_core, comparison_test_auto_347);
  tcase_add_test(tc_core, comparison_test_auto_348);
  tcase_add_test(tc_core, comparison_test_auto_349);
  tcase_add_test(tc_core, comparison_test_auto_350);
  tcase_add_test(tc_core, comparison_test_auto_351);
  tcase_add_test(tc_core, comparison_test_auto_352);
  tcase_add_test(tc_core, comparison_test_auto_353);
  tcase_add_test(tc_core, comparison_test_auto_354);
  tcase_add_test(tc_core, comparison_test_auto_355);
  tcase_add_test(tc_core, comparison_test_auto_356);
  tcase_add_test(tc_core, comparison_test_auto_357);
  tcase_add_test(tc_core, comparison_test_auto_358);
  tcase_add_test(tc_core, comparison_test_auto_359);
  tcase_add_test(tc_core, comparison_test_auto_360);
  tcase_add_test(tc_core, comparison_test_auto_361);
  tcase_add_test(tc_core, comparison_test_auto_362);
  tcase_add_test(tc_core, comparison_test_auto_363);
  tcase_add_test(tc_core, comparison_test_auto_364);
  tcase_add_test(tc_core, comparison_test_auto_365);
  tcase_add_test(tc_core, comparison_test_auto_366);
  tcase_add_test(tc_core, comparison_test_auto_367);
  tcase_add_test(tc_core, comparison_test_auto_368);
  tcase_add_test(tc_core, comparison_test_auto_369);
  tcase_add_test(tc_core, comparison_test_auto_370);
  tcase_add_test(tc_core, comparison_test_auto_371);
  tcase_add_test(tc_core, comparison_test_auto_372);
  tcase_add_test(tc_core, comparison_test_auto_373);
  tcase_add_test(tc_core, comparison_test_auto_374);
  tcase_add_test(tc_core, comparison_test_auto_375);
  tcase_add_test(tc_core, comparison_test_auto_376);
  tcase_add_test(tc_core, comparison_test_auto_377);
  tcase_add_test(tc_core, comparison_test_auto_378);
  tcase_add_test(tc_core, comparison_test_auto_379);
  tcase_add_test(tc_core, comparison_test_auto_380);
  tcase_add_test(tc_core, comparison_test_auto_381);
  tcase_add_test(tc_core, comparison_test_auto_382);
  tcase_add_test(tc_core, comparison_test_auto_383);
  tcase_add_test(tc_core, comparison_test_auto_384);
  tcase_add_test(tc_core, comparison_test_auto_385);
  tcase_add_test(tc_core, comparison_test_auto_386);
  tcase_add_test(tc_core, comparison_test_auto_387);
  tcase_add_test(tc_core, comparison_test_auto_388);
  tcase_add_test(tc_core, comparison_test_auto_389);
  tcase_add_test(tc_core, comparison_test_auto_390);
  tcase_add_test(tc_core, comparison_test_auto_391);
  tcase_add_test(tc_core, comparison_test_auto_392);
  tcase_add_test(tc_core, comparison_test_auto_393);
  tcase_add_test(tc_core, comparison_test_auto_394);
  tcase_add_test(tc_core, comparison_test_auto_395);
  tcase_add_test(tc_core, comparison_test_auto_396);
  tcase_add_test(tc_core, comparison_test_auto_397);
  tcase_add_test(tc_core, comparison_test_auto_398);
  tcase_add_test(tc_core, comparison_test_auto_399);
  tcase_add_test(tc_core, comparison_test_auto_400);
  tcase_add_test(tc_core, comparison_test_auto_401);
  tcase_add_test(tc_core, comparison_test_auto_402);
  tcase_add_test(tc_core, comparison_test_auto_403);
  tcase_add_test(tc_core, comparison_test_auto_404);
  tcase_add_test(tc_core, comparison_test_auto_405);
  tcase_add_test(tc_core, comparison_test_auto_406);
  tcase_add_test(tc_core, comparison_test_auto_407);
  tcase_add_test(tc_core, comparison_test_auto_408);
  tcase_add_test(tc_core, comparison_test_auto_409);
  tcase_add_test(tc_core, comparison_test_auto_410);
  tcase_add_test(tc_core, comparison_test_auto_411);
  tcase_add_test(tc_core, comparison_test_auto_412);
  tcase_add_test(tc_core, comparison_test_auto_413);
  tcase_add_test(tc_core, comparison_test_auto_414);
  tcase_add_test(tc_core, comparison_test_auto_415);
  tcase_add_test(tc_core, comparison_test_auto_416);
  tcase_add_test(tc_core, comparison_test_auto_417);
  tcase_add_test(tc_core, comparison_test_auto_418);
  tcase_add_test(tc_core, comparison_test_auto_419);
  tcase_add_test(tc_core, comparison_test_auto_420);
  tcase_add_test(tc_core, comparison_test_auto_421);
  tcase_add_test(tc_core, comparison_test_auto_422);
  tcase_add_test(tc_core, comparison_test_auto_423);
  tcase_add_test(tc_core, comparison_test_auto_424);
  tcase_add_test(tc_core, comparison_test_auto_425);
  tcase_add_test(tc_core, comparison_test_auto_426);
  tcase_add_test(tc_core, comparison_test_auto_427);
  tcase_add_test(tc_core, comparison_test_auto_428);
  tcase_add_test(tc_core, comparison_test_auto_429);
  tcase_add_test(tc_core, comparison_test_auto_430);
  tcase_add_test(tc_core, comparison_test_auto_431);
  tcase_add_test(tc_core, comparison_test_auto_432);
  tcase_add_test(tc_core, comparison_test_auto_433);
  tcase_add_test(tc_core, comparison_test_auto_434);
  tcase_add_test(tc_core, comparison_test_auto_435);
  tcase_add_test(tc_core, comparison_test_auto_436);
  tcase_add_test(tc_core, comparison_test_auto_437);
  tcase_add_test(tc_core, comparison_test_auto_438);
  tcase_add_test(tc_core, comparison_test_auto_439);
  tcase_add_test(tc_core, comparison_test_auto_440);
  tcase_add_test(tc_core, comparison_test_auto_441);
  tcase_add_test(tc_core, comparison_test_auto_442);
  tcase_add_test(tc_core, comparison_test_auto_443);
  tcase_add_test(tc_core, comparison_test_auto_444);
  tcase_add_test(tc_core, comparison_test_auto_445);
  tcase_add_test(tc_core, comparison_test_auto_446);
  tcase_add_test(tc_core, comparison_test_auto_447);
  tcase_add_test(tc_core, comparison_test_auto_448);
  tcase_add_test(tc_core, comparison_test_auto_449);
  tcase_add_test(tc_core, comparison_test_auto_450);
  tcase_add_test(tc_core, comparison_test_auto_451);
  tcase_add_test(tc_core, comparison_test_auto_452);
  tcase_add_test(tc_core, comparison_test_auto_453);
  tcase_add_test(tc_core, comparison_test_auto_454);
  tcase_add_test(tc_core, comparison_test_auto_455);
  tcase_add_test(tc_core, comparison_test_auto_456);
  tcase_add_test(tc_core, comparison_test_auto_457);
  tcase_add_test(tc_core, comparison_test_auto_458);
  tcase_add_test(tc_core, comparison_test_auto_459);
  tcase_add_test(tc_core, comparison_test_auto_460);
  tcase_add_test(tc_core, comparison_test_auto_461);
  tcase_add_test(tc_core, comparison_test_auto_462);
  tcase_add_test(tc_core, comparison_test_auto_463);
  tcase_add_test(tc_core, comparison_test_auto_464);
  tcase_add_test(tc_core, comparison_test_auto_465);
  tcase_add_test(tc_core, comparison_test_auto_466);
  tcase_add_test(tc_core, comparison_test_auto_467);
  tcase_add_test(tc_core, comparison_test_auto_468);
  tcase_add_test(tc_core, comparison_test_auto_469);
  tcase_add_test(tc_core, comparison_test_auto_470);
  tcase_add_test(tc_core, comparison_test_auto_471);
  tcase_add_test(tc_core, comparison_test_auto_472);
  tcase_add_test(tc_core, comparison_test_auto_473);
  tcase_add_test(tc_core, comparison_test_auto_474);
  tcase_add_test(tc_core, comparison_test_auto_475);
  tcase_add_test(tc_core, comparison_test_auto_476);
  tcase_add_test(tc_core, comparison_test_auto_477);
  tcase_add_test(tc_core, comparison_test_auto_478);
  tcase_add_test(tc_core, comparison_test_auto_479);
  tcase_add_test(tc_core, comparison_test_auto_480);
  tcase_add_test(tc_core, comparison_test_auto_481);
  tcase_add_test(tc_core, comparison_test_auto_482);
  tcase_add_test(tc_core, comparison_test_auto_483);
  tcase_add_test(tc_core, comparison_test_auto_484);
  tcase_add_test(tc_core, comparison_test_auto_485);
  tcase_add_test(tc_core, comparison_test_auto_486);
  tcase_add_test(tc_core, comparison_test_auto_487);
  tcase_add_test(tc_core, comparison_test_auto_488);
  tcase_add_test(tc_core, comparison_test_auto_489);
  tcase_add_test(tc_core, comparison_test_auto_490);
  tcase_add_test(tc_core, comparison_test_auto_491);
  tcase_add_test(tc_core, comparison_test_auto_492);
  tcase_add_test(tc_core, comparison_test_auto_493);
  tcase_add_test(tc_core, comparison_test_auto_494);
  tcase_add_test(tc_core, comparison_test_auto_495);
  tcase_add_test(tc_core, comparison_test_auto_496);
  tcase_add_test(tc_core, comparison_test_auto_497);
  tcase_add_test(tc_core, comparison_test_auto_498);
  tcase_add_test(tc_core, comparison_test_auto_499);
  tcase_add_test(tc_core, comparison_test_auto_500);
  tcase_add_test(tc_core, comparison_test_auto_501);
  tcase_add_test(tc_core, comparison_test_auto_502);
  tcase_add_test(tc_core, comparison_test_auto_503);
  tcase_add_test(tc_core, comparison_test_auto_504);
  tcase_add_test(tc_core, comparison_test_auto_505);
  tcase_add_test(tc_core, comparison_test_auto_506);
  tcase_add_test(tc_core, comparison_test_auto_507);
  tcase_add_test(tc_core, comparison_test_auto_508);
  tcase_add_test(tc_core, comparison_test_auto_509);
  tcase_add_test(tc_core, comparison_test_auto_510);
  tcase_add_test(tc_core, comparison_test_auto_511);
  tcase_add_test(tc_core, comparison_test_auto_512);
  tcase_add_test(tc_core, comparison_test_auto_513);
  tcase_add_test(tc_core, comparison_test_auto_514);
  tcase_add_test(tc_core, comparison_test_auto_515);
  tcase_add_test(tc_core, comparison_test_auto_516);
  tcase_add_test(tc_core, comparison_test_auto_517);
  tcase_add_test(tc_core, comparison_test_auto_518);
  tcase_add_test(tc_core, comparison_test_auto_519);
  tcase_add_test(tc_core, comparison_test_auto_520);
  tcase_add_test(tc_core, comparison_test_auto_521);
  tcase_add_test(tc_core, comparison_test_auto_522);
  tcase_add_test(tc_core, comparison_test_auto_523);
  tcase_add_test(tc_core, comparison_test_auto_524);
  tcase_add_test(tc_core, comparison_test_auto_525);
  tcase_add_test(tc_core, comparison_test_auto_526);
  tcase_add_test(tc_core, comparison_test_auto_527);
  tcase_add_test(tc_core, comparison_test_auto_528);
  tcase_add_test(tc_core, comparison_test_auto_529);
  tcase_add_test(tc_core, comparison_test_auto_530);
  tcase_add_test(tc_core, comparison_test_auto_531);
  tcase_add_test(tc_core, comparison_test_auto_532);
  tcase_add_test(tc_core, comparison_test_auto_533);
  tcase_add_test(tc_core, comparison_test_auto_534);
  tcase_add_test(tc_core, comparison_test_auto_535);
  tcase_add_test(tc_core, comparison_test_auto_536);
  tcase_add_test(tc_core, comparison_test_auto_537);
  tcase_add_test(tc_core, comparison_test_auto_538);
  tcase_add_test(tc_core, comparison_test_auto_539);
  tcase_add_test(tc_core, comparison_test_auto_540);
  tcase_add_test(tc_core, comparison_test_auto_541);
  tcase_add_test(tc_core, comparison_test_auto_542);
  tcase_add_test(tc_core, comparison_test_auto_543);
  tcase_add_test(tc_core, comparison_test_auto_544);
  tcase_add_test(tc_core, comparison_test_auto_545);
  tcase_add_test(tc_core, comparison_test_auto_546);
  tcase_add_test(tc_core, comparison_test_auto_547);
  tcase_add_test(tc_core, comparison_test_auto_548);
  tcase_add_test(tc_core, comparison_test_auto_549);
  tcase_add_test(tc_core, comparison_test_auto_550);
  tcase_add_test(tc_core, comparison_test_auto_551);

  suite_add_tcase(is_equal_suite, tc_core);
  return is_equal_suite;
}