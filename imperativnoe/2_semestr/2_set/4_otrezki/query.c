#include <inttypes.h>

extern int64_t Sum(int l, int r);
extern int64_t *sum_array;
extern int count_numbers;

int Query(int l, int64_t sum) {
  int low = l;
  int high = count_numbers;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (Sum(l, mid) <= sum) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}