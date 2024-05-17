#include "../s21_sprintf.h"

void flag_handling(char **ch, Format_Options *fmt, int *index_format) {
  int is_break = 0;
  while ((!(isalnum(**ch) || **ch == '.' || **ch == '%' || **ch == '*') ||
          **ch == '0') &&
         !is_break) {
    if (**ch == '-') {
      fmt->flag.minus = 1;
      (*ch)++;
      *index_format += 1;
    } else if (**ch == '+') {
      fmt->flag.plus = 1;
      (*ch)++;
      *index_format += 1;
    } else if (**ch == ' ') {
      fmt->flag.space = 1;
      (*ch)++;
      *index_format += 1;
    } else if (**ch == '0') {
      (*ch)++;
      if (**ch != '.' && !isalpha(**ch)) {
        fmt->flag.zero = 1;
        *index_format += 1;
      } else {
        (*ch)--;
        is_break = 1;
      }
    } else if (**ch == '#') {
      fmt->flag.hashtag = 1;
      (*ch)++;
      *index_format += 1;
    } else {
      is_break = 1;
    }
  }
}
