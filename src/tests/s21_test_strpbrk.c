#include <check.h>

#include "s21_test.h"

START_TEST(s21_strpbrk_test_is_normal) {
  char str[20] = "Hello World!";
  char sym[20] = "W";

  char *findSym = s21_strpbrk(str, sym);
  char *findSym2 = strpbrk(str, sym);

  ck_assert_int_eq(findSym - str + 1, findSym2 - str + 1);
}
END_TEST

START_TEST(s21_strpbrk_test_is_null) {
  char str[20] = "Hello World!";
  char sym[20] = "W";

  char *findSym = s21_strpbrk(str, sym);
  char *findSym2 = strpbrk(str, sym);

  ck_assert_str_eq(findSym, findSym2);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *suite;
  TCase *tc_strpbrk_test_is_normal, *tc_strpbrk_test_is_null;
  suite = suite_create("s21_strncpy");

  tc_strpbrk_test_is_normal = tcase_create("s21_strpbrk_test_is_normal");
  tcase_add_test(tc_strpbrk_test_is_normal, s21_strpbrk_test_is_normal);
  suite_add_tcase(suite, tc_strpbrk_test_is_normal);

  tc_strpbrk_test_is_null = tcase_create("s21_strpbrk_test_is_null");
  tcase_add_test(tc_strpbrk_test_is_null, s21_strpbrk_test_is_null);
  suite_add_tcase(suite, tc_strpbrk_test_is_null);

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
  case_test(s21_strpbrk_suite(), &fail);
  return 0;
}