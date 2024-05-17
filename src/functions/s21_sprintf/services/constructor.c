#include "../s21_sprintf.h"

Resources *constructor() {
  Resources *resources =
      (Resources *)calloc(sizeof(Resources), sizeof(Resources));
  PANIC(resources);

  if (resources != NULL) {
    resources->tmp_str = (char *)calloc(1024, sizeof(char));
    PANIC(resources->tmp_str);

    resources->des_str = (char *)calloc(1024, sizeof(char));
    PANIC(resources->des_str);

    resources->res_str = (char *)calloc(1024, sizeof(char));
    PANIC(resources->res_str);
  }

  return resources;
}
