#include "../../s21_sprintf.h"

void ldouble_to_string(long double number, char *result, int precision) {
  int sign = (number < 0) ? -1 : 1;
  number = sign * number;

  int intPart = (int)number;
  long double fracPart = number - intPart;

  unsigned long i = 0;
  do {
    result[i++] = '0' + intPart % 10;
    intPart /= 10;
  } while (intPart > 0);

  reverse_string(result, i);

  if (precision > 0) {
    result[i++] = '.';
  }

  while (precision-- > 0) {
    fracPart *= 10.0;
    int digit = (int)fracPart;
    result[i++] = '0' + digit;
    fracPart -= digit;
  }

  result[i] = '\0';
}
