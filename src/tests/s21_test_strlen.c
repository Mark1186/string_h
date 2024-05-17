#include <check.h>

#include "s21_test.h"

START_TEST(s21_strlen_test_is_normal) {
  const char *str = "Hello World";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *suite;
  TCase *tc_strlen_test_is_normal;
  suite = suite_create("s21_strlen");
  tc_strlen_test_is_normal = tcase_create("s21_strlen_test_is_normal");
  tcase_add_test(tc_strlen_test_is_normal, s21_strlen_test_is_normal);
  suite_add_tcase(suite, tc_strlen_test_is_normal);
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
  case_test(s21_strlen_suite(), &fail);

  return 0;
}