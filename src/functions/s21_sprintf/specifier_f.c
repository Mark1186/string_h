#include "s21_sprintf.h"

void specifier_f(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    long double arg_f = 0.0;
    if (!fmt->length.L) {
      arg_f = va_arg(factor, double);
    } else {
      arg_f = va_arg(factor, long double);
    }

    int is_neg = 0;

    if (arg_f < 0.0) {
      fmt->flag.plus = 1;
      is_neg = 1;
    }

    int default_precision = 7;
    if (fmt->precision.dot_enable) {
      default_precision = fmt->precision.dot_number + 1;
    }
    double_to_string(arg_f, res->tmp_str, default_precision);
    rounded(res->tmp_str, fmt);

    custom_width(res->tmp_str, is_neg, fmt);
    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str) - 1);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}