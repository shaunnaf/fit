#include <math.h>
#include <stdio.h>

int main() {
    float a, b, res;
    scanf("%f %f", &a, &b);
    res = a / b;
    res = floorf(a / b);
    printf("%d", (int)res);
    res = ceilf(a / b);
    printf(" %d", (int)res);
    if (a / b > 0) {
        res = floorf(a / b);
    } else {
        res = ceilf(a / b);
    }
    printf(" %d", (int)res);
    int r = (int)a % (int)b;
    if (r < 0) {
        r += b;
    }
    printf(" %d", r);
    return 0;
}
