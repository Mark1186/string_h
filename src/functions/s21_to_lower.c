#include "../s21_string.h"
#include "s21_sprintf/s21_sprintf.h"

void *s21_to_lower(const char *str) {
  char *result = (char *)calloc(1024, sizeof(char));
  if (str == NULL || result == NULL) {
    result = NULL;
  } else {
    s21_strncpy(result, str, s21_strlen(str));
    for (int i = 0; str[i] != '\0'; ++i) {
      if ('A' <= str[i] && str[i] <= 'Z') {
        result[i] = str[i] - ('A' - 'a');
      } else {
        result[i] = str[i];
      }
    }
  }

  return result;
}