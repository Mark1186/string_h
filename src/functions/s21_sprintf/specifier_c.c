#include "s21_sprintf.h"

void specifier_c(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  char arg_c = 0;

  if (fmt->length.l) {
    wchar_t tmp_str = va_arg(factor, wchar_t);
    arg_c = tmp_str;
  } else {
    arg_c = va_arg(factor, int);
  }

  int length = 0;
  if (fmt->flag.minus) {
    s21_strncat(p_str, &arg_c, 1);
    *index_str += 1;
  }
  if (fmt->width.number != 0) {
    while (++length < fmt->width.number) {
      s21_strncat(p_str, " ", 1);
      *index_str += 1;
    }
  }
  if (!fmt->flag.minus) {
    s21_strncat(p_str, &arg_c, 1);
    *index_str += 1;
  }

  *index_format += 2;
}