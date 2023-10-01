#include <stdio.h>
#include <stdlib.h>

void reading_numbers_systems(int *error, int *start_number_system, int *end_number_system);
int reading_number(int *error, int start_number_system);
void translate_to_10(char symbol, int *sum_10, int start_number_system);
void translate_to_number_system(int sum_10, int number_system);
int count_symbols(int sum_10, int numbers_system);

int main()
{
    int error, start_number_system, end_number_system, sum_10;
    error = 0;
    reading_numbers_systems(&error, &start_number_system, &end_number_system);
    if (error != 1)
    {
        sum_10 = reading_number(&error, start_number_system);
        if (error != 1)
        {
            translate_to_number_system(sum_10, end_number_system);
        }
        else
        {
            printf("ERROR");
        }
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

void reading_numbers_systems(int *error, int *start_number_system, int *end_number_system)
{
    if (scanf("%d %d ", start_number_system, end_number_system) != 2 || *start_number_system < 2 || *end_number_system < 2 || *start_number_system > 36 || *end_number_system > 36)
    {
        *error = 1;
    }
}

int reading_number(int *error, int start_number_system)
{
    int sum_10 = 0;
    char symbol;
    while (1)
    {
        if (scanf("%c", &symbol) == 1 && ((symbol >= 48 && symbol <= 57) || (symbol >= 97 && symbol <= 122)))
        {
            translate_to_10(symbol, &sum_10, start_number_system);
        }
        else
        {
            if (symbol == '\n')
            {
                break;
            }
            *error = 1;
            break;
        }
    }
    return sum_10;
}

void translate_to_10(char symbol, int *sum_10, int start_number_system)
{
    if (symbol >= 48 && symbol <= 57)
    {
        *sum_10 = *sum_10 * start_number_system + symbol - '0';
    }
    else
    {
        *sum_10 = *sum_10 * start_number_system + symbol - 87;
    }
}

void translate_to_number_system(int sum_10, int number_system)
{
    int count = count_symbols(sum_10, number_system);
    while (count != 0)
    {
        int count_2 = 0;
        int sum_10_copy = sum_10;

        while (count_2 != count - 1)
        {
            sum_10_copy /= number_system;
            count_2 += 1;
        }
        if (sum_10_copy % number_system > 9)
        {
            printf("%c", sum_10_copy % number_system + 87);
            count--;
        }
        else
        {
            printf("%d", sum_10_copy % number_system);
            count--;
        }
    }
}

int count_symbols(int sum_10, int numbers_system)
{
    int count = 0;
    while (sum_10 != 0)
    {
        sum_10 /= numbers_system;
        count += 1;
    }
    return count;
}
