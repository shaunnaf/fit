#include <stdio.h>
#include <stdlib.h>

void calculated_count_symbols(int *array_count_symbols);
void print_answer(int *array_count_symbols);

int main(void) {
  int *array_count_symbols = calloc(150, sizeof(int));
  calculated_count_symbols(array_count_symbols);
  print_answer(array_count_symbols);
  free(array_count_symbols);
  return 0;
}

void calculated_count_symbols(int *array_count_symbols) {
  char c = getchar();
  while (c != EOF) {
    if (c != '\n') {
      int number = c;
      array_count_symbols[number] += 1;
    }
    c = getchar();
  }
}

void print_answer(int *array_count_symbols) {
  for (int i = 32; i < 127; i++) {
    if (array_count_symbols[i] != 0) {
      printf("%c ", i);
      while (array_count_symbols[i] != 0) {
        printf("#");
        array_count_symbols[i] -= 1;
      }
      printf("\n");
    }
  }
}
//
