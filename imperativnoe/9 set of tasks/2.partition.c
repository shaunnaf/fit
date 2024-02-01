#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int n, int pivot) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    while (a[left] < pivot) {
      left++;
    }

    while (a[right] > pivot) {
      right--;
    }

    if (left <= right) {
      int temp = a[left];
      a[left] = a[right];
      a[right] = temp;

      left++;
      right--;
    }
  }
  return left;
}

int main() {
  int len_a, pivot;
  FILE *inputFile = fopen("input.txt", "rb");
  fread(&len_a, sizeof(int32_t), 1, inputFile);
  fread(&pivot, sizeof(int32_t), 1, inputFile);

  int *arr = malloc(len_a * sizeof(int32_t));

  fread(arr, sizeof(int32_t), len_a, inputFile);
  fclose(inputFile);

  int k = partition(arr, len_a, pivot);

  FILE *outputFile = fopen("output.txt", "wb");
  fwrite(&k, sizeof(int32_t), 1, outputFile);
  fwrite(arr, sizeof(int32_t), len_a, outputFile);
  fclose(outputFile);

  free(arr);

  return 0;
}
