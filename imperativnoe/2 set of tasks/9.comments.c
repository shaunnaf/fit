#include <stdio.h>

int main()
{
    char curr;
    int flag, flag2, comment_off;
    flag = flag2 = comment_off = 0;
    if (scanf("%c", &curr) != 1)
    {
        flag2 = 1;
    }
    while (flag2 != 1)
    {
        if (curr == '\n')
        {
            printf("\n");
        }
        else if (curr == '/')
        {
            if (scanf("%c", &curr) != 1)
            {
                printf("/");
                break;
            }
            if (curr == '\n')
            {
                printf("\n");
            }
            else if (curr == '*')
            {
                comment_off = 0;
                while (curr != '/')
                {
                    if (curr == '\n')
                    {
                        printf("\n");
                    }
                    else if (curr == '*')
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                    }
                    if (scanf("%c", &curr) != 1)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 1)
                {
                    break;
                }
                else if (flag == 1)
                {
                    comment_off = 1;
                }
            }
            else if (curr == '/')
            {
                comment_off = 0;
                if (scanf("%c", &curr) != 1)
                {
                    flag2 = 1;
                    break;
                }
                while (curr != '\n')
                {
                    if (scanf("%c", &curr) != 1)
                    {
                        flag2 = 1;
                        break;
                    }
                    if (curr == '\n')
                    {
                        printf("\n");
                        comment_off = 1;
                    }
                }
            }
        }
        else
        {
            if (comment_off == 1)
            {
                printf("%c", curr);
            }
        }
        if (scanf("%c", &curr) != 1)
        {
            break;
        }
    }
    return 0;
}
