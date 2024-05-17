#include "s21_sprintf.h"

void specifier_u(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    unsigned long arg_u = 0;
    init_num_ulong(factor, fmt, &arg_u);

    if (fmt->flag.plus) {
      fmt->flag.plus = 0;
    }
    if (!fmt->flag.minus && fmt->precision.dot_enable) {
      fmt->flag.zero = 0;
    }
    if (fmt->precision.dot_enable) {
      fmt->flag.zero = 0;
    }
    convert_to_string(arg_u, res->tmp_str);
    custom_precision(res->tmp_str, fmt);

    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str));
    custom_width(res->des_str, 0, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}