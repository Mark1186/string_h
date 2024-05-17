#include "../s21_sprintf.h"

void custom_plus(char *des_str, const int is_neg, const Format_Options *fmt) {
  Resources *res = constructor();
  if (res != NULL) {
    if (fmt->flag.plus || is_neg) {
      s21_strncat(res->tmp_str, is_neg ? "-" : "+", 1);
      s21_strncat(res->tmp_str, des_str, s21_strlen(des_str));

      s21_strncpy(des_str, res->tmp_str, s21_strlen(res->tmp_str));
    }

    destructor(res);
  }
}
