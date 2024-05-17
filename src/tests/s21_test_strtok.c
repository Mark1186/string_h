#include <check.h>

#include "s21_test.h"

START_TEST(s21_strtok_test_is_normal) {
    char str[] = "- Voice une phrase avec quelques separate ! -";
    const char delim[] = " ,.-!";
    char *s21_strToken = s21_strtok(str, delim);
    char *strToken = strtok(str, delim);

    ck_assert_str_eq(s21_strToken, strToken);
}

END_TEST
START_TEST(s21_strtok_test_is_null) {
    char *str = "";
    const char delim[] = " ,.-!";
    char *s21_strToken = s21_strtok(str, delim);
    char *strToken = strtok(str, delim);
    ck_assert_ptr_eq(s21_strToken, strToken);
}

END_TEST


START_TEST(s21_strtok_test) {
    char str_strtok1[] = "one/two/three(four)five";
    char delim1[] = "/()";

    char str_strtok2[] = "one/two/three(four)five";
    char delim2[] = "/()";
    char *my_strtok = s21_strtok(str_strtok1, delim1);
    char *origin_strtok = strtok(str_strtok2, delim2);
    while (my_strtok != s21_NULL) {
        ck_assert_str_eq(my_strtok, origin_strtok);
        my_strtok = s21_strtok(s21_NULL, delim1);
        origin_strtok = strtok(s21_NULL, delim2);
    }
}

END_TEST

Suite *s21_strtok_suite(void) {
    Suite *suite;
    TCase *tc_strtok_test_is_normal, *tc_strtok_test_is_null, *tc_strtok_test;

    suite = suite_create("s21_strtok");

    tc_strtok_test_is_normal = tcase_create("s21_strtok_test_is_normal");
    tcase_add_test(tc_strtok_test_is_normal, s21_strtok_test_is_normal);
    suite_add_tcase(suite, tc_strtok_test_is_normal);

    tc_strtok_test_is_null = tcase_create("s21_strtok_test_is_null");
    tcase_add_test(tc_strtok_test_is_null, s21_strtok_test_is_null);
    suite_add_tcase(suite, tc_strtok_test_is_null);

    tc_strtok_test = tcase_create("s21_strtok_test");
    tcase_add_test(tc_strtok_test, s21_strtok_test);
    suite_add_tcase(suite, tc_strtok_test);

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
    case_test(s21_strtok_suite(), &fail);
    return 0;
}