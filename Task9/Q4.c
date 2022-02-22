#define SIZE 10
#include <stdio.h>
void mirror(int *arr, int size);

int main()
{
    int arr[SIZE];
    printf("Please insert %d numbers:\n", SIZE);

    for (int *p = arr ; p < arr + SIZE ; p++)
    {
        scanf("%d", p);
    }
    mirror(arr, SIZE);
    for (int *p = arr; p < arr + SIZE; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");

}

void mirror(int *arr, int size)
{
    int *s = arr;
    int temp;
    for (int *p = arr + size - 1; p >= arr + size/2; p--)
    {
        temp = *p;
        *p = *s;
        *s = temp;
        s++;
    }
}
