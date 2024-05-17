#include "../s21_sprintf.h"

void insert_symbol_in_string(char *des_str, char ch, int index) {
  Resources *res = constructor();
  if (res != NULL) {
    int index_des = 0;
    int index_tmp = 0;
    while (des_str[index_des] != '\0') {
      if (index_des == index) {
        res->tmp_str[index_tmp++] = ch;
      }
      res->tmp_str[index_tmp++] = des_str[index_des++];
    }

    res->tmp_str[s21_strlen(res->tmp_str)] = '\0';

    s21_strncpy(des_str, res->tmp_str, s21_strlen(res->tmp_str));
    destructor(res);
  }
}
