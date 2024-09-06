#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int height, width;
char maze[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

typedef struct {
  int x, y;
} Point;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y);

int bfs(Point start, Point end);

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  fscanf(input, "%d %d", &height, &width);

  Point start, end;

  for (int i = 0; i < height; i++) {
    fscanf(input, "%s", maze[i]);
    for (int j = 0; j < width; j++) {
      if (maze[i][j] == 'S') {
        start = (Point){i, j};
      } else if (maze[i][j] == 'F') {
        end = (Point){i, j};
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      visited[i][j] = false;
      dist[i][j] = -1;
    }
  }

  int result = bfs(start, end);

  fprintf(output, "%d\n", result);

  fclose(input);
  fclose(output);

  return 0;
}

bool is_valid(int x, int y) {
  return x >= 0 && x < height && y >= 0 && y < width;
}

int bfs(Point start, Point end) {
  Point queue[MAX * MAX];
  int front = 0, rear = 0;

  queue[rear++] = start;
  visited[start.x][start.y] = true;
  dist[start.x][start.y] = 0;

  while (front < rear) {
    Point curr = queue[front++];
    if (curr.x == end.x && curr.y == end.y) {
      return dist[curr.x][curr.y];
    }

    for (int i = 0; i < 4; i++) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];

      if (is_valid(nx, ny) && maze[nx][ny] != 'X' && !visited[nx][ny]) {
        queue[rear++] = (Point){nx, ny};
        visited[nx][ny] = true;
        dist[nx][ny] = dist[curr.x][curr.y] + 1;
      }
    }
  }

  return -1;
}