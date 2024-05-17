#include "s21_test.h"

START_TEST(s21_insert_test) {
    char *src = "Hello!";
    char *str = ", world";
    char *new_str = s21_insert(src, str, 5);
    if (new_str) {
        ck_assert_str_eq(new_str, "Hello, world!");
        free(new_str);
    }

    new_str = s21_insert(src, "", 15);
    ck_assert(new_str == s21_NULL);

    new_str = s21_insert("Hello!", ", world!!", 5);
    if (new_str) {
        ck_assert_str_eq(new_str, "Hello, world!!!");
        free(new_str);
    }

    new_str = s21_insert("Hello!", ", world!!", 10);
    if (new_str) {
        ck_assert_str_eq(new_str, "Hello!");
        free(new_str);
    }

    new_str = s21_insert("Hello!", ", world!!", 25);
    ck_assert(new_str == s21_NULL);

    new_str = s21_insert("", "", 0);
    if (new_str) {
        ck_assert_str_eq(new_str, "");
        free(new_str);
    }
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *suite;
  TCase *tc_insert_test;

  suite = suite_create("s21_insert");

  tc_insert_test = tcase_create("s21_insert_test");
  tcase_add_test(tc_insert_test, s21_insert_test);
  suite_add_tcase(suite, tc_insert_test);

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
  case_test(s21_insert_suite(), &fail);
  return 0;
}