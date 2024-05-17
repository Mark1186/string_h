#include "s21_sprintf.h"

void specifier_o(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    long arg_o = 0;
    init_num_int(factor, fmt, &arg_o);

    if (fmt->flag.plus) {
      fmt->flag.plus = 0;
    }

    if (!fmt->flag.minus && fmt->precision.dot_enable) {
      fmt->flag.zero = 0;
    }

    convert_dec_to_oct(res->tmp_str, arg_o);
    custom_precision(res->tmp_str, fmt);

    if (fmt->flag.hashtag && fmt->name == 'o') {
      s21_strncat(res->des_str, "0", 1);
    }

    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str));
    custom_width(res->des_str, 0, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += s21_strlen(res->des_str);
    set_index_format(fmt, index_format);
    *index_format += 2;

    destructor(res);
  }
}