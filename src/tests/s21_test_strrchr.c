#include <check.h>

#include "s21_test.h"

START_TEST(s21_strrchr_test_is_normal) {
    char *str = "Hello World!";
    ck_assert_str_eq(s21_strrchr(str, 'W'), strrchr(str, 'W'));
}

END_TEST

START_TEST(s21_strrchr_test_is_null) {
    char *str = "Hello World!";
    ck_assert_ptr_eq(s21_strchr(str, 'j'), strchr(str, 'j'));
}

END_TEST

START_TEST(s21_strrchr_test) {
    char test1[] = "0163456769\0";
    char test2[] = ";;;;;;H%%//#HH\0";
    char test3[] = "     /\0";
    ck_assert_uint_eq((unsigned long) s21_strrchr(test1, '6'),
                      (unsigned long) strrchr(test1, '6'));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test1, ' '),
                      (unsigned long) strrchr(test1, ' '));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test1, '6'),
                      (unsigned long) strrchr(test1, '6'));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test2, 'H'),
                      (unsigned long) strrchr(test2, 'H'));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test2, '$'),
                      (unsigned long) strrchr(test2, '$'));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test2, ';'),
                      (unsigned long) strrchr(test2, ';'));
    ck_assert_uint_eq((unsigned long) s21_strrchr(test3, ' '),
                      (unsigned long) strrchr(test3, ' '));
    ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}

END_TEST

Suite *s21_strrchr_suite(void) {
    Suite *suite;
    TCase *tc_strrchr_test_is_normal, *tc_strrchr_test_is_null, *tc_strrchr_test;

    suite = suite_create("s21_strrchr");

    tc_strrchr_test_is_normal = tcase_create("s21_strrchr_test_is_normal");
    tcase_add_test(tc_strrchr_test_is_normal, s21_strrchr_test_is_normal);
    suite_add_tcase(suite, tc_strrchr_test_is_normal);

    tc_strrchr_test_is_null = tcase_create("s21_strrchr_test_is_null");
    tcase_add_test(tc_strrchr_test_is_null, s21_strrchr_test_is_null);
    suite_add_tcase(suite, tc_strrchr_test_is_null);

    tc_strrchr_test = tcase_create("s21_strrchr_test");
    tcase_add_test(tc_strrchr_test, s21_strrchr_test);
    suite_add_tcase(suite, tc_strrchr_test);

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
    case_test(s21_strrchr_suite(), &fail);
}