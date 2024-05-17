#include <check.h>

#include "s21_test.h"

START_TEST(s21_memset_test_is_normal) {
  char str1[10] = "123456";
  char str2[10] = "123456";

  s21_memset(str1, '0', 4);
  memset(str2, '0', 4);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_is_null) {
  char str1[10] = "";
  char str2[10] = "";

  s21_memset(str1, '0', 4);
  memset(str2, '0', 4);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *suite;
  TCase *tc_memset_test_is_normal, *tc_memset_test_is_null;
  suite = suite_create("s21_memset");

  tc_memset_test_is_normal = tcase_create("s21_memset_test_is_normal");
  tcase_add_test(tc_memset_test_is_normal, s21_memset_test_is_normal);
  suite_add_tcase(suite, tc_memset_test_is_normal);

  tc_memset_test_is_null = tcase_create("s21_memset_test_is_null");
  tcase_add_test(tc_memset_test_is_null, s21_memset_test_is_null);
  suite_add_tcase(suite, tc_memset_test_is_null);

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
  case_test(s21_memset_suite(), &fail);
  return 0;
}