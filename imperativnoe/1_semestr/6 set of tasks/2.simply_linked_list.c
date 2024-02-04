#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *value;
  int node;
} node;

int scan_count_tests(FILE *mf, int *count_tests);
int scan_count(FILE *mf, int *count_numbers_in_array, int *first_index,
               int *count_operations);
int add_data(FILE *mf, node *array, int count_numbers_in_array);
void print_answer(FILE *mf2, node *array, int count_number_in_array,
                  int first_index);
int processing_operation(FILE *mf, FILE *mf2, node *array,
                         int *count_numbers_in_array, int *first_index,
                         int *curr_numbers_in_array);

int main(void) {
  FILE *mf;
  mf = fopen("input.txt", "r");
  if (mf == NULL)
    printf("error_open_file");
  else {
    FILE *mf2 = fopen("output.txt", "w");
    int count_numbers_in_array, first_index, count_tests, count_operations;
    if (scan_count_tests(mf, &count_tests)) {
      printf("error");
    } else {
      for (int i = 0; i < count_tests; i++) {
        if (scan_count(mf, &count_numbers_in_array, &first_index,
                       &count_operations)) {
          printf("error");
        } else {
          int curr_numbers_in_array = count_numbers_in_array;
          node *array = malloc(sizeof(node) *
                               (count_numbers_in_array + count_operations));
          if (!add_data(mf, array, count_numbers_in_array)) {
            if (count_operations == 0) {
              fprintf(mf2, "===\n");
            } else {
              for (int j = 0; j < count_operations; j++) {
                processing_operation(mf, mf2, array, &count_numbers_in_array,
                                     &first_index, &curr_numbers_in_array);
              }
              fprintf(mf2, "===\n");
            }
            print_answer(mf2, array, curr_numbers_in_array, first_index);
            if (i == count_tests - 1)
              fprintf(mf2, "===");
            else
              fprintf(mf2, "===\n");
            free(array);
          } else
            break;
        }
      }
    }
    fclose(mf);
    fclose(mf2);
  }
  return 0;
}

int add_data(FILE *mf, node *array, int count_numbers_in_array) {
  int error = 0;
  for (int i = 0; i < count_numbers_in_array; i++) {
    char *value = (char *)malloc(7);
    int index;
    int len = 0;
    char c = fgetc(mf);
    c = fgetc(mf);
    while (c != ' ') {
      value[len] = c;
      len += 1;
      c = fgetc(mf);
    }
    if (fscanf(mf, "%d", &index) != 1) {
      error = 1;
      break;
    }
    array[i].value = value;
    array[i].node = index;
  }
  return error;
}

void print_answer(FILE *mf2, node *array, int count_number_in_array,
                  int first_index) {
  int index = first_index;
  for (int i = 0; i < count_number_in_array; i++) {
    fprintf(mf2, "%s\n", array[index].value);
    index = array[index].node;
  }
}

int scan_count(FILE *mf, int *count_numbers_in_array, int *first_index,
               int *count_operations) {
  int error = 0;
  if (fscanf(mf, "%d %d %d", count_numbers_in_array, first_index,
             count_operations) != 3)
    error = 1;
  return error;
}

int scan_count_tests(FILE *mf, int *count_tests) {
  int error = 0;
  if (fscanf(mf, "%d", count_tests) != 1) {
    error = 1;
  }
  return error;
}

int processing_operation(FILE *mf, FILE *mf2, node *array,
                         int *count_numbers_in_array, int *first_index,
                         int *curr_numbers_in_array) {
  int operation, index;
  int error = 0;
  char *value = (char *)malloc(7);
  if (fscanf(mf, "%d %d", &operation, &index) != 2) {
    error = 1;
  } else {
    if (operation == 1) {
      fprintf(mf2, "%s\n", array[array[index].node].value);
      if (index == -1) {
        *first_index = array[*first_index].node;
      } else {
        array[index].node = array[array[index].node].node;
      }
      *curr_numbers_in_array -= 1;
    } else if (operation == 0) {
      int len = 0;
      char c = fgetc(mf);
      c = fgetc(mf);
      while (c != '\n' && c != EOF) {
        value[len] = c;
        len += 1;
        c = fgetc(mf);
      }
      array[*count_numbers_in_array].value = value;
      if (index == -1) {
        array[*count_numbers_in_array].node = *first_index;
        *first_index = *count_numbers_in_array;
      } else {
        array[*count_numbers_in_array].node = array[index].node;
        array[index].node = *count_numbers_in_array;
      }
      fprintf(mf2, "%d\n", *count_numbers_in_array);
      *count_numbers_in_array += 1;
      *curr_numbers_in_array += 1;
    } else
      error = 1;
  }
  return error;
}
