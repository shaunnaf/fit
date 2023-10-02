#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_count(int *count_strings);
int read_string(int count_string, char *string1, char *string2);
char *concat(char *pref, char *suff);
void print_string(char *string_array, int len);

int main()
{
    int count_string;
    if (!read_count(&count_string))
    {
        char *string1 = (char *)malloc(101 * sizeof(char));
        char *string2 = (char *)malloc(101 * sizeof(char));
        if (read_string(count_string, string1, string2))
        {
            printf("ERROR");
        }
        free(string1);
        free(string2);
    }
    return 0;
}

int read_count(int *count_strings)
{
    int error = 0;
    if (scanf("%d", count_strings) != 1)
    {
        error = 1;
    }
    return error;
}

int read_string(int count_string, char *string1, char *string2)
{
    int error, mark, len2, len;
    error = mark = 0;
    char symbol;
    scanf("%c", &symbol);
    if (symbol != '\n')
    {
        error = 1;
        goto ret;
    }
    for (int i = 0; i < count_string; i++)
    {
        len = 0;
        if (scanf("%c", &symbol) != 1)
        {
            error = 1;
            goto ret;
        }
        while (symbol != '\n')
        {
            if (i == 0)
            {
                string1[len] = symbol;
                len++;
                if (scanf("%c", &symbol) != 1)
                {
                    error = 1;
                    goto ret;
                }
            }
            else
            {
                string2[len] = symbol;
                len++;
                if (scanf("%c", &symbol) != 1)
                {
                    error = 1;
                    goto ret;
                }
            }
        }
        if (i > 1)
        {
            len2 = strlen(string1);
            string1 = string1 - len2;
        }
        string1 = concat(string1, string2);
    }
    print_string(string1, len + len2);
ret:
    return error;
}

char *concat(char *pref, char *suff)
{
    int len1 = strlen(pref);
    int len2 = strlen(suff);
    char *result = (char *)malloc(len1 + len2 + 1);
    memcpy(result, pref, len1);
    memcpy(result, suff, len2 + 1);
    return result + len1 + len2;
}

void print_string(char *string_array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", string_array[i]);
    }
    printf("\n");
}