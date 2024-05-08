#include <inttypes.h>
#include <stdlib.h>

extern int64_t* sum_array;

void Init(const int* arr, int n) {
  sum_array = malloc(n * sizeof(int64_t));
  sum_array[0] = arr[0];
  for (int i = 1; i < n; i++) {
    sum_array[i] = sum_array[i - 1] + arr[i];
  }
}

int64_t Sum(int l, int r) {
  if (l == 0) return sum_array[r];
  return sum_array[r] - sum_array[l - 1];
}