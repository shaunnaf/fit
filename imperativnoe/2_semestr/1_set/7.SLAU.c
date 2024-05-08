#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *mf;
  int count_equations;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return 1;
  }
  if (fscanf(mf, "%d", &count_equations) != 1) {
    fprintf(stderr, "error_input");
    return 2;
  }
  double **matrix = malloc(count_equations * sizeof(double *));
  for (int i = 0; i < count_equations; i++) {
    matrix[i] = malloc(count_equations * sizeof(double));
  }
  double *answers_array = malloc(count_equations * sizeof(double));
  for (int i = 0; i < count_equations; i++) {
    for (int j = 0; i < count_equations; j++) {
      fscanf(mf, "%lf", &matrix[i][j]);
    }
    fscanf(mf, "%lf", &answers_array[i]);
  }
  for (int i = 0; i < count_equations; i++) {
    for (int j = 0; j < count_equations; j++) {
      if (matrix[i][j] != 0) {
        double coeff =
            matrix[i][j] / for (int k = 1 + i; k < count_equations; k++) {
          matrix[k][j] =
              matrix[k][j] - matrix[i][j] * matrix[k][j] / matrix[i][j];
        }
      }
    }
  }
  return 0;
}