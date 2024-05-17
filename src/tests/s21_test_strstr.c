#include <check.h>

#include "s21_test.h"

START_TEST(s21_strstr_test_is_normal) {
  const char *str = "Hello World";
  const char *substr = "World";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_test_is_null) {
  const char *str = "Nater s ladoshok";
  const char *substr = "Ruchnichek";
  ck_assert_ptr_eq(s21_strstr(str, substr), strstr(str, substr));
}END_TEST

START_TEST(s21_strstr_test) {
    char test_1[] = "<<<5>>>";
    char test_2[] = "5";
    char test_3[] = "QwertyQwertyQwerty";
    char test_4[] = "Qwerty";
    char test_5[] = "abcd";
    char test_6[] = "";
    char test_7[] = "aaaaa123aaa1234aaa";
    char test_8[] = "1234";

    ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
    ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
    ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
    ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
    ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
} END_TEST

Suite *s21_strstr_suite(void) {
  Suite *suite;
  TCase *tc_strstr_test_is_normal, *tc_strstr_test_is_null, *tc_strstr_test;

  suite = suite_create("s21_strstr");

  tc_strstr_test_is_normal = tcase_create("s21_strstr_test_is_normal");
  tcase_add_test(tc_strstr_test_is_normal, s21_strstr_test_is_normal);
  suite_add_tcase(suite, tc_strstr_test_is_normal);

  tc_strstr_test_is_null = tcase_create("s21_strstr_test_is_null");
  tcase_add_test(tc_strstr_test_is_null, s21_strstr_test_is_null);
  suite_add_tcase(suite, tc_strstr_test_is_null);

    tc_strstr_test = tcase_create("s21_strstr_test");
    tcase_add_test(tc_strstr_test, s21_strstr_test);
    suite_add_tcase(suite, tc_strstr_test);

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
  case_test(s21_strstr_suite(), &fail);
  return 0;
}