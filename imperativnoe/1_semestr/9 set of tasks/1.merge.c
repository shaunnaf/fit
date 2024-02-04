#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int merge(const int *a, int ak, const int *b, int bk, int *res) {
  int i = 0, j = 0, k = 0;
  while (i < ak && j < bk) {
    if (a[i] <= b[j]) {
      res[k] = a[i];
      i++;
    } else {
      res[k] = b[j];
      j++;
    }
    k++;
  }

  while (i < ak) {
    res[k] = a[i];
    i++;
    k++;
  }

  while (j < bk) {
    res[k] = b[j];
    j++;
    k++;
  }

  return k;
}

int main() {
  int len_a, len_b;
  FILE *inputFile = fopen("input.txt", "rb");
  fread(&len_a, sizeof(int32_t), 1, inputFile);
  fread(&len_b, sizeof(int32_t), 1, inputFile);

  int *a = malloc(len_a * sizeof(int));
  int *b = malloc(len_b * sizeof(int));

  fread(a, sizeof(int32_t), len_a, inputFile);
  fread(b, sizeof(int32_t), len_b, inputFile);

  fclose(inputFile);

  int *result = malloc((len_a + len_b) * sizeof(int32_t));

  int resultSize = merge(a, len_a, b, len_b, result);

  FILE *outputFile = fopen("output.txt", "wb");
  fwrite(result, sizeof(int32_t), resultSize, outputFile);
  fclose(outputFile);

  free(a);
  free(b);
  free(result);

  return 0;
}
