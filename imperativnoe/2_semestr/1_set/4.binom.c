#include <stdio.h>
#include <stdlib.h>

void triangle_pascal(unsigned long long ***binom, int module);

int main() {
  FILE *mf, *mf2;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error open file");
    return 1;
  }
  int module, count_tests, n, k;
  if (fscanf(mf, "%d %d", &module, &count_tests) != 2) {
    fprintf(stderr, "error_input");
    return 1;
  }
  unsigned long long **matrix = malloc(sizeof(unsigned long long *) * 2001);
  for (int i = 0; i < 2001; i++) {
    matrix[i] = malloc(sizeof(unsigned long long) * 2001);
  }
  triangle_pascal(&matrix, module);
  mf2 = fopen("output.txt", "w");
  for (int i = 0; i < count_tests; i++) {
    if (fscanf(mf, "%d %d", &n, &k) != 2) {
      fprintf(stderr, "error_input");
      for (int i = 0; i < 2001; i++) {
        free(matrix[i]);
      }
      free(matrix);
      return 1;
    }
    if (k > n || k < 0) {
      fprintf(mf2, "0\n");
    } else {
      fprintf(mf2, "%lld\n", ((matrix[n][k]) % module));
    }
  }
  for (int i = 0; i < 2001; i++) {
    free(matrix[i]);
  }
  free(matrix);
  fclose(mf2);
  fclose(mf);
  return 0;
}

void triangle_pascal(unsigned long long ***binom, int module) {
  for (int i = 0; i < 2001; i++) {
    (*binom)[i][0] = (*binom)[i][i] = 1;
  }
  for (int i = 2; i < 2001; i++) {
    for (int j = 1; j < i; j++) {
      (*binom)[i][j] =
          ((*binom)[i - 1][j - 1] % module) + ((*binom)[i - 1][j] % module);
    }
  }
}
