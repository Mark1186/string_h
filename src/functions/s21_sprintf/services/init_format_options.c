#include "../s21_sprintf.h"

void init_format_options(Format_Options *fmt) {
  fmt->name = '\0';

  fmt->flag.minus = 0;
  fmt->flag.plus = 0;
  fmt->flag.space = 0;
  fmt->flag.zero = 0;
  fmt->flag.hashtag = 0;

  fmt->width.enable = 0;
  fmt->width.number = 0;
  fmt->width.star = 0;

  fmt->precision.dot_number = 0;
  fmt->precision.dot_enable = 0;
  fmt->precision.dot_star = 0;

  fmt->length.L = 0;
  fmt->length.h = 0;
  fmt->length.l = 0;
}
