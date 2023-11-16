#include <math.h>
#include <stdio.h>

int main(void) {
  int n, count, flag, answer;
  char input;
  scanf("%d", &n);
  count = flag = answer = 0;
  scanf("%c", &input);
  for (int i = 0; i < n; i++) {
    if (count == 8) {
      count = 0;
      if (flag != 0) {
        printf(" ");
      }
      printf("%d", answer);
      flag = 1;
      answer = 0;
    }
    scanf("%c", &input);
    if (input == '1') {
      answer += pow(2, count);
    }
    count++;
  }
  if (flag == 0) {
    printf("%d", answer);
  } else {
    printf(" %d", answer);
  }
  return 0;
}
