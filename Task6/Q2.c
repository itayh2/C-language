#define SIZE 8
#include <stdio.h>
int main()
{
    int numbers[SIZE], check = 0, temp;
    printf("Please insert %d numbers:\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < SIZE-1; i++)
    {
        if (numbers[i] < numbers[i + 1])
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    if (check == 0)
    {
        printf("The array is not sorted\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d", numbers[i]);
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i += 2)
        {
            temp = numbers[i + 1];
            numbers[i + 1] = numbers[i];
            numbers[i] = temp;
        }
        printf("The array is sorted\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d", numbers[i]);
        }
    }
    printf("\n");
}
