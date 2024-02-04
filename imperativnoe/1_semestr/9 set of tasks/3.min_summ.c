#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

long long find_min_sum(int n, int* arr);
int compare(const void* a, const void* b);

int main() {
  FILE* mf = NULL;
  int count_numbers;
  mf = fopen("input.txt", "r");
  if (mf != NULL) {
    if (fscanf(mf, "%d", &count_numbers) == 1) {
      int* array = malloc(sizeof(int) * count_numbers);
      for (int i = 0; i < count_numbers; i++) {
        if (fscanf(mf, "%d", &array[i]) != 1) {
          break;
        }
      }
      fclose(mf);
      long long res = find_min_sum(count_numbers, array);
      mf = fopen("output.txt", "w");
      fprintf(mf, "%lld", res);
      fclose(mf);
      free(array);
    }
  }
  return 0;
}

long long find_min_sum(int n, int* arr) {
  qsort(arr, n, sizeof(int), compare);

  long long min_sum = 0;

  for (int i = 0; i < n - 1; i++) {
    min_sum += (long long)arr[i] * (n - i - 1);
  }

  return min_sum;
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }