#include "../s21_sprintf.h"

void set_index_format(Format_Options *fmt, int *index_format) {
  if ((fmt->width.enable && fmt->width.number == 0) ||
      (fmt->precision.dot_enable && fmt->precision.dot_number == 0)) {
    *index_format += 1;
  }

  if ((fmt->width.star && find_count(fmt->width.number) > 1) ||
      (fmt->precision.dot_star && find_count(fmt->precision.dot_number) > 1)) {
    *index_format -= 1;
  }

  if (fmt->width.star && fmt->precision.dot_star) {
    *index_format -= 1;
  }
}
