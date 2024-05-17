#include "../s21_string.h"

void compare(const char *str1, const char *str2, size_t *result) {
  int breakpoint = 0;
  for (size_t i = 0; i < s21_strlen(str1) && !breakpoint; i++) {
    for (size_t j = 0; j < s21_strlen(str2) && !breakpoint; j++) {
      if (str1[i] == str2[j]) {
        breakpoint = 1;
      }
    }
    if (!breakpoint) {
      *result += 1;
    }
  }
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t result = 0;

  if (str1 != NULL && str2 != NULL) {
    compare(str1, str2, &result);
  }

  return result;
}