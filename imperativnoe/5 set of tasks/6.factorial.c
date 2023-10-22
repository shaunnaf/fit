#include <stdio.h>
#include <stdlib.h>

typedef struct LongNum_s
{
    int len;       // сколько цифр в числе
    int arr[3000]; // массив десятичных цифр числа
} LongNum;

int scan_count(int *number);
void factorial(LongNum *answer, int number);
void print_answer(LongNum long_num);

int main()
{
    LongNum answer;
    answer.arr[0] = answer.len = 1;

    int number;
    if (!scan_count(&number))
    {
        if (number != 1)
        {
            factorial(&answer, number);
        }
        print_answer(answer);
    }
    else
    {
        printf("Error");
    }
    return 0;
}

void factorial(LongNum *answer, int number)
{
    for (int i = 1; i < 3000; i++)
    {
        answer->arr[i] = 0;
    }

    for (int i = 2; i < number + 1; i++)
    {
        for (int j = 0; j < answer->len; j++)
        {
            answer->arr[j] *= i;
        }
        for (int j = 0; j < answer->len; j++)
        {
            if (answer->arr[j] >= 10)
            {
                answer->arr[j + 1] += answer->arr[j] / 10;
                answer->arr[j] %= 10;
                if (answer->len < j + 2)
                {
                    answer->len = j + 2;
                }
            }
        }
    }
}

int scan_count(int *number)
{
    int error = 0;
    if (scanf("%d", number) != 1)
    {
        error = 1;
    }
    return error;
}

void print_answer(LongNum long_num)
{
    for (int i = long_num.len - 1; i >= 0; i--)
    {
        printf("%d", long_num.arr[i]);
    }
}