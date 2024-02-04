#include <stdio.h>
#include <string.h>

int main(void) {
  char day[3];
  scanf("%s", day);
  if (!strcmp(day, "Mon")) {
    printf("1");
  } else if (!strcmp(day, "Tue")) {
    printf("2");
  } else if (!strcmp(day, "Wed")) {
    printf("3");
  } else if (!strcmp(day, "Thu")) {
    printf("4");
  } else if (!strcmp(day, "Fri")) {
    printf("5");
  } else if (!strcmp(day, "Sat")) {
    printf("6");
  } else if (!strcmp(day, "Sun")) {
    printf("7");
  }
  return 0;
}
