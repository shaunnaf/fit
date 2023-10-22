#include <stdio.h>
#include <stdlib.h>

typedef struct LongNum_s
{
    int len;       // сколько цифр в числе
    int arr[3000]; // массив десятичных цифр числа
} LongNum;

int scan_count(LongNum *answer, LongNum *number1, LongNum *number2);
void print_answer(LongNum long_num);
void long_multiply(LongNum *answer, LongNum *number1, LongNum *number2);

int main()
{
    LongNum answer, number1, number2;
    answer.len = 1;
    number1.len = number2.len = 0;

    if (!scan_count(&answer, &number1, &number2))
    {
        long_multiply(&answer, &number1, &number2);
        print_answer(answer);
    }
    else
    {
        printf("Error");
    }
    return 0;
}

void long_multiply(LongNum *answer, LongNum *number1, LongNum *number2)
{
    answer->len = number1->len + number2->len;
    for (int i = number2->len - 1; i >= 0; i--)
    {
        for (int j = number1->len - 1; j >= 0; j--)
        {
            answer->arr[number1->len + number2->len - i - j - 2] += number1->arr[j] * number2->arr[i];
        }
        int counter = 0;
        while (answer->arr[counter] != 0 || counter < answer->len)
        {
            if (answer->arr[counter] >= 10)
            {
                answer->arr[counter + 1] += answer->arr[counter] / 10;
                answer->arr[counter] %= 10;
            }
            counter++;
        }
        if (counter > answer->len)
        {
            answer->len = counter;
        }
    }
}

int scan_count(LongNum *answer, LongNum *number1, LongNum *number2)
{
    for (int i = 0; i < 3000; i++)
    {
        answer->arr[i] = number2->arr[i] = number1->arr[i] = 0;
    }
    int error = 0;
    char symbol;
    symbol = getchar();
    while (symbol != '\n')
    {
        if (symbol - '0' >= 0 && symbol - '0' <= 9)
        {
            number1->arr[number1->len] = symbol - '0';
            number1->len++;
            symbol = getchar();
        }
        else
        {
            error = 1;
            break;
        }
    }
    if (error == 0)
    {
        symbol = getchar();
        while (symbol != '\n')
        {
            if (symbol - '0' >= 0 && symbol - '0' <= 9)
            {
                number2->arr[number2->len] = symbol - '0';
                number2->len++;
                symbol = getchar();
            }
            else
            {
                error = 1;
                break;
            }
        }
    }
    return error;
}

void print_answer(LongNum long_num)
{
    if (long_num.arr[long_num.len - 1] != 0)
    {
        printf("%d", long_num.arr[long_num.len - 1]);
    }
    for (int i = long_num.len - 2; i >= 0; i--)
    {
        printf("%d", long_num.arr[i]);
    }
}
