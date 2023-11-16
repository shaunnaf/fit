#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime_s {
  int year, month, day;
  int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime *arr, int cnt);
int scan_count(int *count);
int scan_struct(int count, DateTime *DateTimes);

int main(void) {
  DateTime DateTimes[50000];
  DateTime answer;
  int count;
  if (!scan_count(&count)) {
    if (!scan_struct(count, DateTimes)) {
      answer = min(DateTimes, count);
      printf("%d %d %d %d %d %d", answer.year, answer.month, answer.day,
             answer.hours, answer.minutes, answer.seconds);
    } else {
      printf("ERROR");
    }
  } else {
    printf("ERROR");
  }
  return 0;
}

DateTime min(const DateTime *arr, int cnt) {
  int min = 0;
  for (int i = 1; i < cnt; i++) {
    if (arr[min].year > arr[i].year) {
      min = i;
    } else if (arr[min].year == arr[i].year) {
      if (arr[min].month > arr[i].month) {
        min = i;
      } else if (arr[min].month == arr[i].month) {
        if (arr[min].day > arr[i].day) {
          min = i;
        } else if (arr[min].day == arr[i].day) {
          if (arr[min].hours > arr[i].hours) {
            min = i;
          } else if (arr[min].hours == arr[i].hours) {
            if (arr[min].minutes > arr[i].minutes) {
              min = i;
            } else if (arr[min].minutes == arr[i].minutes) {
              if (arr[min].seconds > arr[i].seconds) {
                min = i;
              }
            }
          }
        }
      }
    }
  }
  return arr[min];
}

int scan_count(int *count) {
  int error = 0;
  if (scanf("%d", count) != 1) {
    error = 1;
  }
  return error;
}

int scan_struct(int count, DateTime *DateTimes) {
  int error = 0;
  for (int i = 0; i < count; i++) {
    if (scanf("%d %d %d %d %d %d", &DateTimes[i].year, &DateTimes[i].month,
              &DateTimes[i].day, &DateTimes[i].hours, &DateTimes[i].minutes,
              &DateTimes[i].seconds) != 6) {
      error = 1;
    }
  }
  return error;
}
