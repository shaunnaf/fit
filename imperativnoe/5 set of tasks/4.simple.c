#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int scan_count(int *range, int *count);
int calculate(int count, bool *array);
void eratosfen(int range, bool *array);

int main(void) {
  int count, range;
  if (!scan_count(&range, &count)) {
    bool *array = calloc(range + 1, sizeof(bool));
    eratosfen(range, array);
    calculate(count, array);
    free(array);
  } else {
    printf("error");
  }
  return 0;
}

void eratosfen(int range, bool *array) {
  array[0] = true;
  array[1] = true;
  int number = 2;
  while (number * number <= range) {
    int curr_number = number + number;
    while (curr_number <= range) {
      array[curr_number] = true;
      curr_number += number;
    }
    number++;
  }
}

int scan_count(int *range, int *count) {
  int error = 0;
  if (scanf("%d %d", range, count) != 2) {
    error = 1;
  }
  return error;
}

int calculate(int count, bool *array) {
  int number;
  int error = 0;
  for (int i = 0; i < count; i++) {
    if (scanf("%d", &number) != 1) {
      error = 1;
      break;
    }
    if (array[number]) {
      printf("%d not\n", number);
    } else {
      printf("%d prime\n", number);
    }
  }
  return error;
}
