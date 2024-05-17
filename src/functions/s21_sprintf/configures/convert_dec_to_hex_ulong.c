#include "../s21_sprintf.h"

void convert_dec_to_hex_ulong(char *des_str, unsigned long num,
                              Format_Options *fmt) {
  int i = 0;
  if (num != 0) {
    while (num != 0) {
      int remainder = num % 16;

      if (remainder < 10) {
        des_str[i] = remainder + '0';
      } else {
        des_str[i] = remainder - 10 + (fmt->name == 'X' ? 'A' : 'a');
      }

      num /= 16;
      i++;
    }
  } else {
    des_str[i++] = '0';
  }

  reverse_string(des_str, i);

  des_str[i] = '\0';
}
