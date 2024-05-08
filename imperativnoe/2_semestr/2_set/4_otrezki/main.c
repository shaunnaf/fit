#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

extern void Init(const int* arr, int n);
extern int Query(int l, int64_t sum);

int64_t* sum_array;
int count_numbers;

int main() {
  int count_questions;
  FILE* mf;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return 1;
  }
  if (fscanf(mf, "%d %d", &count_numbers, &count_questions) != 2) {
    fprintf(stderr, "error_input");
    fclose(mf);
    return 2;
  }
  int* array = malloc(count_numbers * sizeof(int));
  for (int i = 0; i < count_numbers; i++) {
    if (fscanf(mf, "%d", &array[i]) != 1) {
      fprintf(stderr, "error_input");
      fclose(mf);
      free(array);
      return 3;
    }
  }
  int l;
  unsigned long long max_sum;
  Init(array, count_numbers);
  FILE* mf2;
  mf2 = fopen("output.txt", "w");
  for (int i = 0; i < count_questions; i++) {
    if (fscanf(mf, "%d %llu", &l, &max_sum) != 2) {
      fprintf(stderr, "error_input");
      fclose(mf);
      free(array);
      free(sum_array);
      return 4;
    }
    fprintf(mf2, "%d\n", Query(l, max_sum));
  }
  fclose(mf);
  fclose(mf2);
  free(sum_array);
  free(array);
  return 0;
}