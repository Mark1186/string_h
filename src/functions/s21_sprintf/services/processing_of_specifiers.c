#include "../s21_sprintf.h"

void processing_of_specifiers(const char *ch, Format_Options *fmt, char *p_str,
                              const char *format, va_list factor,
                              int *index_str, int *index_format) {
  if (*ch == 'c') {
    fmt->name = *ch;
    specifier_c(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'd' || *ch == 'i') {
    fmt->name = *ch;
    specifier_d(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'e' || *ch == 'E') {
    fmt->name = *ch;
    specifier_e(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'f') {
    fmt->name = *ch;
    specifier_f(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'g' || *ch == 'G') {
    fmt->name = *ch;
    specifier_g(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'o') {
    fmt->name = *ch;
    specifier_o(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 's') {
    fmt->name = *ch;
    specifier_s(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'u') {
    fmt->name = *ch;
    specifier_u(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'x' || *ch == 'X') {
    fmt->name = *ch;
    specifier_x(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'p') {
    fmt->name = *ch;
    specifier_p(p_str, factor, fmt, index_str, index_format);
  } else if (*ch == 'n') {
    fmt->name = *ch;
    specifier_n(p_str, factor, index_format);
  } else if (*ch == '%') {
    fmt->name = *ch;
    s21_strncat(p_str, "%", 1);
    (*index_str)++;
    *index_format += 2;
  } else {
    p_str[(*index_str)++] = format[(*index_format)++];
    p_str[(*index_str)++] = format[(*index_format)++];
  }
}
