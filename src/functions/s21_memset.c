#include "../s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  char *str_pointer = str;
  for (size_t i = 0; i < n; ++i) {
    str_pointer[i] = c;
  }
  return str_pointer;
}