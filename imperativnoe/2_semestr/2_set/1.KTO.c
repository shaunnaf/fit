#include <stdio.h>
#include <stdlib.h>

long long chinese_remainder_theorem(int k, long long M, long long* arr_moduls,
                                    long long* arr_ost);
long long extended_gcd(long long a, long long b, long long* x, long long* y);

int main() {
  FILE* mf;
  unsigned long long count_moduls;
  unsigned long long M = 1;

  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return 1;
  }
  if (fscanf(mf, "%lld", &count_moduls) != 1) {
    fprintf(stderr, "error_input");
    fclose(mf);
    return 2;
  }
  long long* arr_moduls = malloc(count_moduls * sizeof(unsigned long long));
  long long* arr_ost = malloc(count_moduls * sizeof(unsigned long long));
  for (unsigned long long j = 0; j < count_moduls; j++) {
    fscanf(mf, "%lld", &arr_moduls[j]);
    M *= arr_moduls[j];
  }
  for (unsigned long long j = 0; j < count_moduls; j++) {
    fscanf(mf, "%lld", &arr_ost[j]);
  }
  long long x = chinese_remainder_theorem(count_moduls, M, arr_moduls, arr_ost);
  printf("%lld", x);
  free(arr_moduls);
  free(arr_ost);
  fclose(mf);
  return 0;
}

long long extended_gcd(long long a, long long b, long long* x, long long* y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  long long x1, y1;
  long long gcd = extended_gcd(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return gcd;
}

long long chinese_remainder_theorem(int count_moduls, long long M,
                                    long long* arr_moduls, long long* arr_ost) {
  long long X = 0;
  for (int i = 0; i < count_moduls; ++i) {
    long long m = M / arr_moduls[i];
    long long x, y;
    extended_gcd(m, arr_moduls[i], &x, &y);
    X += arr_ost[i] * m * x;
  }

  return (X % M + M) % M;
}
