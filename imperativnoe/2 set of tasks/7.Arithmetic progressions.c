#include <stdio.h>

int main()
{
    int left, right, count, curr_count, step, curr_number, answer;
    answer = 0;
    step = curr_count = 1;
    scanf("%d %d %d", &left, &right, &count);
    for (int i = left; i <= right; i++)
    {
        curr_number = i;
        while (step * (count - 1) <= right - left)
        {
            if (curr_count == count)
            {
                if (curr_number <= right && (curr_number + step > right))
                {
                    answer += 1;
                    curr_number = i;
                    curr_count = 1;
                    step += 1;
                }
                else if (curr_number + step <= right)
                {
                    step += 1;
                    curr_count = 1;
                    curr_number = i;
                }
                else
                {
                    break;
                }
            }
            else if (curr_number > right)
            {
                break;
            }
            else
            {
                curr_number += step;
                curr_count++;
            }
        }
        curr_count = 1;
        step = 1;
    }
    printf("%d", answer);
    return 0;
}
