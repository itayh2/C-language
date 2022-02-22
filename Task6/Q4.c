#define SIZE 10
#include <stdio.h>
int main()
{
    int arr[SIZE] = {0}, numbers, countmax = 0;
    printf("Please insert 15 digits:\n");
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &numbers);
        arr[numbers]++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > countmax)
        {
            countmax = arr[i];
        }
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] == countmax)
            {
                printf("%d ", i);
            }
        }
    printf("\n");
    }