#include "../s21_sprintf.h"

void custom_format_e(char *des_str, double number, Format_Options *fmt,
                     int precision) {
  Resources *res = constructor();
  if (res != NULL) {
    char ch = '.';
    int exponent = 0;

    find_exponent(number, &exponent, &precision);
    configure_precision(&precision, exponent, fmt);

    if (number == 0.0) {
      output_zero_e(des_str, fmt->name, precision);
    }

    double_to_string(number, des_str, precision);
    modify_and_concatenate_string(res, des_str, ch, exponent);
    rounded(res->tmp_str, fmt);

    s21_memset(des_str, 0, s21_strlen(des_str));
    s21_strncat(des_str, res->tmp_str, s21_strlen(res->tmp_str) - 1);

    int index = 0;
    if (fmt->name == 'e' || fmt->name == 'E') {
      res->res_str[index++] = fmt->name == 'e' ? 'e' : 'E';
    }
    if ((fmt->name == 'g' || fmt->name == 'G')) {
      if (!fmt->flag.hashtag) {
        del_zero_endstr(des_str);
      }
      res->res_str[index++] = fmt->name == 'g' ? 'e' : 'E';
    }

    res->res_str[index++] = (exponent >= 0) ? '+' : '-';
    res->res_str[index++] = (abs(exponent) / 10) + '0';
    res->res_str[index++] = (abs(exponent) % 10) + '0';

    res->res_str[index] = '\0';
    s21_strncat(des_str, res->res_str, s21_strlen(res->res_str));

    destructor(res);
  }
}
