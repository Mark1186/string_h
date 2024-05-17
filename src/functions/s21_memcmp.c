#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  if (n != 0 && str1 != NULL && str2 != NULL) {
    const char *pointer1 = str1;
    const char *pointer2 = str2;
    int breakpoint = 0;
    for (size_t i = 0; i < n; i++) {
      if ((pointer1[i] < pointer2[i]) && !breakpoint) {
        result = -1;
        breakpoint = 1;
      } else if ((pointer1[i] > pointer2[i]) && !breakpoint) {
        result = 1;
        breakpoint = 1;
      }
    }
  }
  return result;
}