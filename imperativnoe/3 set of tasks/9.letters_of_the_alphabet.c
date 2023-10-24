#include <stdio.h>
#include <stdlib.h>

int reading_count(int *count);
int reading_symbols(int count, char *array_symbols);
void decision(char *array_symbols, int count);
void print_answer(char *array_symbols, int count);
void quickSort(char *numbers, int left, int right);

int main()
{
    int count;
    if (!reading_count(&count))
    {
        char *array_symbols = (char *)malloc(count * sizeof(char));
        if (!reading_symbols(count, array_symbols))
        {
            decision(array_symbols, count);
            print_answer(array_symbols, count);
        }
        else
        {
            printf("ERROR");
        }
        free(array_symbols);
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}

int reading_count(int *count)
{
    int error = 0;
    if (scanf("%d", count) != 1)
    {
        error = 1;
    }
    return error;
}

int reading_symbols(int count, char *array_symbols)
{
    int error = 0;
    getchar();
    for (int i = 0; i < count; i++)
    {
        array_symbols[i] = getchar();
        getchar();
    }
    return error;
}

void decision(char *array_symbols, int count)
{
    int mark = 0;
    for (int i = count - 2; i > 0; i--)
    {
        if (array_symbols[count - 1] > array_symbols[i])
        {
            int temp = array_symbols[i];
            array_symbols[i] = array_symbols[count - 1];
            array_symbols[count - 1] = temp;
            mark = 1;
            break;
        }
    }
    if (mark == 0)
    {
        int min = 9999;
        int index = 0;
        for (int i = 1; i < count; i++)
        {
            if (array_symbols[i] > array_symbols[0] && array_symbols[i] < min)
            {
                min = array_symbols[i];
                index = i;
            }
        }
        int temp = array_symbols[0];
        array_symbols[0] = array_symbols[index];
        array_symbols[index] = temp;
        quickSort(array_symbols, 1, count - 1);
    }
}

void print_answer(char *array_symbols, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        printf("%c ", array_symbols[i]);
    }
    printf("%c", array_symbols[count - 1]);
}

void quickSort(char *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}
