#include "../s21_sprintf.h"

void custom_width(char *des_str, const int is_neg, const Format_Options *fmt) {
  Resources *res = constructor();
  int count = 0;
  if (fmt->flag.plus || is_neg) {
    count++;
  }
  int diff = 0;
  if (fmt->name == 'f' && (fmt->width.number >= (int)s21_strlen(des_str))) {
    diff++;
  }
  if (fmt->width.number > (int)s21_strlen(des_str)) {
    diff = fmt->width.number - s21_strlen(des_str);
  }
  if (fmt->width.enable) {
    while (count++ < diff) {
      s21_strncat(res->tmp_str, (fmt->flag.zero) ? "0" : " ", 1);
    }
  }

  if (!fmt->flag.minus) {
    if (!fmt->flag.zero) {
      custom_plus(des_str, is_neg, fmt);
    } else {
      custom_plus(res->tmp_str, is_neg, fmt);
    }
    s21_strncat(res->tmp_str, des_str, s21_strlen(des_str));
  } else {
    s21_strncat(des_str, res->tmp_str, s21_strlen(res->tmp_str));
    s21_strncpy(res->tmp_str, des_str, s21_strlen(des_str));
    if (fmt->flag.plus || is_neg) {
      custom_plus(des_str, is_neg, fmt);
    }
  }
  s21_strncpy(des_str, res->tmp_str, s21_strlen(res->tmp_str));
  destructor(res);
}
