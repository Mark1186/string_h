#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    dest[i] = src[i];
  }
  return dest;
}