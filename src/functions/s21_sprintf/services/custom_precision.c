#include "../s21_sprintf.h"

void custom_precision(char *des_str, const Format_Options *fmt) {
  Resources *res = constructor();
  int count = 0;
  int diff = 0;
  if (fmt->precision.dot_enable) {
    diff = fmt->precision.dot_number - s21_strlen(des_str);
  }

  while (count++ < diff) {
    s21_strncat(res->tmp_str, "0", 1);
  }

  s21_strncat(res->tmp_str, des_str, s21_strlen(des_str));
  s21_strncpy(des_str, res->tmp_str, s21_strlen(res->tmp_str));

  destructor(res);
}
