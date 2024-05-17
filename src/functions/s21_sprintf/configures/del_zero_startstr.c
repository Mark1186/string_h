#include "../s21_sprintf.h"

void del_zero_startstr(char *des_str) {
  int length = s21_strlen(des_str);
  int nonZeroIndex = 0;
  while (des_str[nonZeroIndex] == '0') {
    nonZeroIndex++;
  }
  if (nonZeroIndex == length) {
    des_str[1] = '\0';
  } else {
    for (int i = 0; i < length - nonZeroIndex; i++) {
      des_str[i] = des_str[nonZeroIndex + i];
    }
    des_str[length - nonZeroIndex] = '\0';
  }
}
