#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  double value;
  int index;
} node;

int scan_count_tests(int *count_tests);
int scan_count(int *count_numbers_in_array, int *first_index,
               int *count_operations);
int scan_data(double *value, int *index);
void add_data(node *array, int count_numbers_in_array);
void print_answer(node *array, int count_number_in_array, int first_index);

int main() {
  int count_numbers_in_array, first_index, count_tests, count_operations;
  if (scan_count_tests(&count_tests)) {
    printf("error");
  } else {
    for (int i = 0; i < count_tests; i++) {
      if (scan_count(&count_numbers_in_array, &first_index,
                     &count_operations)) {
        printf("error");
      } else {
        if (count_operations == 0) {
          printf("===\n");
        } else {
        }
        node *array = malloc(sizeof(node) * count_numbers_in_array);
        add_data(array, count_numbers_in_array);
        print_answer(array, count_numbers_in_array, first_index);
        free(array);
      }
    }
  }
  return 0;
}

void add_data(node *array, int count_numbers_in_array) {
  for (int i = 0; i < count_numbers_in_array; i++) {
    double value = 0;
    int index;
    if (scan_data(&value, &index)) {
      printf("error");
    } else {
      array[i].value = value;
      array[i].index = index;
    }
  }
}

void print_answer(node *array, int count_number_in_array, int first_index) {
  int index = first_index;
  for (int i = 0; i < count_number_in_array; i++) {
    printf("%0.3lf\n", array[index].value);
    index = array[index].index;
  }
}

int scan_count(int *count_numbers_in_array, int *first_index,
               int *count_operations) {
  int error = 0;
  if (scanf("%d %d %d", count_numbers_in_array, first_index,
            count_operations) != 3) {
    error = 1;
  }
  return error;
}

int scan_data(double *value, int *index) {
  int error = 0;
  if (scanf("%lf %d", value, index) != 2) {
    error = 1;
  }
  return error;
}

int scan_count_tests(int *count_tests) {
  int error = 0;
  if (scanf("%d", count_tests) != 1) {
    error = 1;
  }
  return error;
}
