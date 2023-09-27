#include <math.h>
#include <stdio.h>

int main()
{
    int number_flat_new, number_flat, entrance, floor, max_floor,
        flats_on_floor, curr_floor, curr_entrance;

    curr_floor = curr_entrance = 1;
    scanf("%d", &number_flat_new);
    scanf("%d %d %d %d", &number_flat, &entrance, &floor, &max_floor);
    int r = number_flat % (max_floor * (entrance - 1) + floor);
    if (r == 0)
    {
        flats_on_floor = (float)number_flat / (max_floor * (entrance - 1) + floor);
    }
    else
    {
        flats_on_floor = (int)((float)number_flat / (max_floor * (entrance - 1) + floor)) + 1;
    }
    while (number_flat_new > flats_on_floor)
    {
        number_flat_new -= flats_on_floor;
        curr_floor += 1;
        if (curr_floor > max_floor)
        {
            curr_floor = 1;
            curr_entrance += 1;
        }
    }
    printf("%d %d", curr_entrance, curr_floor);
    return 0;
}
