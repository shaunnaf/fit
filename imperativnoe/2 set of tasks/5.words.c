#include <stdio.h>

int main()
{
    char c;
    int answer, flag;
    answer = flag = 0;
    scanf("%c", &c);
    while (c != '\n')
    {
        if (c != '.')
        {
            if (flag == 0)
            {
                answer += 1;
            }
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        scanf("%c", &c);
    }
    printf("%d", answer);
    return 0;
}