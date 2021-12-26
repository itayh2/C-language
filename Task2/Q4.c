#include <stdio.h>
int main()
{
    int num1 = 13, num2 = 34;
    float num;
    num = num1 + ((double) num2 / 100);
    printf("num1 = %d, num2 = %d and decimal num = %f\n", num1, num2, num);
}