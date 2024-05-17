#include <check.h>

#include "s21_test.h"

START_TEST(s21_strchr_test_is_normal) {
    const char *str = "Hello World";
    ck_assert_str_eq(s21_strchr(str, 'W'), strchr(str, 'W'));
}

END_TEST

START_TEST(s21_strchr_test_is_nan) {
    const char *str = "Hello World";
    ck_assert_ptr_eq(s21_strchr(str, 'j'), strchr(str, 'j'));
}

END_TEST

START_TEST(s21_strchr_test) {
    char str1[] = "Abcdefg";
    int symbol1 = 'd';
    char *ach1 = s21_strchr(str1, symbol1);
    ck_assert_str_eq(ach1, "defg");

    char str2[] = "Abcdefg";
    int symbol2 = 'd';
    char *ach2 = strchr(str2, symbol2);
    ck_assert_str_eq(ach1, ach2);
    ck_assert_str_eq(str1, str2);

    char str3[] = "Abcdefg";
    int symbol3 = '\0';
    char *ach3 = s21_strchr(str3, symbol3);

    char str4[] = "Abcdefg";
    int symbol4 = '\0';
    char *ach4 = strchr(str4, symbol4);
    ck_assert_str_eq(ach3, ach4);
    ck_assert_str_eq(str3, str4);
}
END_TEST

Suite *s21_strchr_suite(void) {
    Suite *suite;
    TCase *tc_strchr_test_is_normal, *tc_strchr_test_is_nan, *tc_strchr_test;

    suite = suite_create("s21_strchr");

    tc_strchr_test_is_normal = tcase_create("s21_strchr_is_normal");
    tcase_add_test(tc_strchr_test_is_normal, s21_strchr_test_is_normal);
    suite_add_tcase(suite, tc_strchr_test_is_normal);

    tc_strchr_test_is_nan = tcase_create("s21_strchr_is_nan");
    tcase_add_test(tc_strchr_test_is_nan, s21_strchr_test_is_nan);
    suite_add_tcase(suite, tc_strchr_test_is_nan);

    tc_strchr_test = tcase_create("s21_strchr_test");
    tcase_add_test(tc_strchr_test, s21_strchr_test);
    suite_add_tcase(suite, tc_strchr_test);

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
    case_test(s21_strchr_suite(), &fail);
}