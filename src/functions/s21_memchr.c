#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  char *result = NULL;
  const char *string = str;
  for (size_t i = 0; i < n; ++i) {
    if (*string == c) {
      result = (char *)string;
    } else {
      string++;
    }
  }

  return result;
}