#include "../s21_sprintf.h"

void del_symbol_in_string(char *des_str, char ch) {
  Resources *res = constructor();
  if (res != NULL) {
    int index_tmp = 0;
    int index_des = 0;
    while (des_str[index_des] != '\0') {
      if (des_str[index_des] != ch) {
        res->tmp_str[index_tmp] = des_str[index_des];
        index_tmp++;
        index_des++;
      } else {
        index_des++;
      }
    }

    s21_strncpy(des_str, res->tmp_str, s21_strlen(des_str));
    destructor(res);
  }
}