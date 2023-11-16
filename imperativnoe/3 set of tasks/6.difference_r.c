#include <stdio.h>
#include <stdlib.h>

int answer(void);
void reading_count(int *count, int *error);
void reading_numbers(int *array_numbers, int count, int *error);
void reading_numbers_b(int *array_numbers, int count, int *error);
void compare(int count_a, int *array_numbers_a, int *array_numbers_b,
             int *array_answer, int *count_answer);
void quickSort(int *numbers, int left, int right);
void print_answer(int count_answer, int *array_answer);

int main(void) {
  if (answer()) {
    printf("ERROR");
  }
  return 0;
}

int answer(void) {
  int count_a, count_b, count_answer, error;
  count_answer = error = 0;
  int *array_numbers_a = NULL;
  int *array_numbers_b = NULL;
  int *array_answer = NULL;

  reading_count(&count_a, &error);
  if (error != 1) {
    array_numbers_a = (int *)malloc(count_a * sizeof(int));
    reading_numbers(array_numbers_a, count_a, &error);
    if (error != 1) {
      reading_count(&count_b, &error);
      if (error != 1) {
        array_numbers_b = (int *)calloc(100001, sizeof(int));
        reading_numbers_b(array_numbers_b, count_b, &error);
        if (error != 1) {
          array_answer = (int *)malloc(count_a * sizeof(int));
          compare(count_a, array_numbers_a, array_numbers_b, array_answer,
                  &count_answer);
          print_answer(count_answer, array_answer);
          free(array_answer);
        }
        free(array_numbers_b);
      }
    }
    free(array_numbers_a);
  }
  return error;
}

void compare(int count_a, int *array_numbers_a, int *array_numbers_b,
             int *array_answer, int *count_answer) {
  for (int i = 0; i < count_a; i++) {
    int flag = 0;
    if (array_numbers_b[array_numbers_a[i]] != 0) {
      flag = 1;
    }
    if (flag == 0) {
      array_answer[*count_answer] = array_numbers_a[i];
      *count_answer += 1;
      array_numbers_b[array_numbers_a[i]] += 1;
    }
  }
}

void reading_numbers(int *array_numbers, int count, int *error) {
  for (int i = 0; i < count; i++) {
    if (scanf("%d", &array_numbers[i]) != 1 || array_numbers[i] > 100000 ||
        array_numbers[i] < 0) {
      *error = 1;
      break;
    }
  }
}

void reading_count(int *count, int *error) {
  if (scanf("%d", count) != 1 || *count < 1 || *count > 100000) {
    *error = 1;
  }
}

void quickSort(int *numbers, int left, int right) {
  int pivot;
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right) {
    while ((numbers[right] >= pivot) && (left < right)) right--;
    if (left != right) {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right)) left++;
    if (left != right) {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) quickSort(numbers, left, pivot - 1);
  if (right > pivot) quickSort(numbers, pivot + 1, right);
}

void print_answer(int count_answer, int *array_answer) {
  if (count_answer == 0) {
    printf("0");
  } else {
    quickSort(array_answer, 0, count_answer - 1);
    printf("%d\n", count_answer);
    for (int i = 0; i < count_answer - 1; i++) {
      printf("%d ", array_answer[i]);
    }
    printf("%d", array_answer[count_answer - 1]);
  }
}

void reading_numbers_b(int *array_numbers, int count, int *error) {
  int x;
  for (int i = 0; i < count; i++) {
    if (scanf("%d", &x) != 1 || x > 100000 || x < 0) {
      *error = 1;
      break;
    } else {
      array_numbers[x] = 1;
    }
  }
}

// изменить, сделать не через сортировку а через 3 задание
