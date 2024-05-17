#include <check.h>

#include "s21_test.h"

START_TEST(s21_strncat_test_is_normal) {
  char str1[10] = "000";
  char str2[10] = "000";
  char add_str[10] = "12345";

  s21_strncat(str1, add_str, 3);
  strncat(str2, add_str, 3);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncat_test_is_null) {
  char str1[10] = "";
  char str2[10] = "";
  char add_str[10] = "12345";

  s21_strncat(str1, add_str, 3);
  strncat(str2, add_str, 3);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *suite;
  TCase *tc_strncat_test_is_normal, *tc_strncat_test_is_null;
  suite = suite_create("s21_strncat");

  tc_strncat_test_is_normal = tcase_create("s21_strncat_test_is_normal");
  tcase_add_test(tc_strncat_test_is_normal, s21_strncat_test_is_normal);
  suite_add_tcase(suite, tc_strncat_test_is_normal);

  tc_strncat_test_is_null = tcase_create("s21_strncat_test_is_null");
  tcase_add_test(tc_strncat_test_is_null, s21_strncat_test_is_null);
  suite_add_tcase(suite, tc_strncat_test_is_null);

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
  case_test(s21_strncat_suite(), &fail);
  return 0;
}