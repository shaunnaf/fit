#include <stdio.h>

int main(void) {
    int a, b, c, sum;
    scanf("%d %d %d", &a, &b, &c);
    if (a <= 0) {
        printf("-1");
    } else if (b <= 0) {
        printf("-2");
    } else if (c <= 0) {
        printf("-3");
    } else {
        sum = (a * b + b * c + c * a) * 2;
        printf("%d", sum);
    }
    return 0;
}
