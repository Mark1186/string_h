#include "s21_test.h"

START_TEST(s21_sscanf_test_for_format_s) {
  char *input = "Johny";
  const char *format = "%s";
  char name[1024];
  char name2[1024];

  s21_sscanf(input, format, name);
  sscanf(input, format, name2);

  ck_assert_str_eq(name, name2);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_d) {
  char *input = "26";
  const char *format = "%d";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_i) {
  char *input = "23";
  const char *format = "%i";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_c) {
  char *input = " A";
  const char *format = "%c";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_o) {
  char *input = " 0123";
  const char *format = "%o";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_x) {
  char *input = "0x1a";
  const char *format = "%x";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_u) {
  char *input = " 24";
  const char *format = "%u";
  int my_age = 0;
  int age = 0;

  s21_sscanf(input, format, &my_age);
  sscanf(input, format, &age);

  ck_assert_int_eq(my_age, age);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_e) {
  char *input = " 1.234e+03";
  const char *format = "%e";
  double my_ddouble = 0;
  double ddouble = 0;

  s21_sscanf(input, format, &my_ddouble);
  sscanf(input, format, &ddouble);

  ck_assert_double_eq_tol(my_ddouble, ddouble, 6);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_f) {
  char *input = " 1.234312";
  const char *format = "%f";
  double my_ddouble = 0;
  double ddouble = 0;

  s21_sscanf(input, format, &my_ddouble);
  sscanf(input, format, &ddouble);

  ck_assert_double_eq_tol(my_ddouble, ddouble, 6);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_g) {
  char *input = " 1.234e+03";
  const char *format = "%e";
  double my_ddouble = 0;
  double ddouble = 0;

  s21_sscanf(input, format, &my_ddouble);
  sscanf(input, format, &ddouble);

  ck_assert_double_eq_tol(my_ddouble, ddouble, 6);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_p) {
  char *input = " 0x1a";
  const char *format = "%p";
  void *my_pointer = NULL;
  void *pointer = NULL;

  s21_sscanf(input, format, &my_pointer);
  sscanf(input, format, &pointer);

  ck_assert_ptr_eq(my_pointer, pointer);
}
END_TEST

START_TEST(s21_sscanf_test_for_format_n) {
  char *input = "234 423";
  const char *format = "%d%d%n";
  int my_counter = 0;
  int counter = 0;
  int input1 = 0;
  int input2 = 0;

  s21_sscanf(input, format, &input1, &input2, &my_counter);
  sscanf(input, format, &input1, &input2, &counter);

  ck_assert_int_eq(my_counter, counter);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *suite;
  TCase *tc_sscanf_test_for_format_s, *tc_sscanf_test_for_format_d,
      *tc_sscanf_test_for_format_i, *tc_sscanf_test_for_format_c,
      *tc_sscanf_test_for_format_o, *tc_sscanf_test_for_format_x,
      *tc_sscanf_test_for_format_u, *tc_sscanf_test_for_format_e,
      *tc_sscanf_test_for_format_f, *tc_sscanf_test_for_format_g,
      *tc_sscanf_test_for_format_p, *tc_sscanf_test_for_format_n;

  suite = suite_create("s21_sscanf");

  tc_sscanf_test_for_format_s = tcase_create("s21_sscanf_test_for_format_s");
  tcase_add_test(tc_sscanf_test_for_format_s, s21_sscanf_test_for_format_s);
  suite_add_tcase(suite, tc_sscanf_test_for_format_s);

  tc_sscanf_test_for_format_d = tcase_create("s21_sscanf_test_for_format_d");
  tcase_add_test(tc_sscanf_test_for_format_d, s21_sscanf_test_for_format_d);
  suite_add_tcase(suite, tc_sscanf_test_for_format_d);

  tc_sscanf_test_for_format_i = tcase_create("s21_sscanf_test_for_format_i");
  tcase_add_test(tc_sscanf_test_for_format_i, s21_sscanf_test_for_format_i);
  suite_add_tcase(suite, tc_sscanf_test_for_format_i);

  tc_sscanf_test_for_format_c = tcase_create("s21_sscanf_test_for_format_c");
  tcase_add_test(tc_sscanf_test_for_format_c, s21_sscanf_test_for_format_c);
  suite_add_tcase(suite, tc_sscanf_test_for_format_c);

  tc_sscanf_test_for_format_o = tcase_create("s21_sscanf_test_for_format_o");
  tcase_add_test(tc_sscanf_test_for_format_o, s21_sscanf_test_for_format_o);
  suite_add_tcase(suite, tc_sscanf_test_for_format_o);

  tc_sscanf_test_for_format_x = tcase_create("s21_sscanf_test_for_format_x");
  tcase_add_test(tc_sscanf_test_for_format_x, s21_sscanf_test_for_format_x);
  suite_add_tcase(suite, tc_sscanf_test_for_format_x);

  tc_sscanf_test_for_format_u = tcase_create("s21_sscanf_test_for_format_u");
  tcase_add_test(tc_sscanf_test_for_format_u, s21_sscanf_test_for_format_u);
  suite_add_tcase(suite, tc_sscanf_test_for_format_u);

  tc_sscanf_test_for_format_e = tcase_create("s21_sscanf_test_for_format_e");
  tcase_add_test(tc_sscanf_test_for_format_e, s21_sscanf_test_for_format_e);
  suite_add_tcase(suite, tc_sscanf_test_for_format_e);

  tc_sscanf_test_for_format_f = tcase_create("s21_sscanf_test_for_format_f");
  tcase_add_test(tc_sscanf_test_for_format_f, s21_sscanf_test_for_format_f);
  suite_add_tcase(suite, tc_sscanf_test_for_format_f);

  tc_sscanf_test_for_format_g = tcase_create("s21_sscanf_test_for_format_g");
  tcase_add_test(tc_sscanf_test_for_format_g, s21_sscanf_test_for_format_g);
  suite_add_tcase(suite, tc_sscanf_test_for_format_g);

  tc_sscanf_test_for_format_p = tcase_create("s21_sscanf_test_for_format_p");
  tcase_add_test(tc_sscanf_test_for_format_p, s21_sscanf_test_for_format_p);
  suite_add_tcase(suite, tc_sscanf_test_for_format_p);

  tc_sscanf_test_for_format_n = tcase_create("s21_sscanf_test_for_format_n");
  tcase_add_test(tc_sscanf_test_for_format_n, s21_sscanf_test_for_format_n);
  suite_add_tcase(suite, tc_sscanf_test_for_format_n);

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
  case_test(s21_sscanf_suite(), &fail);

  return 0;
}