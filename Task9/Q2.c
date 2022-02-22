#define SIZE 10
#include <stdio.h>
int main()
{
    int phone_num[SIZE] = {0, 5, 4, 2, 8, 8, 7, 1 ,3 ,3};
    int *p_phone_num[SIZE];
    int i = 0;
    for (int *ptr1 = p_phone_num; ptr1 < p_phone_num + SIZE; ptr1++)
    {
        *ptr1 = phone_num + i;
        i++;
    }
    printf("My Phone number is: \n");
    for (int *ptr2 = phone_num; ptr2 < phone_num + SIZE; ptr2++)
    {
        printf("%d", *ptr2);
    }
    printf("\n");
    for (int *ptr3 = p_phone_num; ptr3 < p_phone_num + SIZE; ptr3++)
    {
        printf("%p\n", *ptr3);
    }
    printf("\n");
    for (int *ptr4 = p_phone_num; ptr4 < p_phone_num + SIZE; ptr4++)
    {
        int *ptr5 = *ptr4;
        printf("%d", *ptr5);
    }
}

