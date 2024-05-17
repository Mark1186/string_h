#include "s21_sprintf.h"

void specifier_d(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();

  if (res != NULL) {
    int arg_d = 0;
    long arg_l = 0;

    if (fmt->length.l) {
      arg_l = va_arg(factor, long);
      convert_to_string(arg_l, res->tmp_str);
    } else {
      arg_d = va_arg(factor, int);
      convert_to_string(arg_d, res->tmp_str);
    }

    int is_neg = 0;
    if (arg_d < 0 || arg_l < 0) {
      fmt->flag.plus = 0;
      is_neg = 1;
    }
    if (fmt->precision.dot_enable) {
      fmt->flag.zero = 0;
    }
    custom_precision(res->tmp_str, fmt);

    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str));
    custom_width(res->des_str, is_neg, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}