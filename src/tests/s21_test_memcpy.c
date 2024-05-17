#include <check.h>

#include "s21_test.h"

START_TEST(s21_memcpy_test_is_normal) {
  char str1[12] = "Hello World";
  char dest1[12] = "";
  char dest2[12] = "";
  s21_memcpy(dest1, str1, 11);
  memcpy(dest2, str1, 11);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_is_null) {
  char str1[12] = "";
  char dest1[12] = "";
  char dest2[12] = "";
  s21_memcpy(dest1, str1, 11);
  memcpy(dest2, str1, 11);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *suite;
  TCase *tc_memcpy_test_is_normal, *tc_memcpy_test_is_null;

  suite = suite_create("s21_memcpy");

  tc_memcpy_test_is_normal = tcase_create("s21_memcpy_test_is_normal");
  tcase_add_test(tc_memcpy_test_is_normal, s21_memcpy_test_is_normal);
  suite_add_tcase(suite, tc_memcpy_test_is_normal);

  tc_memcpy_test_is_null = tcase_create("s21_memcpy_test_is_null");
  tcase_add_test(tc_memcpy_test_is_null, s21_memcpy_test_is_null);
  suite_add_tcase(suite, tc_memcpy_test_is_null);

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
  case_test(s21_memcpy_suite(), &fail);
  return 0;
}