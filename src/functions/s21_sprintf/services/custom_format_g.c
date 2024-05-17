#include "../s21_sprintf.h"

void custom_format_g(char *des_str, Format_Options *fmt, double number,
                     int exponent, int precision, int is_neg) {
  if (exponent < -4 || exponent >= precision) {
    double_to_string(number, des_str, precision);
    rounded(des_str, fmt);

    Format_Options fmt_ptr = *fmt;
    if (fmt_ptr.precision.dot_enable && fmt_ptr.precision.dot_number) {
      fmt_ptr.precision.dot_number -= 1;
    } else {
      fmt_ptr.precision.dot_number -= 0;
    }

    custom_format_e(des_str, number, &fmt_ptr, precision);
    custom_width(des_str, is_neg, &fmt_ptr);
  } else {
    if (number != 0.0) {
      precision -= 2;
      double_to_string(number, des_str, precision);
      rounded(des_str, fmt);

      if (!fmt->flag.hashtag) {
        del_zero_endstr(des_str);
      }

      if (des_str[s21_strlen(des_str) - 1] == '.') {
        des_str[s21_strlen(des_str) - 1] = '\0';
      }

      custom_width(des_str, 0, fmt);
    } else {
      s21_strncat(des_str, "0", 1);
      custom_width(des_str, 0, fmt);
    }
  }
}
