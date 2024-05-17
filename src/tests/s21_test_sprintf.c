#include <check.h>

#include "s21_test.h"

START_TEST(s21_sprintf_test_for_sprecifier_s) {
  char *text = "Name: %5s, %lsf";
  char *name = "John";
  wchar_t *last_name = L"Markov";
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, name, last_name);
  int str_length = sprintf(str, text, name, last_name);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_d) {
  char *text = "Age %010.5d  f  %-5.1ld";
  int age = -26;
  int age2 = -26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age, age2);
  int str_length = sprintf(str, text, age, age2);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_i) {
  char *text = "Age %010.5i%-5.1li";
  int age = 26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age, age);
  int str_length = sprintf(str, text, age, age);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_c) {
  char *text = "Age %d%010.5c -> %lc";
  char age = 26;
  char ch = '!';
  wchar_t wch = '@';
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age, ch, wch);
  int str_length = sprintf(str, text, age, ch, wch);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_o) {
  char *text = "Age%o %010.5o  f  %-5.1lo";
  int age = 26;
  int age2 = -26;
  int age3 = -26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age, age2, age3);
  int str_length = sprintf(str, text, age, age2, age3);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_x) {
  char *text = "Age %10x";
  char age_hex = 26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age_hex);
  int str_length = sprintf(str, text, age_hex);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_u) {
  char *text = "Age %010.5u%-5.1u";
  int age = 26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, age, age);
  int str_length = sprintf(str, text, age, age);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_e) {
  char *text = "Age %010e";
  double num = 26.34643;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, num);
  int str_length = sprintf(str, text, num);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_f) {
  char *text = "Age %010f";
  double num = 26.34643;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, num);
  int str_length = sprintf(str, text, num);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_g) {
  char *text = "Age %010g";
  double num = 26.34643;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, num);
  int str_length = sprintf(str, text, num);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_p) {
  char *text = "Age %010.5p";
  int age = 26;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, (void *)&age);
  int str_length = sprintf(str, text, (void *)&age);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
END_TEST

START_TEST(s21_sprintf_test_for_specifier_n) {
  char *text = "Age %n";
  int age;
  char my_str[100];
  char str[100];

  int my_str_length = s21_sprintf(my_str, text, &age);
  int str_length = sprintf(str, text, &age);

  ck_assert_str_eq(my_str, str);
  ck_assert_int_eq(my_str_length, str_length);
}
Suite *s21_sprintf_suite(void) {
  Suite *suite;
  TCase *tc_sprintf_test_for_specifier_s, *tc_sprintf_test_for_specifier_d,
      *tc_sprintf_test_for_specifier_c, *tc_sprintf_test_for_specifier_o,
      *tc_sprintf_test_for_specifier_x, *tc_sprintf_test_for_specifier_p,
      *tc_sprintf_test_for_specifier_n, *tc_sprintf_test_for_specifier_u,
      *tc_sprintf_test_for_specifier_i, *tc_sprintf_test_for_specifier_e,
      *tc_sprintf_test_for_specifier_f, *tc_sprintf_test_for_specifier_g;

  suite = suite_create("s21_sprintf");

  tc_sprintf_test_for_specifier_s =
      tcase_create("s21_sprintf_test_for_specifier_s");
  tcase_add_test(tc_sprintf_test_for_specifier_s,
                 s21_sprintf_test_for_sprecifier_s);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_s);

  tc_sprintf_test_for_specifier_d =
      tcase_create("s21_sprintf_test_for_specifier_d");
  tcase_add_test(tc_sprintf_test_for_specifier_d,
                 s21_sprintf_test_for_specifier_d);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_d);

  tc_sprintf_test_for_specifier_i =
      tcase_create("s21_sprintf_test_for_specifier_i");
  tcase_add_test(tc_sprintf_test_for_specifier_i,
                 s21_sprintf_test_for_specifier_i);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_i);

  tc_sprintf_test_for_specifier_c =
      tcase_create("s21_sprintf_test_for_specifier_c");
  tcase_add_test(tc_sprintf_test_for_specifier_c,
                 s21_sprintf_test_for_specifier_c);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_c);

  tc_sprintf_test_for_specifier_o =
      tcase_create("s21_sprintf_test_for_specifier_o");
  tcase_add_test(tc_sprintf_test_for_specifier_o,
                 s21_sprintf_test_for_specifier_o);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_o);

  tc_sprintf_test_for_specifier_x =
      tcase_create("s21_sprintf_test_for_specifier_x");
  tcase_add_test(tc_sprintf_test_for_specifier_x,
                 s21_sprintf_test_for_specifier_x);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_x);

  tc_sprintf_test_for_specifier_u =
      tcase_create("s21_sprintf_test_for_specifier_u");
  tcase_add_test(tc_sprintf_test_for_specifier_u,
                 s21_sprintf_test_for_specifier_u);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_u);

  tc_sprintf_test_for_specifier_n =
      tcase_create("s21_sprintf_test_for_specifier_n");
  tcase_add_test(tc_sprintf_test_for_specifier_n,
                 s21_sprintf_test_for_specifier_n);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_n);

  tc_sprintf_test_for_specifier_p =
      tcase_create("s21_sprintf_test_for_specifier_p");
  tcase_add_test(tc_sprintf_test_for_specifier_p,
                 s21_sprintf_test_for_specifier_p);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_p);

  tc_sprintf_test_for_specifier_e =
      tcase_create("s21_sprintf_test_for_specifier_e");
  tcase_add_test(tc_sprintf_test_for_specifier_e,
                 s21_sprintf_test_for_specifier_e);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_e);

  tc_sprintf_test_for_specifier_f =
      tcase_create("s21_sprintf_test_for_specifier_f");
  tcase_add_test(tc_sprintf_test_for_specifier_f,
                 s21_sprintf_test_for_specifier_f);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_f);

  tc_sprintf_test_for_specifier_g =
      tcase_create("s21_sprintf_test_for_specifier_g");
  tcase_add_test(tc_sprintf_test_for_specifier_g,
                 s21_sprintf_test_for_specifier_g);
  suite_add_tcase(suite, tc_sprintf_test_for_specifier_g);
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
  case_test(s21_sprintf_suite(), &fail);
  return 0;
}