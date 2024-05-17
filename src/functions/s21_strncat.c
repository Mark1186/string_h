#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *dest_pointer = dest;
  size_t index = s21_strlen((const char *)dest);

  for (size_t i = 0; i < n && src[i] != '\0'; i++) {
    dest_pointer[index + i] = src[i];
  }

  dest_pointer[index + n] = '\0';
  return dest_pointer;
}
