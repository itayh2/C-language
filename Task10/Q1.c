#include <stdio.h>
#define SIZE 10
int main()
{
    int phone_num[SIZE] = { 0,5,4,2,8,8,7,1,3,3};
    int* p_phone_num[SIZE];
    int count = 0;
    int* pt = &count;
    for (int** p = p_phone_num; p < p_phone_num + SIZE; p++)
    {
        *p = phone_num + count;
        count++;
    }
    printf("The phone number is");
    for (int* pt = phone_num; pt < phone_num + SIZE; pt++)
        printf(" %d", *pt);
    for (int** p = p_phone_num; p < p_phone_num + SIZE; p++)
    {
        pt = *p;
        printf("\nThe adress are %p the phone number is %d", *p, *pt);
    }
    printf("\n");
}