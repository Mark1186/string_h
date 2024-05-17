#include "../s21_sprintf.h"

void width_processing(char **ch, va_list factor, Format_Options *fmt,
                      int *index_format) {
  if (isdigit((unsigned char)**ch) || **ch == '*') {
    fmt->width.enable = 1;
    if (**ch == '*') {
      fmt->width.star = 1;
      fmt->width.number = va_arg(factor, int);
      (*ch)++;
    } else {
      while (isdigit(**ch)) {
        fmt->width.number = fmt->width.number * 10 + (**ch - '0');
        (*ch)++;
      }
    }
    *index_format += find_count(fmt->width.number);
  }
}
