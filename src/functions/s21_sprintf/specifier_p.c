#include "s21_sprintf.h"

void specifier_p(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  Resources *res = constructor();
  if (res != NULL) {
    uintptr_t arg_p;
    arg_p = va_arg(factor, unsigned long);

    int length = 0;

    if (fmt->flag.minus) {
      fmt->flag.zero = 0;
    }

    s21_strncat(res->des_str, "0x", 2);

    count_of_hex_digits(arg_p, &length);
    representation_of_num_in_hex(res->tmp_str, &arg_p, length);

    custom_precision(res->tmp_str, fmt);
    s21_strncat(res->des_str, res->tmp_str, s21_strlen(res->tmp_str));
    custom_width(res->des_str, 0, fmt);

    s21_strncat(p_str, res->des_str, s21_strlen(res->des_str));

    *index_str += (int)s21_strlen(res->des_str);
    *index_format += 2;

    destructor(res);
  }
}