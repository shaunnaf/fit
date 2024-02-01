#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **values;
  int count;
} dict;

int scan_count_elements(FILE *mf, int *count_elements);
int scan_data(FILE *mf, int count_elements, dict *array);
void sort(dict *array, int count_elements);
void print_array(dict *array, int count_elements);
void free_array(dict *array, int count_elements);

int main() {
  FILE *mf;
  int count_elements;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
  } else {
    if (scan_count_elements(mf, &count_elements)) {
      fprintf(stderr, "error_read_count");
    } else {
      dict *array = calloc(1000001, sizeof(dict));
      if (scan_data(mf, count_elements, array)) {
        fprintf(stderr, "error_read_data");
      } else {
        print_array(array, count_elements);
      }
      free_array(array, count_elements);
    }
    fclose(mf);
  }
  return 0;
}

int scan_count_elements(FILE *mf, int *count_elements) {
  int error = 0;
  if (fscanf(mf, "%d", count_elements) != 1) {
    error = 1;
  }
  return error;
}

int scan_data(FILE *mf, int count_elements, dict *array) {
  int error = 0;
  for (int i = 0; i < 1000001; i++) {
    array[i].values = malloc(sizeof(char *) * 1);
  }
  for (int i = 0; i < count_elements; i++) {
    int x;
    fscanf(mf, "%d ", &x);
    char buf[7];
    if (fscanf(mf, "%s", buf) == 1) {
      array[x].values[array[x].count] = strdup(buf);
      array[x].count++;
      array[x].values =
          realloc(array[x].values, sizeof(char *) * (array[x].count + 1));
    } else {
      fprintf(stderr, "error_input");
      break;
    }
  }
  return error;
}

void print_array(dict *array, int count_elements) {
  for (int i = 0; i < 1000001; i++) {
    if (array[i].count != 0) {
      for (int j = 0; j < array[i].count; j++) {
        printf("%d ", i);
        printf("%s\n", array[i].values[j]);
      }
    }
  }
}

void free_array(dict *array, int count_elements) {
  for (int i = 0; i < count_elements; i++) {
    for (int j = 0; j < array[i].count; j++) {
      free(array[i].values[j]);
    }
    free(array[i].values);
  }
  free(array);
}
