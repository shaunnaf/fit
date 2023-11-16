#include <math.h>
#include <stdio.h>

int main(void) {
  int count_numbers, number, negative, null, positive;
  negative = null = positive = 0;
  double ans;
  scanf("%d", &count_numbers);
  for (int i = 0; i < count_numbers; i++) {
    scanf("%d", &number);
    if (number > 0) {
      positive++;
    } else if (number == 0) {
      null++;
    } else {
      negative++;
    }
  }

  if (negative != 0) {
    ans = (double)negative / count_numbers;
    printf("%0.5lf ", floor(100000 * ans) / 100000);
  } else {
    printf("0 ");
  }

  if (null != 0) {
    ans = (double)null / count_numbers;
    printf("%0.5lf ", floor(100000 * ans) / 100000);
  } else {
    printf("0 ");
  }

  if (positive != 0) {
    ans = (double)positive / count_numbers;
    printf("%0.5lf", floor(100000 * ans) / 100000);
  } else {
    printf("0");
  }
  return 0;
}
