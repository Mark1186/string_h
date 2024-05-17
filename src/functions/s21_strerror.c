#include "../s21_string.h"
#include "s21_sprintf/s21_sprintf.h"
#include "s21_strerror_macros.h"

char *s21_strerror(int errnum) {
  char *error_messages[] = {ERROR_MESSAGES};
  static char result[1024] = {'\0'};
#ifdef Linux
  if (errnum >= 134 || errnum < 0) {
    s21_sprintf(result, "Unknown error %d", errnum);
  } else {
    s21_strncpy(result, error_messages[errnum],
                s21_strlen(error_messages[errnum]));
  }
#elif Darwin
  if (errnum >= 107 || errnum < 0) {
    s21_sprintf(result, "Unknown error %d", errnum);
  } else {
    s21_strncpy(result, error_messages[errnum],
                s21_strlen(error_messages[errnum]));
  }
#endif
  return result;
}