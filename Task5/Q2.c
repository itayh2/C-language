const int one = 1;
const int zero = 0;

#include <stdio.h>
int sumOfDivide(int number1, int number2);

int main()
{
    int number1, number2, res;
    printf("Insert a number1:\n");
    scanf("%d", &number1);
    printf("Insert a number2:\n");
    scanf("%d", &number2);
    res = sumOfDivide(number1, number2);
    if (res == one)
    {
        printf("The numbers is friends\n");
    }
    else
    {
        printf("The numbers is not friends\n");

    }
}
int sumOfDivide(int number1, int number2)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < number1; i++)
    {
        if((number1 % i) == 0)
        {
            sum1 = sum1 + i;
        }
    }
    for (int j = 1; j < number2; j++)
    {
        if ((number2 % j) == 0)
        {
            sum2 = sum2 + j;
        }

    }
    if ((sum1 == number2) && (sum2 == number1))
    {
        return one;
    }
    else
    {
        return zero;
    }
    }