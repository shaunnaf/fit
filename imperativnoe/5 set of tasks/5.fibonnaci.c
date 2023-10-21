#include <stdio.h>
#include <stdlib.h>

typedef struct LongNum_s
{
    int len;      // сколько цифр в числе
    int arr[500]; // массив десятичных цифр числа
} LongNum;

int scan_count(int *number);
void fibonnaci(int number, LongNum *long_num);
void print_answer(LongNum *long_num);

int main()
{
    LongNum long_num[2];
    long_num[0].arr[0] = 1;
    long_num[1].arr[0] = 1;
    long_num[0].len = 1;
    long_num[1].len = 1;
    int number;
    if (!scan_count(&number))
    {
        if (number != 1 && number != 2)
        {
            fibonnaci(number, long_num);
        }
        print_answer(long_num);
    }
    return 0;
}

void fibonnaci(int number, LongNum *long_num)
{
    int curr_number = 2;
    for (int i = 1; i < 500; i++)
    {
        long_num[1].arr[i] = 0;
        long_num[0].arr[i] = 0;
    }
    while (curr_number != number)
    {
        int mark = 0;
        for (int i = 0; i < long_num[1].len; i++)
        {
            int temp;
            if (mark == 1)
            {
                temp = long_num[1].arr[i] - 1;
            }
            else
            {
                temp = long_num[1].arr[i];
            }
            mark = 0;
            if (long_num[0].len == long_num[1].len || i < long_num[0].len)
            {
                long_num[1].arr[i] += long_num[0].arr[i];
            }
            else
            {
                long_num[0].len++;
            }
            long_num[0].arr[i] = temp;
            if (long_num[1].arr[i] >= 10)
            {
                long_num[1].arr[i + 1]++;
                long_num[1].arr[i] %= 10;
                mark = 1;
                if (long_num[1].len < i + 2)
                {
                    long_num[1].len = i + 2;
                    break;
                }
            }
        }
        curr_number++;
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

void print_answer(LongNum *long_num)
{
    for (int i = long_num[1].len - 1; i >= 0; i--)
    {
        printf("%d", long_num[1].arr[i]);
    }
}
