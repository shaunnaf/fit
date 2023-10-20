#include <stdio.h>
#include <stdlib.h>

typedef struct Label_s
{
    char name[16]; // имя автора (заканчивается нулём)
    int age;       // возраст автора (сколько лет)
} Label;

typedef struct NameStats_s
{
    int cntTotal; // сколько всего подписей
    int cntLong;  // сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;  // сколько всего подписей
    int cntAdults; // сколько подписей взрослых (хотя бы 18 лет)
    int cntKids;   // сколько подписей детей (меньше 14 лет)
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges);
int scanCount(int *count);
int scanData(int count, Label *data);

int main()
{
    int count;
    if (!scanCount(&count))
    {
        Label *data = malloc(sizeof(Label) * count);
        NameStats name_stats;
        AgeStats age_stats;
        name_stats.cntTotal = 0;
        name_stats.cntLong = 0;
        age_stats.cntTotal = 0;
        age_stats.cntAdults = 0;
        age_stats.cntKids = 0;
        if (!scanData(count, data))
        {
            calcStats(data, count, &name_stats, &age_stats);
            printf("names: total = %d\r\n", count);
            printf("names: long = %d\r\n", name_stats.cntLong);
            printf("ages: total = %d\r\n", count);
            printf("ages: adult = %d\r\n", age_stats.cntAdults);
            printf("ages: kid = %d", age_stats.cntKids);
        }
        else
        {
            printf("Error");
        }
    }
    else
    {
        printf("Error");
    }
    return 0;
}

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    for (int i = 0; i < cnt; i++)
    {
        int j = 0;
        while (arr[i].name[j] != '\0')
        {
            j++;
        }
        if (j > 10)
        {
            oNames->cntLong++;
        }
        if (arr[i].age >= 18)
        {
            oAges->cntAdults++;
        }
        else if (arr[i].age < 14)
        {
            oAges->cntKids++;
        }
        oAges->cntTotal++;
        oNames->cntTotal++;
    }
}

int scanCount(int *count)
{
    int error = 0;
    if (scanf("%d", count) != 1)
    {
        error = 1;
    }
    return error;
}

int scanData(int count, Label *data)
{
    int error = 0;

    for (int i = 0; i < count; i++)
    {
        if (scanf("%s %d let", data[i].name, &data[i].age) != 2)
        {
            error = 1;
            break;
        }
    }
    return error;
}
