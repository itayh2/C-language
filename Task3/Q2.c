#include <stdio.h>
int main()
{
    int months, addmonths, newmonth;
    printf("Please enter number of months:\n");
    scanf("%d", &months);
    if(months < 1 || months > 12)
    {
        printf("The months number have to be between 1-12\n");
    }
    else
    printf("Please enter number of add months:\n");
    scanf("%d", &addmonths);
    newmonth = (months + addmonths-1) % 12 + 1;
    printf("The new months is: %d\n", newmonth);
}