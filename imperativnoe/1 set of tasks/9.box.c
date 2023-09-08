#include <math.h>
#include <stdio.h>

int main() {
    double a, b, c;
    long long n;
    scanf("%lld", &n);
    a = b = c = 1;
    long long answer = 0;
    while (1) {
        while (a * b * c <= n) {
            answer += floor(n / a / b) - (c - 1);
            b += 1;
            c = b;
        }
        a += 1;
        b = a;
        c = a;
        if (a * b * c > n) {
            break;
        }
    }
    printf("%lld", answer);
    return 0;
}
