#include "../s21_sprintf.h"

void del_zero_endstr(char *des_str) {
  int i = s21_strlen(des_str) - 1;
  while ((i >= 0 && des_str[i] == '0') && s21_strchr(des_str, '.') != NULL) {
    des_str[i] = '\0';
    i--;
  }
}
