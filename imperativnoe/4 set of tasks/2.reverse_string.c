#include <stdio.h>
#include <stdlib.h>

int read_count(int *count_strings);
int read_string(int count_strings, char *string_array);
void reverse(char *start, int len);
void print_string(char *string_array, int len);

int main(void) {
  int count_strings;
  if (!read_count(&count_strings)) {
    char *string_array = (char *)malloc(101 * sizeof(char));
    if (read_string(count_strings, string_array)) {
      printf("ERROR");
    }
    free(string_array);
  } else {
    printf("ERROR");
  }
  return 0;
}

int read_count(int *count_strings) {
  int error = 0;
  if (scanf("%d", count_strings) != 1) {
    error = 1;
  }
  return error;
}

int read_string(int count_strings, char *string_array) {
  int error = 0;
  char symbol;
  scanf("%c", &symbol);
  if (symbol != '\n') {
    error = 1;
    goto ret;
  }
  for (int i = 0; i < count_strings; i++) {
    int len = 0;
    if (scanf("%c", &symbol) != 1) {
      error = 1;
      goto ret;
    }
    while (symbol != '\n') {
      string_array[len] = symbol;
      len++;
      if (scanf("%c", &symbol) != 1) {
        error = 1;
        goto ret;
      }
    }
    reverse(string_array, len);
    print_string(string_array, len);
  }
ret:
  return error;
}

void reverse(char *start, int len) {
  char temp;
  for (int i = 0; i < len / 2; i++) {
    temp = start[i];
    start[i] = start[len - i - 1];
    start[len - i - 1] = temp;
  }
}

void print_string(char *string_array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%c", string_array[i]);
  }
  printf("\n");
}
//
