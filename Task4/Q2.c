#include <stdio.h>
int main()
{
    int number1, number2, max1 = 1, max2 = 1, savenumber1, savenumber2;
    printf("Insert a number1:\n");
    scanf("%d", &number1);
    printf("Insert a number2:\n");
    scanf("%d", &number2);
    savenumber1 = number1;
    savenumber2 = number2;
    while (number1 != 0)
    {
        max1 = max1 * (number1 % 10);
        number1 = number1 / 10;
    }
    while (number2 != 0)
    {
        max2 = max2 * (number2 % 10);
        number2 = number2 / 10;
    }
    (max1 > max2)? printf("%d\n", savenumber1): printf("%d\n", savenumber2);
}