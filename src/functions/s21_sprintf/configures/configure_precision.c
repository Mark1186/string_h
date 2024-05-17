#include "../s21_sprintf.h"

void configure_precision(int *precision, int exponent, Format_Options *fmt) {
  if (fmt->precision.dot_enable) {
    if (exponent < 0) {
      *precision = fmt->precision.dot_number + abs(exponent) + 1;
    } else {
      *precision = fmt->precision.dot_number + 1;
    }
  }
}
