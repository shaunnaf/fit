#include <stdio.h>

int max(int a, int b);

int main()
{
    int a1, a2, b1, b2, c1, c2;
    int flag = 0;
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
    if (a1 * a2 >= b1 * b2 + c1 * c2)
    {
        if ((a1 >= b1 + c1 && a2 >= max(b2, c2)) || (a1 >= b2 + c2 && a2 >= max(b1, c1)) || (a1 >= b1 + c2 && a2 >= max(b2, c1)) || (a1 >= b2 + c1 && a2 >= max(b1, c2)))
        {
            flag = 1;
        }
        else if ((a2 >= b1 + c1 && a1 >= max(b2, c2)) || (a2 >= b2 + c2 && a1 >= max(b1, c1)) || (a2 >= b1 + c2 && a1 >= max(b2, c1)) || (a2 >= b2 + c1 && a1 >= max(b1, c2)))
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}