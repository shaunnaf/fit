#include <stdio.h>
#include <stdlib.h>

void reading_count(int *count, int *error);
void reading_numbers(int *error, int count, int *array_numbers);
void counting(int *array_numbers, int count);

int main()
{
    int count, error;
    error = 0;
    reading_count(&count, &error);
    if (error == 0)
    {
        int *array_numbers = (int *)malloc(count * sizeof(int));
        reading_numbers(&error, count, array_numbers);
        if (error == 0)
        {
            counting(array_numbers, count);
        }
        else
        {
            printf("ERROR");
        }
        free(array_numbers);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

void reading_count(int *count, int *error)
{
    if (scanf("%d", count) != 1 || *count < 1 || *count > 5000)
    {
        *error = 1;
    }
}

void reading_numbers(int *error, int count, int *array_numbers)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &array_numbers[i]) != 1 || array_numbers[i] < -10000 || array_numbers[i] > 10000)
        {
            *error = 1;
            break;
        }
    }
}

void counting(int *array_numbers, int count)
{
    int curr_sum, max_sum, answer_left, answer_right, curr_left;
    curr_sum = curr_left = answer_left = answer_right = 0;
    max_sum = array_numbers[0];

    for (int right = 0; right < count; right++)
    {
        curr_sum += array_numbers[right];

        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
            answer_right = right;
            answer_left = curr_left;
        }
        if (curr_sum < 0)
        {
            curr_left = right + 1;
            curr_sum = 0;
        }
    }
    printf("%d %d %d", answer_left, answer_right, max_sum);
}