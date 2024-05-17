#include <check.h>

#include "s21_test.h"

START_TEST(s21_strncpy_test_is_normal) {
  char destination[20] = "";
  char source[20] = "Hello METANIT.COM!!";

  char *s21_strnCpy = s21_strncpy(destination, source, 20);
  char *strnCpy = strncpy(destination, source, 20);
  ck_assert_str_eq(s21_strnCpy, strnCpy);
}
END_TEST

START_TEST(s21_strncpy_test_is_null) {
  char destination[20] = "";
  char source[20] = "Hello METANIT\0.COM!!";

  char *s21_strnCpy = s21_strncpy(destination, source, 20);
  char *strnCpy = strncpy(destination, source, 20);
  ck_assert_str_eq(s21_strnCpy, strnCpy);
}

Suite *s21_strncpy_suite(void) {
  Suite *suite;
  TCase *tc_strncpy_test_is_normal, *tc_strncpy_test_is_null;
  suite = suite_create("s21_strncpy");

  tc_strncpy_test_is_normal = tcase_create("s21_strncpy_test_is_normal");
  tcase_add_test(tc_strncpy_test_is_normal, s21_strncpy_test_is_normal);
  suite_add_tcase(suite, tc_strncpy_test_is_normal);

  tc_strncpy_test_is_null = tcase_create("s21_strncpy_test_is_null");
  tcase_add_test(tc_strncpy_test_is_null, s21_strncpy_test_is_null);
  suite_add_tcase(suite, tc_strncpy_test_is_null);

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
  case_test(s21_strncpy_suite(), &fail);
  return 0;
}