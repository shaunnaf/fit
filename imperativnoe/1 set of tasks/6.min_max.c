#include <stdio.h>

int main()
{
    int min, max, min_index, max_index, amount_numbers, x;
    scanf("%d", &amount_numbers);
    scanf("%d", &x);
    min = max = x;
    min_index = max_index = 1;
    for (int i = 1; i < amount_numbers; i++)
    {
        scanf("%d", &x);
        if (x > max)
        {
            max = x;
            max_index = i + 1;
        }
        if (x < min)
        {
            min = x;
            min_index = i + 1;
        }
    }
    printf("%d %d %d %d", min, min_index, max, max_index);
    return 0;
}
