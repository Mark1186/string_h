#include "s21_test.h"

START_TEST(s21_trim_test) {
    char *trimmed_str;
    char *str_to_trim = " \n   Hello, world!  !\n";
    trimmed_str = s21_trim(str_to_trim, " H!\nd");
    if (trimmed_str) {
        ck_assert_str_eq(trimmed_str, "ello, worl");
        free(trimmed_str);
    }

    char *empty_str = "";
    trimmed_str = s21_trim(empty_str, s21_NULL);
    if (trimmed_str) {
        ck_assert_str_eq(trimmed_str, "");
        free(trimmed_str);
    }

    trimmed_str = s21_trim(empty_str, " \n\0");
    if (trimmed_str) {
        ck_assert_str_eq(trimmed_str, "");
        free(trimmed_str);
    }

    char *empty_format = "";
    trimmed_str = s21_trim(str_to_trim, empty_format);
    if (trimmed_str) {
        ck_assert_str_eq(trimmed_str, "Hello, world!  !");
        free(trimmed_str);
    }

    trimmed_str = s21_trim(s21_NULL, empty_format);
    ck_assert(trimmed_str == s21_NULL);

    char *str_to_trim2 = "xxx Hello, world! xxx ---";
    char *format_str = "x -";
    trimmed_str = s21_trim(str_to_trim2, format_str);
    if (trimmed_str) {
        ck_assert_str_eq(trimmed_str, "Hello, world!");
        free(trimmed_str);
    }
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite;
  TCase *tc_trim_test;

  suite = suite_create("s21_trim");

  tc_trim_test = tcase_create("s21_trim_test");
  tcase_add_test(tc_trim_test, s21_trim_test);
  suite_add_tcase(suite, tc_trim_test);

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
  case_test(s21_trim_suite(), &fail);
  return 0;
}