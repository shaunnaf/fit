#include <stdio.h>
#include <stdlib.h>

void reading_count(int *count, int *error);
void reading_numbers(int *error, int count, int *array);
void counting(int *array, int count);

int main(void) {
  int count, error;
  error = 0;
  reading_count(&count, &error);
  if (error == 0) {
    int *array = (int *)malloc(count * sizeof(int));
    reading_numbers(&error, count, array);
    if (error == 0) {
      counting(array, count);
    } else {
      printf("ERROR");
    }
    free(array);
  } else {
    printf("ERROR");
  }
  return 0;
}

void reading_count(int *count, int *error) {
  if (scanf("%d", count) != 1 || *count < 1 || *count > 100) {
    *error = 1;
  }
}

void reading_numbers(int *error, int count, int *array) {
  for (int i = 0; i < count; i++) {
    if (scanf("%d", &array[i]) != 1) {
      *error = 1;
      break;
    }
  }
}

void counting(int *array, int count) {
  int answer = 0;
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (array[i] > array[j]) {
        answer += 1;
      }
    }
    printf("%d ", answer);
    answer = 0;
  }
  printf("0");
}
