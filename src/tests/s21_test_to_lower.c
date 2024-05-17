#include "s21_test.h"

START_TEST(s21_tolower_test_is_normal) {
  char *text = "HeLLO wOrld";
  char *expected = "hello world";

  char *str = (char *)s21_to_lower(text);

  ck_assert_str_eq(str, expected);
  free(str);
}

END_TEST

Suite *s21_tolower_suite(void) {
  Suite *suite;
  TCase *tc_tolower_test_is_normal;

  suite = suite_create("s21_tolower");

  tc_tolower_test_is_normal = tcase_create("s21_tolower_test_is_normal");
  tcase_add_test(tc_tolower_test_is_normal, s21_tolower_test_is_normal);
  suite_add_tcase(suite, tc_tolower_test_is_normal);

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
  case_test(s21_tolower_suite(), &fail);
  return 0;
}