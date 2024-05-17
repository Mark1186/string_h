#include <check.h>

#include "s21_test.h"

START_TEST(s21_strerror_test_is_normal) {
  char *str21 = s21_strerror(100);
  char *str = strerror(100);
  ck_assert_str_eq(str, str21);
}
END_TEST

START_TEST(s21_strerror_test_out_of_range_pos) {
  char *str21 = s21_strerror(135);
  char *str = strerror(135);
  ck_assert_str_eq(str, str21);
}
END_TEST

START_TEST(s21_strerror_test_out_of_range_neg) {
  char *str21 = s21_strerror(-2);
  char *str = strerror(-2);
  ck_assert_str_eq(str21, str);
  free(str);
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *suite;
  TCase *tc_strerror_test_is_normal, *tc_strerror_test_out_of_range_pos,
      *tc_strerror_test_out_of_range_neg;
  suite = suite_create("s21_strerror");

  tc_strerror_test_is_normal = tcase_create("s21_strerror_test_is_normal");
  tcase_add_test(tc_strerror_test_is_normal, s21_strerror_test_is_normal);
  suite_add_tcase(suite, tc_strerror_test_is_normal);

  tc_strerror_test_out_of_range_pos =
      tcase_create("s21_strerror_test_out_of_range_pos");
  tcase_add_test(tc_strerror_test_out_of_range_pos,
                 s21_strerror_test_out_of_range_pos);
  suite_add_tcase(suite, tc_strerror_test_out_of_range_pos);

  tc_strerror_test_out_of_range_neg =
      tcase_create("s21_strerror_test_out_of_range_neg");
  tcase_add_test(tc_strerror_test_out_of_range_neg,
                 s21_strerror_test_out_of_range_neg);
  suite_add_tcase(suite, tc_strerror_test_out_of_range_neg);

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
  case_test(s21_strerror_suite(), &fail);
  return 0;
}