#include "s21_sprintf.h"

void specifier_g(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    va_list factor_copy;
    va_copy(factor_copy, factor);
    long double arg_g = 0.0;
    if (!fmt->length.L) {
      arg_g = va_arg(factor, double);
    } else {
      arg_g = va_arg(factor, long double);
    }

    int is_neg = 0;
    if (arg_g < 0.0) {
      fmt->flag.plus = 1;
      is_neg = 1;
    }
    va_end(factor_copy);

    int exponent = 0;
    if (arg_g != 0.0) {
      exponent = (int)floor(log10(fabs((double)arg_g)));
    }

    int precision = 6;
    if (fmt->precision.dot_enable) {
      precision = fmt->precision.dot_number;
    }

    double_to_string(arg_g, res->tmp_str, precision);
    rounded(res->tmp_str, fmt);

    int i = s21_strlen(res->tmp_str) - 1;
    while (i >= 0 && res->tmp_str[i] == '0') {
      res->tmp_str[i] = '\0';
      i--;
    }

    custom_format_g(res->des_str, fmt, arg_g, exponent, precision, is_neg);
    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}