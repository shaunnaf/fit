#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double answer[1002];
} binoms;

int scan_count(int *count);
void triangle_pascal(binoms *binom);
int scan_and_print_numbers(binoms *binom, int count);

int main(void) {
  binoms binom[1002];
  int count;
  if (!scan_count(&count)) {
    triangle_pascal(binom);
    if (scan_and_print_numbers(binom, count)) {
      printf("ERROR");
    }
  } else {
    printf("ERROR");
  }
  return 0;
}

int scan_count(int *count) {
  int error = 0;
  if (scanf("%d", count) != 1) {
    error = 1;
  }
  return error;
}

int scan_and_print_numbers(binoms *binom, int count) {
  int n, k, error;
  error = 0;
  for (int i = 0; i < count; i++) {
    if (scanf("%d %d", &n, &k) != 2) {
      error = 1;
      break;
    }
    printf("%0.10g\n", binom[n].answer[k]);
  }
  return error;
}

void triangle_pascal(binoms *binom) {
  for (int i = 0; i < 1001; i++) {
    binom[i].answer[0] = binom[i].answer[i] = 1;
  }
  for (int i = 2; i < 1001; i++) {
    for (int j = 1; j < i; j++) {
      binom[i].answer[j] = binom[i - 1].answer[j - 1] + binom[i - 1].answer[j];
    }
  }
}
