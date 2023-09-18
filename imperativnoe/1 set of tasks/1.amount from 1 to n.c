#include <stdio.h>

int main(void)
{
    float n;
    int s;
    s = 0;
    scanf("%f", &n);
    s = (1 + n) / 2 * n;
    printf("%d", s);
    return 0;
}
