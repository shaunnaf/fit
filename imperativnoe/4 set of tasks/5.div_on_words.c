#include <stdio.h>
#include <stdlib.h>

void calcLetters(char *iStr);
void calculated(char *array);

int main()
{
    char *array = (char *)malloc(10000000 * sizeof(char));
    calculated(array);
    free(array);
    return 0;
}

void calcLetters(char *iStr)
{
    int UpperCnt, DigitsCnt, mark, count, temp_count;
    char *temp_array = (char *)malloc(10000000 * sizeof(char));
    UpperCnt = mark = count = temp_count = 0;
    while (iStr[count] != '\0')
    {
        if (iStr[count] >= 65 && iStr[count] <= 90)
        {
            temp_array[temp_count] = iStr[count];
            UpperCnt += 1;
            mark = 1;
            temp_count += 1;
        }
        else if (iStr[count] >= 97 && iStr[count] <= 122)
        {
            temp_array[temp_count] = iStr[count];
            temp_count += 1;
            mark = 1;
        }
        else if (mark == 1)
        {
            printf("%d/%d ", UpperCnt, temp_count);
            for (int i = 0; i < temp_count; i++)
            {
                printf("%c", temp_array[i]);
            }
            printf("\n");
            UpperCnt = mark = temp_count = 0;
        }
        count += 1;
    }
    free(temp_array);
}

void calculated(char *array)
{
    if (fgets(array, 10000000, stdin) != NULL)
    {
        calcLetters(array);
    }
    else
    {
        printf("ERROR");
    }
}