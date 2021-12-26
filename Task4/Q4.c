#include <stdio.h>
int main()
{
    int num = 0;
    while (num <= 0)
    {
        printf("Please insert a positive number of the board size:\n");
        scanf("%d", &num);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if ((i + j) % 2 == 0)
            {
                printf("X");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
}