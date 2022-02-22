#define SIZE 3
#include <stdio.h>
#include <stdlib.h>
int *FirstNumberInArray(int *arr[], int size, int *size1);
int main()
{
    int arr1[] = {1,17,823};
    int arr2[] = {202,77,12};
    int arr3[] = {-15,60,45};
    int *arr[] = {arr1, arr2, arr3};
    int Newsize;
    int* newArr = FirstNumberInArray(arr, SIZE, &Newsize);
    if (newArr == NULL)
    {
        printf("Memory allocation failed\n");
    }
    printf("The new array is: ");
    for (int i = 0; i < Newsize; i++)
    {
        printf(" %d", newArr[i]);
    }
    printf("\n");
    free(newArr);
    newArr = NULL;
}
int *FirstNumberInArray(int *arr[], int size, int *size1)
{
    int *NewArr = (int *)malloc(size * sizeof(int));
    if (NewArr == NULL)
    {
        return NewArr;
    }
    for (int i = 0; i < size; arr++,i++)
    {
        NewArr[i] = **arr;
    }
    *size1 = size;
    return NewArr;
}
