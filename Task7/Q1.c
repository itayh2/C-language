#define SIZE 7
int arrChange(int arr[], int size, int choosesize, int addNumber);
#include <stdio.h>
int main()
{
    int arr[SIZE], choosesize, addNumber, check;
    printf("Please enter how many numbers you want to insert to the array between 1 to %d: ", SIZE);
    scanf("%d", &choosesize);
    for (int i = 0; i < choosesize; i++)
    {
        printf("%d. Please enter number to the array: ", i+1);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("The array is: ");
    for (int i = 0; i < choosesize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Please enter another number: ");
    scanf("%d", &addNumber);
    check = arrChange(arr, SIZE, choosesize, addNumber);
    if (check == 1)
    {
        printf("The array is: ");

        for (int i = 0; i < choosesize + 1; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for (int i = 0; i < choosesize; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
int arrChange(int arr[], int size, int choosesize, int addNumber)
{
    int temp = 0, temp2 = 0, index = 0;
    if(choosesize == size)
    {
        return 0;
    }
    if (arr[choosesize-1] < addNumber)
    {
        arr[choosesize] = addNumber;
        return 1;
    }
    for (int i = 0; i < choosesize; i++)
    {
        if (arr[i] > addNumber)
        {
            index = i;
            temp = arr[i];
            arr[i] = addNumber;
            break;
        }
    }
    for (int i = index + 1; i < choosesize + 1; i++)
    {
        temp2 = arr[i];
        arr[i] = temp;
        temp = temp2;
    }
    return 1;
}
