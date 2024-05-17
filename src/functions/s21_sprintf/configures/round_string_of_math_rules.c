#include "../s21_sprintf.h"

void round_string_of_math_rules(char *tmp_str, char *des_str) {
  int last_index = s21_strlen(tmp_str) - 1;
  int is_break = 0;
  for (int i = (int)s21_strlen(des_str) - 1; i >= 0 && !is_break; --i) {
    if (des_str[i] - '0' >= 5) {
      if (des_str[i] - '0' < 9) {
        writing_numbers(tmp_str, &last_index, i, &is_break);
      } else {
        writing_numbers(tmp_str, &last_index, i, &is_break);
      }
    } else {
      is_break = 1;
    }
    last_index--;
  }
}
