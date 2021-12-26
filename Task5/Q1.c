int sumOfDivide(int number);
#include <stdio.h>
int main()
{
    int number, res;
    printf("Insert a number:\n");
    scanf("%d", &number);
    res = sumOfDivide(number);
    printf("The sum of the divide of this number is: %d\n", res);
}
int sumOfDivide(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if((number % i) == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}