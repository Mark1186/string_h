#include <check.h>

#include "s21_test.h"

START_TEST(s21_memcmp_test_is_normal) {
  const char *str1 = "1234567890";
  const char *str2 = "1234567891";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_is_null) {
  const char *str1 = "";
  const char *str2 = "1234567891";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *suite;
  TCase *tc_memcmp_test_is_normal, *tc_memcmp_test_is_null;

  suite = suite_create("s21_memcmp");

  tc_memcmp_test_is_normal = tcase_create("s21_memcmp_test_is_normal");
  tcase_add_test(tc_memcmp_test_is_normal, s21_memcmp_test_is_normal);
  suite_add_tcase(suite, tc_memcmp_test_is_normal);

  tc_memcmp_test_is_null = tcase_create("s21_memcmp_test_is_null");
  tcase_add_test(tc_memcmp_test_is_null, s21_memcmp_test_is_null);
  suite_add_tcase(suite, tc_memcmp_test_is_null);

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
  case_test(s21_memcmp_suite(), &fail);
  return 0;
}