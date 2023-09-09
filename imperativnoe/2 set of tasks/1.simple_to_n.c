#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool prime(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (prime(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

bool prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
