#include <stdio.h>
#include <stdlib.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt);
void calculate_answer(char *array);
void print_answer(int count_line, int count_char, int len, int oLowerCnt, int oUpperCnt, int oDigitsCnt);

int main()
{
    char *array = (char *)malloc(1000 * sizeof(char));
    calculate_answer(array);
    free(array);
    return 0;
}

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    int count = 0;
    while (iStr[count] != '\0' && iStr[count] != '\n')
    {
        if (iStr[count] >= 65 && iStr[count] <= 90)
        {
            *oUpperCnt += 1;
        }
        else if (iStr[count] >= 97 && iStr[count] <= 122)
        {
            *oLowerCnt += 1;
        }
        else if (iStr[count] - '0' >= 0 && iStr[count] - '0' <= 9)
        {
            *oDigitsCnt += 1;
        }
        count += 1;
    }
    return count;
}

void calculate_answer(char *array)
{
    int count_line = 1;
    while (1)
    {
        if (fgets(array, 1000, stdin) != NULL)
        {
            int oLowerCnt, oUpperCnt, oDigitsCnt, count;
            oLowerCnt = oUpperCnt = oDigitsCnt = count = 0;
            count = calcLetters(array, &oLowerCnt, &oUpperCnt, &oDigitsCnt);
            print_answer(count_line, count, oLowerCnt + oUpperCnt, oLowerCnt, oUpperCnt, oDigitsCnt);
            count_line += 1;
        }
        else
        {
            break;
        }
    }
}

void print_answer(int count_line, int count_char, int len, int oLowerCnt, int oUpperCnt, int oDigitsCnt)
{
    printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", count_line, count_char, len, oLowerCnt, oUpperCnt, oDigitsCnt);
}