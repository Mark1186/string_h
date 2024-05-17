#include "../s21_string.h"

int extract_decimal(const char **str, int width, int *counter);

unsigned int extract_unsigned_decimal(const char **str, int width,
                                      int *counter);

int extract_octal(const char **str, int width, int *counter);

char *extract_string(const char **str, int width, int *counter);

float extract_float(const char **str, int width, int *counter);

void *extract_pointer(const char **str, int width, int *counter);

int extract_hex(const char **str, int width, int *counter);

void delete_spaces(const char **str, int *counter);

void format_d_or_i(const char **str, int *count_chars, int *h_length,
                   int *l_length, int width, va_list args);

void format_c(const char **str, int *count_chars, va_list args, int *l_length);

void format_s(const char **str, int *count_chars, int width, va_list args,
              int *l_length);

void format_f_and_others(const char **str, int *count_chars, int width,
                         va_list args, int *L_length);

void format_o(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args);

void format_u(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args);

void format_x(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args);

void format_p(const char **str, int *count_chars, int width, va_list args);

void format_n(const char **str, int *count_chars, va_list args);

void format_percent_sign(const char **str, int *count_chars);

void format_not_asterisk(const char **str, const char **format, int width,
                         int *h_length, int *l_length, int *L_length,
                         int *count_chars, va_list args);

int s21_sscanf(const char *str, const char *format, ...);

int extract_decimal(const char **str, int width, int *counter) {
  int extracted_number = 0;
  int sign = (**str == '-')   ? ((*str)++, -1)
             : (**str == '+') ? ((*str)++, 1)
                              : 1;
  while (**str != '\0' && **str != ' ' && (**str >= '0' && **str <= '9')) {
    if (width != 0) {
      extracted_number = extracted_number * 10 + (**str - '0');
      width--;
    }
    (*str)++;
    (*counter)++;
  }
  return extracted_number * sign;
}

unsigned int extract_unsigned_decimal(const char **str, int width,
                                      int *counter) {
  unsigned int extracted_number = 0;

  while (**str != '\0' && **str != ' ' && (**str >= '0' && **str <= '9')) {
    if (width != 0) {
      extracted_number = extracted_number * 10 + (**str - '0');
      width--;
    }
    (*str)++;
    (*counter)++;
  }
  return extracted_number;
}

int extract_octal(const char **str, int width, int *counter) {
  int sign = (**str == '-')   ? ((*str)++, -1)
             : (**str == '+') ? ((*str)++, 1)
                              : 1;
  int extracted_number = 0;
  while (**str != '\0' && **str != ' ' && (**str >= '0' && **str <= '7')) {
    if (width != 0) {
      extracted_number = extracted_number * 8 + (**str - '0');
      width--;
    }
    (*str)++;
    (*counter)++;
  }
  return extracted_number * sign;
}

char *extract_string(const char **str, int width, int *counter) {
  char *extracted_string = (char *)calloc(STR_SIZE, sizeof(char));

  int i = 0;
  while (**str != '\0' && **str != ' ' &&
         ((**str >= 'a' && **str <= 'z') || (**str >= 'A' && **str <= 'Z'))) {
    if (width != 0) {
      extracted_string[i] = **str;
      i += 1;
      width -= 1;
    }
    (*str)++;
    (*counter)++;
  }
  extracted_string[i] = '\0';

  return extracted_string;
}

float extract_float(const char **str, int width, int *counter) {
  float extracted_float = 0.0f;
  float decimal_place = 0.1f;

  while (**str != '\0' && (**str >= '0' && **str <= '9') && width != 0) {
    extracted_float = extracted_float * 10.0f + (float)(**str - '0');
    width--;
    (*str)++;
    (*counter)++;
  }
  if (**str == '.') {
    (*str)++;
    (*counter)++;
    width--;
    while (**str != '\0' && **str >= '0' && **str <= '9' && width != 0) {
      extracted_float += (float)(**str - '0') * decimal_place;
      decimal_place *= 0.1f;
      width--;
      (*str)++;
      (*counter)++;
    }
  }
  if (**str == 'e' || **str == 'E') {
    (*str)++;
    (*counter)++;
    int e_number = 0;

    int sign = (**str == '-')   ? ((*str)++, -1)
               : (**str == '+') ? ((*str)++, 1)
                                : 1;
    (*counter)++;
    while (**str != '\0' && (**str >= '0' && **str <= '9')) {
      e_number = e_number * 10 + (**str - '0');
      (*str)++;
      (*counter)++;
    }
    extracted_float *= (float)pow(10, sign * e_number);
  }

  return extracted_float;
}

void *extract_pointer(const char **str, int width, int *counter) {
  void *ptr = NULL;
  int breakpoint = 0;
  uintptr_t value = 0;

  if (*(*str) == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *(str) += 2;
    *counter += 2;
    while (**str != '\0' && (isdigit(**str) || isalpha(**str)) && !breakpoint) {
      if (**str >= '0' && **str <= '9') {
        value = value * 16 + (**str - '0');
      } else if (**str >= 'a' && **str <= 'f') {
        value = value * 16 + (**str - 'a' + 10);
      } else if (**str >= 'A' && **str <= 'F') {
        value = value * 16 + (**str - 'A' + 10);
      } else {
        breakpoint = 1;
      }
      (*str)++;
      (*counter)++;
      if (width != 0) {
        ptr = (void *)value;
      }
    }
  } else {
    while (**str != '\0' && (isdigit(**str) || isalpha(**str)) && !breakpoint) {
      if (**str >= '0' && **str <= '9') {
        value = value * 16 + (**str - '0');
      } else if (**str >= 'a' && **str <= 'f') {
        value = value * 16 + (**str - 'a' + 10);
      } else if (**str >= 'A' && **str <= 'F') {
        value = value * 16 + (**str - 'A' + 10);
      } else {
        breakpoint = 1;
      }
      (*str)++;
      (*counter)++;
      if (width != 0) {
        ptr = (void *)value;
      }
    }
  }

  return ptr;
}

int extract_hex(const char **str, int width, int *counter) {
  int extracted_number = 0;
  while (**str != '\0' && **str != ' ' &&
         ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f') ||
          (**str >= 'A' && **str <= 'F'))) {
    int value = 0;
    if (**str >= '0' && **str <= '9') {
      value = **str - '0';
    } else if (**str >= 'a' && **str <= 'f') {
      value = **str - 'a' + 10;
    } else if (**str >= 'A' && **str <= 'F') {
      value = **str - 'A' + 10;
    }
    if (width != 0) {
      extracted_number = extracted_number * 16 + value;
      width--;
    }
    (*str)++;
    (*counter)++;
  }
  return extracted_number;
}

void delete_spaces(const char **str, int *counter) {
  while (**str != '\0' && **str == ' ') {
    (*str)++;
    (*counter)++;
  }
}

void length(int *h_length, int *l_length, int *L_length, const char **format) {
  if (*(*format) == 'h') {
    *h_length = 1;
    (*format)++;
  } else if (*(*format) == 'l') {
    *l_length = 1;
    (*format)++;
  } else if (*(*format) == 'L') {
    *L_length = 1;
    (*format)++;
  }
}

void format_d_decimal_part(const char **str, int *count_chars, int *h_length,
                           int *l_length, int width, va_list args) {
  if (*h_length) {
    short int *result_int = va_arg(args, short int *);
    *result_int = (short)extract_decimal(str, width, count_chars);
    *h_length = 0;
    *l_length = 0;
  } else if (*l_length) {
    long int *result_int = va_arg(args, long int *);
    *result_int = extract_decimal(str, width, count_chars);
    *l_length = 0;
  } else {
    int *result_int = va_arg(args, int *);
    *result_int = extract_decimal(str, width, count_chars);
    *l_length = 0;
  }
}

void format_d_or_i(const char **str, int *count_chars, int *h_length,
                   int *l_length, int width, va_list args) {
  delete_spaces(str, count_chars);
  if (*(*str) == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *(str) += 2;
    count_chars += 2;
    if (*h_length) {
      short int *result_hex = va_arg(args, short int *);
      *result_hex = (short)extract_hex(str, width, count_chars);
      *h_length = 0;
      *l_length = 0;
    } else if (*l_length) {
      long int *result_hex = va_arg(args, long int *);
      *result_hex = extract_hex(str, width, count_chars);
      *l_length = 0;
    } else {
      int *result_hex = va_arg(args, int *);
      *result_hex = extract_hex(str, width, count_chars);
      *l_length = 0;
    }
  } else if (*(*str) == '0') {
    (*str)++;
    count_chars += 1;
    if (*h_length) {
      unsigned short int *result_int = va_arg(args, unsigned short int *);
      *result_int = extract_octal(str, width, count_chars);
      *h_length = 0;
      *l_length = 0;
    } else if (*l_length) {
      unsigned long int *result_int = va_arg(args, unsigned long int *);
      *result_int = extract_octal(str, width, count_chars);
      *l_length = 0;
    } else {
      unsigned int *result_int = va_arg(args, unsigned int *);
      *result_int = extract_octal(str, width, count_chars);
      *l_length = 0;
    }
  } else {
    format_d_decimal_part(str, count_chars, h_length, l_length, width, args);
  }
}

void format_c(const char **str, int *count_chars, va_list args, int *l_length) {
  if (*l_length) {
    wchar_t *extracted_char = va_arg(args, wchar_t *);
    *extracted_char = (wchar_t)(*(*str));
    (*str)++;
    (*count_chars)++;
    *l_length = 0;
  } else {
    char *extracted_char = va_arg(args, char *);
    *extracted_char = *(*str);
    (*str)++;
    (*count_chars)++;
    *l_length = 0;
  }
}

void format_s(const char **str, int *count_chars, int width, va_list args,
              int *l_length) {
  delete_spaces(str, count_chars);
  if (*l_length) {
    wchar_t *result_string = (wchar_t *)extract_string(str, width, count_chars);
    s21_strncpy((char *)va_arg(args, wchar_t *), (char *)result_string,
                STR_SIZE);
    *l_length = 0;
    if (result_string != NULL) {
      free(result_string);
    }
  } else {
    char *result_string = extract_string(str, width, count_chars);
    s21_strncpy(va_arg(args, char *), result_string, STR_SIZE);
    *l_length = 0;
    if (result_string != NULL) {
      free(result_string);
    }
  }
}

void format_f_and_others(const char **str, int *count_chars, int width,
                         va_list args, int *L_length) {
  delete_spaces(str, count_chars);
  if (*L_length) {
    long double *result_double = va_arg(args, long double *);
    *result_double = extract_float(str, width, count_chars);
    *L_length = 0;
  } else {
    float *result_float = va_arg(args, float *);
    *result_float = extract_float(str, width, count_chars);
  }
}

void format_o(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args) {
  delete_spaces(str, count_chars);
  if (*h_length) {
    short int *result_octal = va_arg(args, short int *);
    *result_octal = (short)extract_octal(str, width, count_chars);
    *h_length = 0;
  } else if (*l_length) {
    long int *result_octal = va_arg(args, long int *);
    *result_octal = extract_octal(str, width, count_chars);
    *l_length = 0;
  } else {
    int *result_octal = va_arg(args, int *);
    *result_octal = extract_octal(str, width, count_chars);
  }
}

void format_u(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args) {
  delete_spaces(str, count_chars);
  if (*h_length) {
    unsigned short int *result_decimal = va_arg(args, unsigned short int *);
    *result_decimal = extract_unsigned_decimal(str, width, count_chars);
    *h_length = 0;
  } else if (*l_length) {
    unsigned long int *result_decimal = va_arg(args, unsigned long int *);
    *result_decimal = extract_unsigned_decimal(str, width, count_chars);
    *l_length = 0;
  } else {
    unsigned int *result_decimal = va_arg(args, unsigned int *);
    *result_decimal = extract_unsigned_decimal(str, width, count_chars);
  }
}

void format_x(const char **str, int *count_chars, int *h_length, int *l_length,
              int width, va_list args) {
  delete_spaces(str, count_chars);
  if (*(*str) == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *(str) += 2;
    count_chars += 2;
    if (*h_length) {
      unsigned short int *result_hex = va_arg(args, unsigned short int *);
      *result_hex = extract_hex(str, width, count_chars);
      *h_length = 0;
    } else if (*l_length) {
      unsigned long int *result_hex = va_arg(args, unsigned long int *);
      *result_hex = extract_hex(str, width, count_chars);
      *l_length = 0;
    } else {
      unsigned int *result_hex = va_arg(args, unsigned int *);
      *result_hex = extract_hex(str, width, count_chars);
    }
  } else {
    if (*h_length) {
      unsigned short int *result_hex = va_arg(args, unsigned short int *);
      *result_hex = extract_hex(str, width, count_chars);
      *h_length = 0;
    } else if (*l_length) {
      unsigned long int *result_hex = va_arg(args, unsigned long int *);
      *result_hex = extract_hex(str, width, count_chars);
      *l_length = 0;
    } else {
      unsigned int *result_hex = va_arg(args, unsigned int *);
      *result_hex = extract_hex(str, width, count_chars);
    }
  }
}

void format_p(const char **str, int *count_chars, int width, va_list args) {
  delete_spaces(str, count_chars);
  void **result_ptr = va_arg(args, void **);
  *result_ptr = extract_pointer(str, width, count_chars);
}

void format_n(const char **str, int *count_chars, va_list args) {
  delete_spaces(str, count_chars);
  int *result_number = va_arg(args, int *);
  *result_number = *count_chars;
}

void format_percent_sign(const char **str, int *count_chars) {
  delete_spaces(str, count_chars);
  (*str)++;
  (*count_chars)++;
}

void format_not_asterisk(const char **str, const char **format, int width,
                         int *h_length, int *l_length, int *L_length,
                         int *count_chars, va_list args) {
  while (isdigit(*(*format))) {
    if (width == 1000) {
      width = 0;
    }
    width = width * 10 + (*(*format) - '0');
    (*format)++;
  }
  length(h_length, l_length, L_length, format);
  if (*(*format) == 'd' || *(*format) == 'i') {
    format_d_or_i(str, count_chars, h_length, l_length, width, args);
  } else if (*(*format) == 'c') {
    format_c(str, count_chars, args, l_length);
  } else if (*(*format) == 's') {
    format_s(str, count_chars, width, args, l_length);
  } else if (*(*format) == 'f' || *(*format) == 'g' || *(*format) == 'e' ||
             *(*format) == 'G' || *(*format) == 'E') {
    format_f_and_others(str, count_chars, width, args, L_length);
  } else if (*(*format) == 'o') {
    format_o(str, count_chars, h_length, l_length, width, args);
  } else if (*(*format) == 'u') {
    format_u(str, count_chars, h_length, l_length, width, args);
  } else if (*(*format) == 'x' || *(*format) == 'X') {
    format_x(str, count_chars, h_length, l_length, width, args);
  } else if (*(*format) == 'p') {
    format_p(str, count_chars, width, args);
  } else if (*(*format) == 'n') {
    format_n(str, count_chars, args);
  } else if (*(*format) == '%') {
    format_percent_sign(str, count_chars);
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count_chars = 0;
  int h_length = 0;
  int l_length = 0;
  int L_length = 0;

  while (*format != '\0') {
    if (*format == '%') {
      int width = 1000;
      format++;
      if (*format != '*') {
        format_not_asterisk(&str, &format, width, &h_length, &l_length,
                            &L_length, &count_chars, args);
      }
    }
    format++;
  }

  va_end(args);
  return 1;
}
