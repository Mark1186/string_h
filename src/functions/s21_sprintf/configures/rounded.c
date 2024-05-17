#include "../s21_sprintf.h"

void rounded(char *des_str, Format_Options *fmt) {
  Resources *res = constructor();
  if (res != NULL) {
    int precision = 6;

    if (fmt->precision.dot_enable) {
      precision = fmt->precision.dot_number;
    }

    s21_strncat(res->tmp_str, des_str, s21_strlen(des_str));

    int index_to_remove = 0;
    for (int i = 0; res->tmp_str[i] != '\0'; ++i) {
      if (res->tmp_str[i] == '.') {
        index_to_remove = i;
      }
    }

    del_symbol_in_string(res->tmp_str, '.');
    del_symbol_in_string(des_str, '.');

    round_string_of_math_rules(res->tmp_str, des_str);

    if (fmt->precision.dot_enable && precision == 0) {
      insert_symbol_in_string(res->tmp_str, '.', index_to_remove);
    } else if (fmt->name == 'g' || fmt->name == 'G') {
      if (index_to_remove >= (int)s21_strlen(res->tmp_str) - 1) {
        insert_symbol_in_string(res->tmp_str, '.', index_to_remove);
      } else {
        insert_symbol_in_string(res->tmp_str, '.', index_to_remove);
      }
    } else {
      insert_symbol_in_string(res->tmp_str, '.', index_to_remove);
    }

    s21_strncpy(des_str, res->tmp_str, s21_strlen(res->tmp_str));
    destructor(res);
  }
}