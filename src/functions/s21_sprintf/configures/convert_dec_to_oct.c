#include "../s21_sprintf.h"

void convert_dec_to_oct(char *des_str, unsigned int num) {
  int i = 0;
  if (num != 0) {
    while (num != 0) {
      int remainder = num % 8;
      if (remainder < 7) {
        des_str[i] = remainder + '0';
      } else {
        des_str[i] = '7';
      }
      num /= 8;
      i++;
    }
  } else {
    des_str[i++] = '0';
  }

  reverse_string(des_str, i);

  des_str[i] = '\0';
}
