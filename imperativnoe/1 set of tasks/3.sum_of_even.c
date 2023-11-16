#include <stdio.h>

int main(void) {
  int n, x;
  int summ = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x % 2 == 0) {
      summ += x;
    }
  }
  printf("%d", summ);
  return 0;
}
