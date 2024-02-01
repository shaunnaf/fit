#include <stdio.h>

typedef union {
  double double_number;
  long long long_number;
} Double_as_long;

int scan_count(FILE* mf, int* count);
double xor_double_with_int(double x, long long m);
void xor_numbers(FILE* mf, int count);

int main() {
  int count;
  FILE* mf = fopen("input.txt", "r");
  if (mf != NULL) {
    if (!scan_count(mf, &count)) {
      xor_numbers(mf, count);
    }
    fclose(mf);
  } else
    printf("error_open_file");
  return 0;
}

int scan_count(FILE* mf, int* count) {
  int error = 0;
  if (fscanf(mf, "%d", count) != 1) {
    error = 1;
  }
  return error;
}

int scan_numbers(FILE* mf, long long* numerator, long long* denominator,
                 long long* x_number) {
  int error = 0;
  if (fscanf(mf, "%lld/%lld xor %llx", numerator, denominator, x_number) != 3) {
    error = 1;
  }
  return error;
}

double xor_double_with_int(double hex, long long x_number) {
  Double_as_long xor ;
  xor.double_number = hex;
  xor.long_number ^= x_number;
  return xor.double_number;
}

void xor_numbers(FILE* mf, int count) {
  for (int i = 0; i < count; i++) {
    long long numerator, denominator, x_number;
    if (!scan_numbers(mf, &numerator, &denominator, &x_number)) {
      double hex = (double)numerator / denominator;
      double result = xor_double_with_int(hex, x_number);
      printf("%0.15g\n", result);
    } else {
      printf("error_read");
      break;
    }
  }
}
