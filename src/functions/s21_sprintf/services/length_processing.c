#include "../s21_sprintf.h"

void length_processing(char **ch, Format_Options *fmt, int *index_format) {
  if (isalpha(**ch)) {
    if (**ch == 'h') {
      fmt->length.h = 'h';
      (*ch)++;
      (*index_format)++;
    } else if (**ch == 'l') {
      fmt->length.l = 'l';
      (*ch)++;
      (*index_format)++;
    } else if (**ch == 'L') {
      fmt->length.L = 'L';
      (*ch)++;
      (*index_format)++;
    }
  } else {
    (*ch)++;
  }
}
