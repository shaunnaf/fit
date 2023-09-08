#include <math.h>
#include <stdio.h>

int main() {
    int number_flat_new, number_flat, entrance, floor, max_floor,
        flats_on_floor, curr_floor, curr_entrance;
    curr_floor = 1;
    curr_entrance = 1;
    scanf("%d", &number_flat_new);
    scanf("%d %d %d %d", &number_flat, &entrance, &floor, &max_floor);
    flats_on_floor =
        ceilf((float)number_flat / (max_floor * (entrance - 1) + floor));
    while (number_flat_new > flats_on_floor) {
        number_flat_new -= flats_on_floor;
        curr_floor += 1;
        if (curr_floor > max_floor) {
            curr_floor = 1;
            curr_entrance += 1;
        }
    }
    printf("%d %d", curr_entrance, curr_floor);
    return 0;
}
