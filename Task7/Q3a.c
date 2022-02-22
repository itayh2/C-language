#define SIZE 3
#include <stdio.h>
int arrCheck(int arr1[], int arr2[]);
int main()
{
    int arr1[SIZE], arr2[SIZE], check = 0;
    printf("Insert %d numbers to arr1: \n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Insert %d numbers to arr2: \n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr2[i]);
    }
    check = arrCheck(arr1, arr2);
    if (check == 1)
    {
        printf("The arrays are a mirror duo\n");
    }
    else
    {
        printf("The arrays are not a mirror duo\n");
    }

}
int arrCheck(int arr1[], int arr2[])
{
    int check = 0;
    for (int i = 0; i < SIZE; i++)
    {
            if (arr1[i] == arr2[SIZE-1-i])
            {
                check = 1;
            }
            else
            {
                check = 0;
                break;
            }
    }
    return check;
}
