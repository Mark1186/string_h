#include "../s21_sprintf.h"

void output_zero_e(char *des_str, char name, int precision) {
  des_str[0] = '0';
  des_str[1] = '.';
  for (int i = 2; i < precision + 1; i++) {
    des_str[i] = '0';
  }
  if (name == 'e' || name == 'E') {
    des_str[precision + 1] = name == 'e' ? 'e' : 'E';
  }
  if (name == 'g' || name == 'G') {
    des_str[precision + 1] = name == 'g' ? 'e' : 'E';
  }
  des_str[precision + 2] = '+';
  des_str[precision + 3] = '0';
  des_str[precision + 4] = '0';
  des_str[precision + 5] = '\0';
}