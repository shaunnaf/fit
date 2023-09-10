#include <stdio.h>

int main()
{
    int day, month, year, k;
    int flag = 0;
    scanf("%d %d %d %d", &day, &month, &year, &k);
    while (k != 0)
    {
        while (k >= 366)
        {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                if (flag == 0)
                {
                    if (month < 3)
                    {
                        year += 1;
                        k -= 366;
                    }
                    else
                    {
                        year += 1;
                        k -= 365;
                    }
                    flag = 1;
                }
                else
                {
                    year += 1;
                    k -= 366;
                }
            }
            else
            {
                flag = 1;
                k -= 365;
                year += 1;
            }
        }
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2 && flag == 1)
        {
            k -= 1;
        }
        while (k >= 31)
        {
            switch (month)
            {
            case 1:
                k -= 31;
                month += 1;
                break;
            case 2:
                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                {
                    k -= 29;
                    month += 1;
                    break;
                }
                else
                {
                    k -= 28;
                    month += 1;
                    break;
                }
            case 3:
                k -= 31;
                month += 1;
                break;
            case 4:
                k -= 30;
                month += 1;
                break;
            case 5:
                k -= 31;
                month += 1;
                break;
            case 6:
                k -= 30;
                month += 1;
                break;
            case 7:
                k -= 31;
                month += 1;
                break;
            case 8:
                k -= 31;
                month += 1;
                break;
            case 9:
                k -= 30;
                month += 1;
                break;
            case 10:
                k -= 31;
                month += 1;
                break;
            case 11:
                k -= 30;
                month += 1;
                break;
            case 12:
                k -= 31;
                month = 1;
                year += 1;
                break;
            }
        }
        switch (month)
        {
        case 1:
            day += k;
            k = 0;
            if (day > 31)
            {
                month += 1;
                day -= 31;
                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                {
                    if (day > 29)
                    {
                        day -= 29;
                        month += 1;
                    }
                }
                else
                {
                    if (day > 28)
                    {
                        day -= 28;
                        month += 1;
                    }
                }
            }
            break;
        case 2:
            day += k;
            k = 0;
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                if (day > 29)
                {
                    day -= 29;
                    month += 1;
                }
                break;
            }
            else
            {
                if (day > 28)
                {
                    day -= 28;
                    month += 1;
                }
                break;
            }
        case 3:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month += 1;
                if (day == 31)
                {
                    day -= 31;
                    month += 1;
                }
            }
            break;
        case 4:
            day += k;
            k = 0;
            if (day > 30)
            {
                day -= 30;
                month += 1;
            }
            break;
        case 5:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month += 1;
                if (day == 31)
                {
                    day -= 31;
                    month += 1;
                }
            }
            break;
        case 6:
            day += k;
            k = 0;
            if (day > 30)
            {
                day -= 30;
                month += 1;
            }
            break;
        case 7:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month += 1;
            }
            break;
        case 8:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month += 1;
                if (day == 31)
                {
                    day -= 31;
                    month += 1;
                }
            }
            break;
        case 9:
            day += k;
            k = 0;
            if (day > 30)
            {
                day -= 30;
                month += 1;
            }
            break;
        case 10:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month += 1;
                if (day == 31)
                {
                    day -= 31;
                    month += 1;
                }
            }
            break;
        case 11:
            day += k;
            k = 0;
            if (day > 30)
            {
                day -= 30;
                month += 1;
            }
            break;
        case 12:
            day += k;
            k = 0;
            if (day > 31)
            {
                day -= 31;
                month = 1;
                year += 1;
            }
            break;
        }
    }
    printf("%d %d %d", day, month, year);
    return 0;
}
