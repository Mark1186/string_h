#include "../../s21_sprintf.h"

void short_to_string(short num, char *des_str) {
  int length = find_count(num);

  if (num < 0) {
    *des_str++ = '-';
    num = -num;
    length--;
  }

  for (int i = length - 1; i >= 0; i--) {
    des_str[i] = num % 10 + '0';
    num /= 10;
  }

  des_str[length] = '\0';
}
