#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int N;
char maze[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

void dfs(int x, int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_valid(nx, ny) && maze[nx][ny] == '*' && !visited[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  fscanf(input, "%d", &N);

  for (int i = 0; i < N; i++) {
    fscanf(input, "%s", maze[i]);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = false;
    }
  }

  int count = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maze[i][j] == '*' && !visited[i][j]) {
        dfs(i, j);
        count++;
      }
    }
  }

  fprintf(output, "%d\n", count);

  fclose(input);
  fclose(output);

  return 0;
}
