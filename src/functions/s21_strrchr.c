#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = NULL;

  while (*str++) {
    if (*str == (char)c) {
      result = (char *)str;
    }
  }
  return result;
}