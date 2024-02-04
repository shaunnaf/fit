#include <stdio.h>

int gcd(int a, int b);

int main() {
  int count_tests, number_a, number_b;
  if (scanf("%d", &count_tests) != 1) {
    fprintf(stderr, "error input");
    return 1;
  }
  for (int i = 0; i < count_tests; i++) {
    if (scanf("%d %d", &number_a, &number_b) != 2) {
      fprintf(stderr, "error input");
      return 1;
    }
    printf("%d\n", gcd(number_a, number_b));
  }
  return 0;
}

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }