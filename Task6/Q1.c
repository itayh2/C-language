#define SIZE 10
#include <stdio.h>
int main()
{
    double arr[SIZE], sum = 0, avg = 0;
    int count = 0;
    printf("Please insert %d grades:\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%lf", &arr[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    avg = sum / SIZE;
    for (int i = 0; i < SIZE; i++)
    {
        if(arr[i] < avg)
        {
            count++;
        }
    }
    printf("%d trainers run less the from the average time which is %.2lf\n", count, avg);
}