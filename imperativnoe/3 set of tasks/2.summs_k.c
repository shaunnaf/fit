#include <stdio.h>
#include <stdlib.h>

void reading_count(int *count, int *error);
void reading_numbers(int *error, int count, int *array);
void counting(int count, int *array);

int main()
{
    int count, error, answer;
    error = answer = 0;
    reading_count(&count, &error);
    if (error == 0)
    {
        int *array = (int *)malloc(count * sizeof(int));
        reading_numbers(&error, count, array);
        if (error == 0)
        {
            counting(count, array);
        }
        else
        {
            printf("ERROR");
        }
        free(array);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

void reading_count(int *count, int *error)
{
    if (scanf("%d", count) != 1 || *count < 1 || *count > 100000)
    {
        *error = 1;
    }
}

void reading_numbers(int *error, int count, int *array)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &array[i]) != 1 || array[i] < 1 || array[i] > 10000)
        {
            *error = 1;
            break;
        }
    }
}

void counting(int count, int *array)
{
    int answer;
    for (int i = 0; i < count; i++)
    {
        answer = 0;
        for (int j = i; j < count; j += i + 1)
        {
            answer += array[j];
        }
        printf("%d\n", answer);
    }
}