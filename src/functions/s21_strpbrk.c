#include "../s21_string.h"

char *loop(char *result, const char *str1, const char *str2) {
  int breakpoint = 0;
  for (size_t i = 0; i < s21_strlen(str1) && !breakpoint; i++) {
    for (size_t n = 0; n < s21_strlen(str2) && !breakpoint; n++) {
      if (str1[i] == str2[n]) {
        result = &((char *)str1)[i];
        breakpoint = 1;
      }
    }
  }
  return result;
}
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = NULL;
  if (str1 != NULL && str2 != NULL) {
    result = loop(result, str1, str2);
  }

  return result;
}