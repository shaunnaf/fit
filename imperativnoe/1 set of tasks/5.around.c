#include <stdio.h>

int main(void) {
  float a, b, res;
  scanf("%f %f", &a, &b);
  int r = (int)a % (int)b;
  res = a / b;
  if (res >= 0) {
    if (r == 0) {
      printf("%d %d %d", (int)res, (int)res, (int)res);
    } else {
      printf("%d %d %d", (int)res, (int)(res + 1), (int)res);
    }
  } else {
    if (r == 0) {
      printf("%d %d %d", (int)res, (int)res, (int)res);
    } else {
      printf("%d %d %d", (int)res - 1, (int)res, (int)res);
    }
  }
  if (r < 0) {
    r += b;
  }
  printf(" %d", r);
  return 0;
}
