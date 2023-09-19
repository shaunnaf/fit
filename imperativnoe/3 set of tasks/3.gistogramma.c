#include <stdio.h>
#include <stdlib.h>

void reading_count(int *count, int *error);
void reading_numbers(int *error, int count, int *array_numbers, int *array_count_number);
void counting(int *array_count_number);

int main()
{
    int count, error, answer;
    error = answer = 0;
    reading_count(&count, &error);
    if (error == 0)
    {
        int *array_numbers = (int *)malloc(count * sizeof(int));
        int *array_count_number = (int *)calloc(10001, sizeof(int));
        reading_numbers(&error, count, array_numbers, array_count_number);
        if (error == 0)
        {
            counting(array_count_number);
        }
        else
        {
            printf("ERROR");
        }
        free(array_numbers);
        free(array_count_number);
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

void reading_numbers(int *error, int count, int *array_numbers, int *array_count_numbers)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &array_numbers[i]) != 1 || array_numbers[i] < 1 || array_numbers[i] > 10000)
        {
            *error = 1;
            break;
        }
        else
        {
            array_count_numbers[array_numbers[i]] += 1;
        }
    }
}

void counting(int *array_count_number)
{
    for (int i = 1; i < 10001; i++)
    {
        if (array_count_number[i] != 0)
        {
            printf("%d: %d\n", i, array_count_number[i]);
        }
    }
}