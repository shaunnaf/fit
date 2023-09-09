#include <stdio.h>

int main()
{
    int a1, a2, b1, b2, c1, c2, max_a, min_a, max_b, min_b, max_c, min_c;
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
    if (a1 * a2 < b1 * b2 + c1 * c2)
    {
        if (a1 > a2)
        {
            max_a = a1;
            min_a = a2;
        }
        else
        {
            max_a = a2;
            min_a = a1;
        }
        if (b1 > b2)
        {
            max_b = b1;
            min_b = b2;
        }
        else
        {
            max_b = b2;
            min_b = b1;
        }
        if (c1 > c2)
        {
            max_c = c1;
            min_c = c2;
        }
        else
        {
            max_c = c2;
            min_c = c1;
        }
        if (max_a >= max_b && max_a >= max_c && min_a >= min_b && min_a >= min_c)
        {
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}