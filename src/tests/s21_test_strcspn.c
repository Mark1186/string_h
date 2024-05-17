#include <check.h>

#include "s21_test.h"

START_TEST(s21_strcspn_test_is_normal) {
  char str[10] = "123456789";
  char sym[10] = "9876";
  ck_assert_int_eq(s21_strcspn(str, sym), strcspn(str, sym));
}
END_TEST

START_TEST(s21_strcspn_test_is_null) {
  char str[10] = "";
  char sym[10] = "9876";
  ck_assert_int_eq(s21_strcspn(str, sym), strcspn(str, sym));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *suite;
  TCase *tc_strcspn_test_is_normal, *tc_strcspn_test_is_null;
  suite = suite_create("s21_strcspn");

  tc_strcspn_test_is_normal = tcase_create("s21_strcspn_test_is_normal");
  tcase_add_test(tc_strcspn_test_is_normal, s21_strcspn_test_is_normal);
  suite_add_tcase(suite, tc_strcspn_test_is_normal);

  tc_strcspn_test_is_null = tcase_create("s21_strcspn_test_is_null");
  tcase_add_test(tc_strcspn_test_is_null, s21_strcspn_test_is_null);
  suite_add_tcase(suite, tc_strcspn_test_is_null);

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
  case_test(s21_strcspn_suite(), &fail);
  return 0;
}