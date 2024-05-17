#include "s21_sprintf.h"

void specifier_e(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    long double arg_e = 0.0;

    if (!fmt->length.L) {
      arg_e = va_arg(factor, double);
    } else {
      arg_e = va_arg(factor, long double);
    }

    int is_neg = 0;

    if (arg_e < 0.0) {
      fmt->flag.plus = 1;
      is_neg = 1;
    }

    int default_precision = 7;
    if (fmt->precision.dot_enable) {
      default_precision = fmt->precision.dot_number + 1;
    }

    convert_double_to_string(arg_e, res->tmp_str, default_precision);
    rounded(res->tmp_str, fmt);
    custom_format_e(res->des_str, arg_e, fmt, default_precision);
    custom_width(res->des_str, is_neg, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}