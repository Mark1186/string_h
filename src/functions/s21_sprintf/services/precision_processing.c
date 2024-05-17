#include "../s21_sprintf.h"

void precision_processing(char **ch, va_list factor, Format_Options *fmt,
                          int *index_format) {
  if (**ch == '.') {
    (*ch)++;
    *index_format += 1;
    fmt->precision.dot_enable = 1;
    fmt->precision.dot_number = 0;
    if (**ch == '*') {
      fmt->precision.dot_star = 1;
      fmt->precision.dot_number = va_arg(factor, int);
      (*ch)++;
    } else {
      while (isdigit(**ch)) {
        fmt->precision.dot_number =
            fmt->precision.dot_number * 10 + (**ch - '0');
        (*ch)++;
      }
    }

    *index_format += find_count(fmt->precision.dot_number);
  }
}
