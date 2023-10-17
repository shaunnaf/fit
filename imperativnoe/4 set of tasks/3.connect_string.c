#include <stdio.h>
#include <stdlib.h>

int read_count(int *count_strings);
int read_string(int count_string, char *string1, char *string2);
char *concat(char *pref, char *suff);
void print_string(char *string_array, char *temp_string);

int main()
{
    int count_string;
    if (!read_count(&count_string))
    {
        char *string1 = (char *)malloc(10000000 * sizeof(char));
        char *string2 = (char *)malloc(1000 * sizeof(char));
        if (read_string(count_string, string1, string2))
        {
            printf("ERROR");
        }
        free(string1);
        free(string2);
    }
    else
    {
        printf("Error");
    }
    return 0;
}

int read_count(int *count_strings)
{
    int error = 0;
    if (scanf("%d\n", count_strings) != 1)
    {
        error = 1;
    }
    return error;
}

int read_string(int count_string, char *string1, char *string2)
{
    int error, mark;
    char *temp_string;
    error = mark = 0;
    for (int i = 0; i < count_string; i++)
    {
        if (fgets(string2, 1000, stdin) != NULL)
        {
            temp_string = concat(string1, string2);
            print_string(string1, temp_string);
            string1 = temp_string;
        }
        else
        {
            error = 1;
            break;
        }
    }
    return error;
}

char *concat(char *pref, char *suff)
{
    while (*suff != '\n')
    {
        *pref = *suff;
        pref++;
        suff++;
    }
    return pref;
}

void print_string(char *string_array, char *temp_string)
{
    while (string_array != temp_string)
    {
        printf("%c", *string_array);
        string_array++;
    }
}
