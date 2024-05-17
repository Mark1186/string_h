#include "../s21_sprintf.h"

void modify_and_concatenate_string(Resources *res, char *des_str, char ch,
                                   int exponent) {
  char *find_char = s21_strchr(des_str, ch);
  int abs_exponent = abs(exponent);
  int index_to_remove = s21_strlen(des_str) - s21_strlen(find_char);
  if (exponent < 0) {
    del_symbol_in_string(des_str, ch);
    insert_symbol_in_string(des_str, ch, abs(exponent - index_to_remove));
    del_zero_startstr(des_str);
    s21_strncat(res->tmp_str, des_str, s21_strlen(des_str));
  } else {
    del_symbol_in_string(des_str, ch);
    insert_symbol_in_string(des_str, ch, index_to_remove - exponent);
    s21_strncat(res->tmp_str, des_str, s21_strlen(des_str) - abs_exponent);
  }
}
