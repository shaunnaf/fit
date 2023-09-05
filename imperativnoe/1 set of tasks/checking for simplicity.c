#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool prime(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    if (prime(n) == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

bool prime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
