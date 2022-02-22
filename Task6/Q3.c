#define SIZE 10
#include <stdio.h>
int main()
{
    int numbers[SIZE], temp;
    printf("Please insert %d numbers:\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if(numbers[j] < numbers[i])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
