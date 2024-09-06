#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12

int string, column;
char board[MAX][MAX];
char result[MAX][MAX];
bool cols[MAX], diag1[MAX * 2 - 1], diag2[MAX * 2 - 1];

bool safe(int curr_string, int curr_column);
bool decision(int curr_string);

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  fscanf(input, "%d %d", &string, &column);

  for (int i = 0; i < string; ++i) {
    fscanf(input, "%s", board[i]);
  }

  memset(cols, 0, sizeof(cols));
  memset(diag1, 0, sizeof(diag1));
  memset(diag2, 0, sizeof(diag2));

  for (int i = 0; i < string; i++) {
    for (int j = 0; j < column; j++) {
      result[i][j] = '.';
    }
  }

  if (decision(0)) {
    fprintf(output, "YES\n");
    for (int i = 0; i < string; ++i) {
      for (int j = 0; j < column; ++j) {
        fprintf(output, "%c", result[i][j]);
      }
      fprintf(output, "\n");
    }
  } else {
    fprintf(output, "NO\n");
  }

  fclose(input);
  fclose(output);

  return 0;
}

bool decision(int curr_string) {
  if (curr_string == string) {
    return true;
  }

  for (int curr_column = 0; curr_column < column; curr_column++) {
    if (safe(curr_string, curr_column)) {
      result[curr_string][curr_column] = 'X';
      cols[curr_column] = diag1[curr_string + curr_column] =
          diag2[curr_string - curr_column + column - 1] = true;

      if (decision(curr_string + 1)) return true;

      result[curr_string][curr_column] = '.';
      cols[curr_column] = diag1[curr_string + curr_column] =
          diag2[curr_string - curr_column + column - 1] = false;
    }
  }
  return false;
}

bool safe(int curr_string, int curr_column) {
  return !cols[curr_column] && !diag1[curr_string + curr_column] &&
         !diag2[curr_string - curr_column + column - 1] &&
         board[curr_string][curr_column] != '.';
}
