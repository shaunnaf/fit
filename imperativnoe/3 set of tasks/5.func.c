#include <stdio.h>
#include <stdlib.h>

int reading_count(int *size_R, int *count_pair);
int reading_pair(int count_pair, int *array_x, int *array_y);
void answer(int *array_x, int *array_y, int count_pair, int *array_value_x, int *array_value_y, int *array_answer, int size_R);

int main()
{
    int size_R, count_pair;
    if (!reading_count(&size_R, &count_pair))
    {
        int *array_x = (int *)malloc(count_pair * sizeof(int));
        int *array_y = (int *)malloc(count_pair * sizeof(int));
        if (!reading_pair(count_pair, array_x, array_y))
        {
            int *array_value_x = (int *)calloc(size_R + 1, sizeof(int));
            int *array_value_y = (int *)calloc(size_R + 1, sizeof(int));
            int *array_answer = (int *)calloc(5, sizeof(int));
            answer(array_x, array_y, count_pair, array_value_x, array_value_y, array_answer, size_R);
            free(array_value_x);
            free(array_value_y);
            free(array_answer);
        }
        else
        {
            printf("ERROR");
        }
        free(array_x);
        free(array_y);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

int reading_count(int *size_R, int *count_pair)
{
    int error = 0;
    if (scanf("%d %d", size_R, count_pair) != 2)
    {
        error = 1;
    }
    return error;
}

int reading_pair(int count_pair, int *array_x, int *array_y)
{
    int error = 0;
    for (int i = 0; i < count_pair; i++)
    {
        if (scanf("%d %d", &array_x[i], &array_y[i]) != 2)
        {
            error = 1;
            break;
        }
    }
    return error;
}

void answer(int *array_x, int *array_y, int count_pair, int *array_value_x, int *array_value_y, int *array_answer, int size_R)
{
    for (int i = 0; i < count_pair; i++)
    {
        if (array_value_x[array_x[i]] != 0)
        {
            array_answer[0] = 1;
        }
        if (array_value_y[array_y[i]] != 0)
        {
            array_answer[2] = 1;
        }
        array_value_x[array_x[i]] = array_y[i];
        array_value_y[array_y[i]] = array_x[i];
    }
    for (int i = 1; i <= size_R; i++)
    {
        if (array_value_x[i] == 0)
        {
            array_answer[1] = 1;
        }
        if (array_value_y[i] == 0)
        {
            array_answer[3] = 1;
        }
    }
    if (array_answer[0] == 1)
    {
        array_answer[1] = 1;
        array_answer[2] = 1;
        array_answer[3] = 1;
    }
    if (array_answer[2] == 1 && array_answer[3] == 1)
    {
        array_answer[4] = 1;
    }
    if (array_answer[0] == 1 && array_answer[1] == 1 && array_answer[2] == 1 && array_answer[3] == 1 && array_answer[4] == 1)
    {
        printf("0");
    }
    else
    {
        int mark = 0;
        for (int i = 0; i < 5; i++)
        {
            if (array_answer[i] == 0)
            {
                if (mark == 1)
                {
                    printf(" %d", i + 1);
                }
                else
                {
                    printf("%d", i + 1);
                    mark = 1;
                }
            }
        }
    }
}
