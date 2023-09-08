#include <stdio.h>

int main() {
    int hours, minute, second, new_hours, new_minute, new_second, add_time;
    scanf("%d %d %d %d", &hours, &minute, &second, &add_time);
    new_second = second + (add_time % 60);
    new_minute = minute + (add_time / 60 % 60);
    new_hours = hours + (add_time / 60 / 60 % 24);
    if (new_second > 59) {
        new_second %= 60;
        new_minute += 1;
    }
    if (new_minute > 59) {
        new_minute %= 60;
        new_hours += 1;
    }
    new_hours %= 24;
    printf("%d %d %d", new_hours, new_minute, new_second);
    return 0;
}
