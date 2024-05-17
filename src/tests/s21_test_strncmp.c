#include <check.h>

#include "s21_test.h"

START_TEST(s21_strncmp_test_is_normal) {
  // Arrange
  char str1[20] = "1234567890";
  char str2[20] = "1234567890";
  char *result1 = "";
  char *result2 = "";
  // Act
  int expected = strncmp(str1, str2, 5);
  int result = s21_strncmp(str1, str2, 5);

  // Assert
  if (expected == 0) {
    result1 = "str1 = str2";
  }
  if (result == 0) {
    result2 = "str1 = str2";
  }
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncmp_test_is_neg) {
  // Arrange
  char str1[20] = "123";
  char str2[20] = "1234567890";
  char *result1 = "";
  char *result2 = "";

  // Act
  int expected = strncmp(str1, str2, 5);
  int result = s21_strncmp(str1, str2, 5);

  // Assert
  if (expected < 0) {
    result1 = "str1 < str2";
  }
  if (result < 0) {
    result2 = "str1 < str2";
  }
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncmp_test_is_pos) {
  // Arrange
  char str1[20] = "1234567890";
  char str2[20] = "1234";
  char *result1 = "";
  char *result2 = "";
  // Act
  int expected = strncmp(str1, str2, 5);
  int result = s21_strncmp(str1, str2, 5);

  // Assert
  if (expected > 0) {
    result1 = "str1 > str2";
  }
  if (result > 0) {
    result2 = "str1 > str2";
  }
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncmp_test_is_null) {
  // Arrange
  char str1[20] = "1234567890";
  char str2[20] = "1234567890";

  // Act
  int expected = strncmp(str1, str2, 0);
  int result = s21_strncmp(str1, str2, 0);

  // Assert
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *suite;
  TCase *tc_strncmp_test_is_normal, *tc_strncmp_test_is_null,
      *tc_strncmp_test_is_neg, *tc_strncmp_test_is_pos;
  suite = suite_create("s21_strncmp");

  tc_strncmp_test_is_normal = tcase_create("s21_strncmp_test_is_normal");
  tcase_add_test(tc_strncmp_test_is_normal, s21_strncmp_test_is_normal);
  suite_add_tcase(suite, tc_strncmp_test_is_normal);

  tc_strncmp_test_is_neg = tcase_create("s21_strncmp_test_is_neg");
  tcase_add_test(tc_strncmp_test_is_neg, s21_strncmp_test_is_neg);
  suite_add_tcase(suite, tc_strncmp_test_is_neg);

  tc_strncmp_test_is_pos = tcase_create("s21_strncmp_test_is_pos");
  tcase_add_test(tc_strncmp_test_is_pos, s21_strncmp_test_is_pos);
  suite_add_tcase(suite, tc_strncmp_test_is_pos);

  tc_strncmp_test_is_null = tcase_create("s21_strncmp_test_is_null");
  tcase_add_test(tc_strncmp_test_is_null, s21_strncmp_test_is_null);
  suite_add_tcase(suite, tc_strncmp_test_is_null);

  return suite;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fail = 0;
  case_test(s21_strncmp_suite(), &fail);
  return 0;
}