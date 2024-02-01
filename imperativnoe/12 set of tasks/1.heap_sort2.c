#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int *array, int count_numbers, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < count_numbers && array[left] > array[largest]) largest = left;

  if (right < count_numbers && array[right] > array[largest]) largest = right;

  if (largest != i) {
    swap(&array[i], &array[largest]);
    heapify(array, count_numbers, largest);
  }
}

void heapSort(int *array, int count_numbers) {
  for (int i = count_numbers / 2 - 1; i >= 0; i--)
    heapify(array, count_numbers, i);

  for (int i = count_numbers - 1; i > 0; i--) {
    swap(&array[0], &array[i]);
    heapify(array, i, 0);
  }
}

int main() {
  FILE *inputFile, *outputFile;

  inputFile = fopen("input.txt", "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error opening input file.\n");
    return 1;
  }

  outputFile = fopen("output.txt", "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Error opening output file.\n");
    fclose(inputFile);
    return 1;
  }

  int count_numbers;
  fscanf(inputFile, "%d", &count_numbers);
  int *array = malloc(count_numbers * sizeof(int));

  for (int i = 0; i < count_numbers; i++) {
    fscanf(inputFile, "%d", &array[i]);
  }
  heapSort(array, count_numbers);

  for (int i = 0; i < count_numbers; i++) {
    fprintf(outputFile, "%d ", array[i]);
  }
  free(array);
  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
