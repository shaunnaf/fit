#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d %d\n", a * b, a % b, b % a);
    return 0;
}
