#include <stdio.h>

int read_count(int *count_time);
int read_time(int count_time);
void printTime(int hours, int minutes, int seconds);

int main(void) {
  int count_time;
  if (!read_count(&count_time)) {
    if (read_time(count_time)) {
      printf("ERROR");
    }
  } else {
    printf("ERROR");
  }
  return 0;
}

int read_count(int *count_time) {
  int error = 0;
  if (scanf("%d", count_time) != 1) {
    error = 1;
  }
  return error;
}

int read_time(int count_time) {
  int error = 0;
  int hours, minutes, seconds;
  for (int i = 0; i < count_time; i++) {
    if (scanf("%d %d %d", &hours, &minutes, &seconds) != 3) {
      error = 1;
      break;
    }
    printTime(hours, minutes, seconds);
  }
  return error;
}

void printTime(int hours, int minutes, int seconds) {
  printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}
//
