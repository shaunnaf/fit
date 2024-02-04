#include <stdio.h>

int scan_data(FILE *mf, int *count_tests, int *module);
int check_module(int number_a, int module);

int main() {
  int count_tests, module, number_a;
  FILE *mf;
  mf = fopen("input.txt", "r");
  if (scan_data(mf, &count_tests, &module)) {
    fprintf(stderr, "error");
    return 1;
  }
  for (int i = 0; i < count_tests; i++) {
    if (!fscanf(mf, "%d", &number_a)) {
      fprintf(stderr, "error");
      return 1;
    } else {
      printf("%d\n", check_module(number_a, module));
    }
  }
  return 0;
}

int scan_data(FILE *mf, int *count_tests, int *module) {
  int error = 0;
  if (fscanf(mf, "%d %d", count_tests, module) != 2) {
    error = 1;
  }
  return error;
}

int check_module(int number_a, int module) {
  int module_copy = module;
  int temp, delenie;
  int x0 = 0;
  int x1 = 1;

  if (module == 1 || number_a == 0) return -1;

  while (number_a > 1) {
    delenie = number_a / module;
    temp = module;
    module = number_a % module;
    number_a = temp;
    temp = x0;
    x0 = x1 - delenie * x0;
    x1 = temp;
  }

  while (x1 < 0) x1 += module_copy;

  return x1;
}