#define ROWS 6
#define COLS 3
#include <stdio.h>
int arrCheck(int arr1[][COLS]);
int arrCheck1(int arr1[], int arr2[]);
int main()
{
    int arr[ROWS][COLS], check;
    printf("Insert %d digits between 0 to 9 to %dx%d array: \n", ROWS * COLS, ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] < 0 || arr[i][j] > 9)
            {
                printf("You need to enter digits between 0 to 9, please try again: \n");
                j--;
            }
        }
    }
    check = arrCheck(arr);
    if (check == 1)
    {
        printf("The array is a mirror array\n");
    }
    else
    {
        printf("The array is not a mirror array\n");
    }

}
int arrCheck(int arr1[][COLS])
{
    int check = 0;
    for (int i = 0; i < ROWS / 2; i++)
    {
            if (arrCheck1(arr1[i], arr1[ROWS-i-1]))
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
int arrCheck1(int arr1[], int arr2[])
{
    int check = 0;
    for (int i = 0; i < COLS; i++)
    {
            if (arr1[i] == arr2[COLS-1-i])
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
