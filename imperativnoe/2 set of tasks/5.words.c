#include <stdio.h>

int main()
{
    char c;
    int answer = 0;
    scanf("%c", &c);
    int flag = 0;
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