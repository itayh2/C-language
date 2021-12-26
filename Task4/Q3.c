#include <stdio.h>
int main()
{
    int number,number1 = 0, maxdigit = 0, mindigit = 10;
    printf("Insert a number:\n");
    scanf("%d", &number);
    number1 = number;
    while (number1 != 0)
    {
        if(maxdigit < number1 % 10)
        {
            maxdigit = number1 % 10;
        }
        if (mindigit > number1 % 10)
        {
            mindigit = number1 % 10;
        }
        number1 = number1 / 10;
    }
    for (int i = mindigit; i <= maxdigit; i++)
    {
        printf("%d", i);
    }
    printf("\n");
}
