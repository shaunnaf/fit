#include <stdio.h>
#include <stdlib.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds);
void printTime(int hours, int minutes, int seconds, int error);

int main()
{
    char *array = (char *)malloc(20 * sizeof(char));
    int hours, minutes, seconds, error;
    error = readTime(array, &hours, &minutes, &seconds);
    printTime(hours, minutes, seconds, error);
    free(array);
    return 0;
}

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds)
{
    int error;
    if (fgets(iStr, 20, stdin) != NULL)
    {
        error = 1;
        int check_scan = sscanf(iStr, "%02d:%02d:%02d", oHours, oMinutes, oSeconds);
        if (check_scan == 2 || check_scan == 3)
        {
            if (check_scan == 2)
            {
                *oSeconds = 0;
            }
            if (*oHours >= 24 || *oHours < 0 || *oMinutes < 0 || *oMinutes >= 60 || *oSeconds < 0 || *oSeconds >= 60)
            {
                error = 0;
            }
        }
        else
        {
            error = 0;
        }
    }
    else
    {
        error = 0;
    }
    return error;
}

void printTime(int hours, int minutes, int seconds, int error)
{
    if (error == 1)
    {
        printf("1 %d %d %d\n", hours, minutes, seconds);
        printf("1 %d %d\n", hours, minutes);
        printf("1 %d\n", hours);
    }
    else
    {
        printf("0 -1 -1 -1\n0 -1 -1\n0 -1");
    }
}
