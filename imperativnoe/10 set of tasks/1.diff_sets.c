#include <stdio.h>
#include <stdlib.h>

int comp(const void *i, const void *j);

int binarySearch(int *arr, int size, int key);

int main() {
  FILE *mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return 1;
  }

  int count_numbers_in_array_a, count_numbers_in_array_b;
  if (fscanf(mf, "%d", &count_numbers_in_array_a) != 1) {
    fprintf(stderr, "error_input");
    fclose(mf);
    return 1;
  }

  int *array_a = malloc(sizeof(int) * count_numbers_in_array_a);
  for (int i = 0; i < count_numbers_in_array_a; i++) {
    if (fscanf(mf, "%d", &array_a[i]) != 1) {
      fprintf(stderr, "error input in array");
      free(array_a);
      fclose(mf);
      return 1;
    }
  }

  qsort(array_a, count_numbers_in_array_a, sizeof(int), comp);

  if (fscanf(mf, "%d", &count_numbers_in_array_b) != 1) {
    fprintf(stderr, "error_input");
    free(array_a);
    fclose(mf);
    return 1;
  }

  int *array_b = malloc(sizeof(int) * count_numbers_in_array_b);
  for (int i = 0; i < count_numbers_in_array_b; i++) {
    if (fscanf(mf, "%d", &array_b[i]) != 1) {
      fprintf(stderr, "error_input_array_b");
      free(array_a);
      free(array_b);
      fclose(mf);
      return 1;
    }
  }

  qsort(array_b, count_numbers_in_array_b, sizeof(int), comp);

  int *array_answer = NULL;
  int count_answer = 0;

  if (binarySearch(array_b, count_numbers_in_array_b, array_a[0]) == -1) {
    array_answer = realloc(array_answer, sizeof(int) * (count_answer + 1));
    array_answer[count_answer++] = array_a[0];
  }

  for (int i = 1; i < count_numbers_in_array_a; i++) {
    if ((array_a[i] != array_a[i - 1]) &&
        (binarySearch(array_b, count_numbers_in_array_b, array_a[i]) == -1)) {
      array_answer = realloc(array_answer, sizeof(int) * (count_answer + 1));
      array_answer[count_answer++] = array_a[i];
    }
  }

  fclose(mf);
  mf = fopen("output.txt", "w");
  fprintf(mf, "%d\n", count_answer);

  for (int i = 0; i < count_answer; i++) {
    fprintf(mf, "%d", array_answer[i]);
    if (i < count_answer - 1) {
      fprintf(mf, " ");
    }
  }

  fprintf(mf, "\n");

  free(array_a);
  free(array_b);
  free(array_answer);
  fclose(mf);

  return 0;
}

int comp(const void *i, const void *j) { return *(int *)i - *(int *)j; }

int binarySearch(int *arr, int size, int key) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
