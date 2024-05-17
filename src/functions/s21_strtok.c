#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *lastToken = NULL;
  char *tokenStart = NULL;

  if ((str != NULL || (lastToken != NULL && *lastToken != '\0'))) {
    if (str != NULL) {
      lastToken = str;
    }

    while (*lastToken && s21_strchr(delim, *lastToken) != NULL) {
      ++lastToken;
    }

    if (*lastToken != '\0') {
      tokenStart = lastToken;

      while (*lastToken && s21_strchr(delim, *lastToken) == NULL) {
        ++lastToken;
      }

      if (*lastToken != '\0') {
        *lastToken = '\0';
        ++lastToken;
      }
    }
  }

  return tokenStart;
}
