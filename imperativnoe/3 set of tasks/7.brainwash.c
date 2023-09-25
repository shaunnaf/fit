#include <stdio.h>
#include <stdlib.h>
void reading_count(int *error, int *count);
void reading_numbers(int *error, int *array, int count);
void quickSort(int *numbers, int left, int right);
void print_array(int *array, int count);

int main()
{
    int error, count;
    error = 0;
    reading_count(&error, &count);
    if (error != 1)
    {
        int *array = (int *)malloc(count * sizeof(int));
        reading_numbers(&error, array, count);
        if (error != 1)
        {
            quickSort(array, 0, count - 1);
            print_array(array, count);
        }
        free(array);
    }
    return 0;
}

void reading_count(int *error, int *count)
{
    if (scanf("%d", count) != 1 || *count < 1 || *count > 10000)
    {
        *error = 1;
    }
}

void reading_numbers(int *error, int *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &array[i]) != 1 || array[i] < -100000 || array[i] > 100000)
        {
            *error = 1;
        }
    }
}

void quickSort(int *numbers, int left, int right)
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

void print_array(int *array, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d", array[count - 1]);
}