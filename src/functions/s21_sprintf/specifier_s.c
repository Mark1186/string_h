#include "s21_sprintf.h"

void handle_precision_and_flag(char *p_str, const char *p_source,
                               int *index_str, int length,
                               Format_Options *fmt) {
  if (fmt->precision.dot_enable && fmt->flag.minus) {
    if (fmt->precision.dot_number > length) {
      s21_strncat(p_str, p_source, length);
      *index_str += length;
    } else {
      s21_strncat(p_str, p_source, fmt->precision.dot_number);
      *index_str += fmt->precision.dot_number;
    }
  } else if (!fmt->precision.dot_enable) {
    if (fmt->flag.minus) {
      s21_strncat(p_str, p_source, length);
      *index_str += length;
    }
  }
}

void handle_width(char *p_str, int *index_str, int length, int count,
                  Format_Options *fmt) {
  if (fmt->width.number != 0 && fmt->precision.dot_number >= length) {
    while (length++ < fmt->width.number) {
      s21_strncat(p_str, " ", 1);
      (*index_str)++;
    }
  } else if (fmt->width.number != 0 && fmt->precision.dot_enable) {
    while (count++ < fmt->width.number) {
      s21_strncat(p_str, " ", 1);
      (*index_str)++;
    }
  } else {
    while (length++ < fmt->width.number) {
      s21_strncat(p_str, " ", 1);
      (*index_str)++;
    }
  }
}

void handle_output(char *p_str, const char *arg_s, int *index_str,
                   Format_Options *fmt) {
  int counter_length = (int)s21_strlen(arg_s);
  if (!fmt->flag.minus && !fmt->precision.dot_enable) {
    s21_strncat(p_str, arg_s, counter_length);
    *index_str += counter_length;
  } else if (!fmt->flag.minus) {
    if (fmt->precision.dot_number >= counter_length) {
      s21_strncat(p_str, arg_s, counter_length);
      *index_str += counter_length;
    } else {
      s21_strncat(p_str, arg_s, fmt->precision.dot_number);
      *index_str += fmt->precision.dot_number;
    }
  }
}

void handle_zero_precision(char *p_str, int *index_str, int *index_format,
                           Format_Options *fmt) {
  if (fmt->precision.dot_enable && fmt->precision.dot_number == 0) {
    s21_strncat(p_str, " ", 1);
    *index_str += fmt->precision.dot_number;
    (*index_format)++;
  }
}

void specifier_s(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format) {
  char *tmp_str = (char *)calloc(1024, sizeof(char));
  PANIC(tmp_str);

  if (tmp_str != NULL) {
    if (fmt->length.l) {
      wchar_t *arg_s = va_arg(factor, wchar_t *);
      for (int i = 0; arg_s[i] != '\0'; ++i) {
        tmp_str[i] = (char)arg_s[i];
      }
    } else {
      va_list factor_copy;
      va_copy(factor_copy, factor);
      s21_strncpy(tmp_str, va_arg(factor_copy, char *),
                  s21_strlen(va_arg(factor, char *)));
      va_end(factor_copy);
    }

    int length = 0;
    int i = 0;
    while (tmp_str[i++] != '\0') {
      length++;
    }
    int count = fmt->precision.dot_number;

    if (fmt->flag.plus || fmt->flag.zero) {
      fmt->flag.plus = 0;
      fmt->flag.zero = 0;
    }

    handle_precision_and_flag(p_str, tmp_str, index_str, length, fmt);
    handle_width(p_str, index_str, length, count, fmt);
    handle_output(p_str, tmp_str, index_str, fmt);
    handle_zero_precision(p_str, index_str, index_format, fmt);

    *index_format += 2;
    free(tmp_str);
    tmp_str = NULL;
  }
}