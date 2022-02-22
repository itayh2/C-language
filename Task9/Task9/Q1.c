//
//  Q1.c
//  Task9
//
//  Created by איתי חסיד on 7 Tevet 5781.
//
//#define SIZE 10
//#include <stdio.h>
//int main()
//{
//    int arr[SIZE];
//    int *addressMin = arr, *addressMax = arr;
//    int temp;
//    printf("Please insert %d numbers: \n", SIZE);
//    for (int *p = arr; p < arr + SIZE; p++)
//    {
//        scanf("%d", p);
//    }
//    for (int *p = arr+1; p < arr + SIZE; p++)
//    {
//        if(*p < *addressMin)
//        {
//            addressMin = p;
//
//        }
//        else
//        {
//            if (*p > *addressMax)
//            {
//                addressMax = p;
//            }
//        }
//    }
//    printf("The address of the minimum number is %p\n", addressMin);
//    printf("The value of the minimum numbers is %d\n", *addressMin);
//    temp = *addressMin;
//    *addressMin = *addressMax;
//    *addressMax = temp;
//    printf("The new array is:\n");
//    for (int *p = arr; p < arr + SIZE; p++)
//    {
//        printf("%d ", *p);
//    }
//    printf("\n");
//}
