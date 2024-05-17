#include "../s21_string.h"
#include "s21_sprintf/s21_sprintf.h"

void *s21_to_upper(const char *str) {
  char *result = (char *)calloc(1024, sizeof(char));
  if (str == NULL || result == NULL) {
    result = NULL;
  } else {
    s21_strncpy(result, str, s21_strlen(str));
    for (int i = 0; str[i] != '\0'; ++i) {
      if ('a' <= str[i] && str[i] <= 'z') {
        result[i] = str[i] - ('a' - 'A');
      } else {
        result[i] = str[i];
      }
    }
  }
  return result;
}