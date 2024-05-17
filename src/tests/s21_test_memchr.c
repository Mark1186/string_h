#include <check.h>

#include "s21_test.h"

START_TEST(s21_memchr_is_correct) {
  const char *str = "Hello World";
  ck_assert_str_eq(s21_memchr(str, 'W', strlen(str)),
                   memchr(str, 'W', s21_strlen(str)));
}
END_TEST

START_TEST(s21_memchr_is_nan) {
  const char *str = "Hello World";
  ck_assert_ptr_eq(s21_memchr(str, 'j', s21_strlen(str)),
                   memchr(str, 'j', s21_strlen(str)));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *suite;
  TCase *tc_memchr_is_correct, *tc_memchr_is_nan;

  suite = suite_create("s21_memchr");

  tc_memchr_is_correct = tcase_create("s21_memchr_is_correct");
  tcase_add_test(tc_memchr_is_correct, s21_memchr_is_correct);
  suite_add_tcase(suite, tc_memchr_is_correct);

  tc_memchr_is_nan = tcase_create("s21_memchr_is_nan");
  tcase_add_test(tc_memchr_is_nan, s21_memchr_is_nan);
  suite_add_tcase(suite, tc_memchr_is_nan);

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
  case_test(s21_memchr_suite(), &fail);
}