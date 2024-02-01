#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  double value;
  int node;
} node;

int scan_count(FILE *mf, int *count_numbers_in_array, int *first_index);
int scan_data(FILE *mf, double *value, int *index);
void add_data(FILE *mf, node *array, int count_numbers_in_array);
void print_answer(node *array, int count_number_in_array, int first_index);

int main(void) {
  FILE *mf;
  mf = fopen("input.txt", "r");
  if (mf == NULL)
    printf("error_open_file");
  else {
    int count_numbers_in_array, first_index;
    if (scan_count(mf, &count_numbers_in_array, &first_index)) {
      printf("error");
    } else {
      node *array = malloc(sizeof(node) * count_numbers_in_array);
      add_data(mf, array, count_numbers_in_array);
      print_answer(array, count_numbers_in_array, first_index);
      free(array);
    }
    fclose(mf);
  }
  return 0;
}

void add_data(FILE *mf, node *array, int count_numbers_in_array) {
  for (int i = 0; i < count_numbers_in_array; i++) {
    double value = 0;
    int index;
    if (scan_data(mf, &value, &index)) {
      printf("error");
      break;
    } else {
      array[i].value = value;
      array[i].node = index;
    }
  }
}

void print_answer(node *array, int count_number_in_array, int first_index) {
  int index = first_index;
  for (int i = 0; i < count_number_in_array; i++) {
    printf("%0.3lf\n", array[index].value);
    index = array[index].node;
  }
}

int scan_count(FILE *mf, int *count_numbers_in_array, int *first_index) {
  int error = 0;
  if (fscanf(mf, "%d %d", count_numbers_in_array, first_index) != 2) {
    error = 1;
  }
  return error;
}

int scan_data(FILE *mf, double *value, int *index) {
  int error = 0;
  if (fscanf(mf, "%lf %d", value, index) != 2) {
    error = 1;
  }
  return error;
}
