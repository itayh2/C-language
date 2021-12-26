#include <stdio.h>
int main()
{
    int students, seats, order, remainder;
    printf("Enter number of students:\n");
    scanf("%d", &students);
    printf("Enter number of seats per spaceship:\n");
    scanf("%d", &seats);
    remainder = students % seats;
    if (students > seats && remainder == 0)
    {
            order = students / seats;
        printf("You need %d ships\n", order);
    }
        else
        {
            order = students / seats;
            order++;
            printf("You need %d ships\n", order);
        }
}