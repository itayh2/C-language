#include <stdio.h>
int main()
{
    int number = 31630, day, hours, minutes;
    day = number / 10000;
    hours = number / 100 % 100;
    minutes = number % 100;
    printf("Today is the %dth day of Week, and the Time is %d:%d\n", day, hours, minutes);
}
