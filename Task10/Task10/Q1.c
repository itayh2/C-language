//
//  Q1.c
//  Task10
//
//  Created by איתי חסיד on 15 Tevet 5781.
//

//#include <stdio.h>
//#define SIZE 10
//int main()
//{
//    int phone_num[SIZE] = { 0,5,4,2,8,8,7,1,3,3};
//    int* p_phone_num[SIZE];
//    int count = 0;
//    int* pt = &count;
//    for (int** p = p_phone_num; p < p_phone_num + SIZE; p++)
//    {
//        *p = phone_num + count;
//        count++;
//    }
//    printf("The phone number is");
//    for (int* pt = phone_num; pt < phone_num + SIZE; pt++)
//        printf(" %d", *pt);
//    for (int** p = p_phone_num; p < p_phone_num + SIZE; p++)
//    {
//        pt = *p;
//        printf("\nThe adress are %p the phone number is %d", *p, *pt);
//    }
//    printf("\n");
//}

//#define SIZE 10
//#include <stdio.h>
//int main()
//{
//    int phone_num[SIZE] = { 0, 5, 4, 2, 8, 8, 7, 1 ,3 ,3 };
//    int *p_phone_num[SIZE];
//    int i = 0;
//    for (int **ptr1 = p_phone_num; ptr1 < p_phone_num + SIZE; ptr1++)
//    {
//        *ptr1 = phone_num + i;
//        i++;
//    }
//    printf("My Phone number is: \n");
//    for (int *ptr2 = phone_num; ptr2 < phone_num + SIZE; ptr2++)
//    {
//        printf("%d", *ptr2);
//    }
//    printf("\n");
//    for (int *ptr3 = p_phone_num; ptr3 < p_phone_num + SIZE; ptr3++)
//    {
//        printf("%p\n", *ptr3);
//    }
//    printf("\n");
//    for (int **ptr4 = p_phone_num; ptr4 < p_phone_num + SIZE; ptr4++)
//    {
//        printf("%d", **ptr4);
//    }
//}
