#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *dest_pointer = dest;
  const char *src_pointer = src;
  for (size_t i = 0; i < n; ++i) {
    dest_pointer[i] = src_pointer[i];
  }
  return dest_pointer;
}