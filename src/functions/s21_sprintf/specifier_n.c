#include "s21_sprintf.h"

void specifier_n(char *p_str, va_list factor, int *index_format) {
  int *arg_d = va_arg(factor, int *);
  int count_string = (int)s21_strlen(p_str);
  *arg_d = count_string;

  *index_format += 2;
}