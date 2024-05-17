#include "s21_sprintf.h"

void specifier_x(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    unsigned long arg_x = 0;
    init_num_ulong(factor, fmt, &arg_x);

    if (fmt->flag.plus) {
      fmt->flag.plus = 0;
    }

    convert_dec_to_hex_ulong(res->tmp_str, arg_x, fmt);
    custom_precision(res->tmp_str, fmt);

    if (fmt->flag.hashtag && fmt->name == 'x') {
      s21_strncat(res->des_str, "0x", 2);
    } else if (fmt->flag.hashtag && fmt->name == 'X') {
      s21_strncat(res->des_str, "0X", 2);
    }

    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str));
    custom_width(res->des_str, 0, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));
    *index_str += s21_strlen(res->des_str);
    if (fmt->precision.dot_enable && fmt->precision.dot_number == 0) {
      *index_format += 3;
    } else {
      *index_format += 2;
    }

    destructor(res);
  }
}