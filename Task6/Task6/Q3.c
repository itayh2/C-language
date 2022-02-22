//
//  Q3.c
//  Task6
//
//  Created by איתי חסיד on 17 Kislev 5781.
//
//// כתוב תכנית הקולטת מהמשתמש  N מספרים שלמים לתוך מערך numbers (גודל המערך הוא N אשר את ערכו אתם תחליטו)
//התוכנית תשנה את המערך כך שכל המספרים השליליים יהיו בתחילת המערך, לאחר מכן יופיעו האיברים שערכם שווה ל-0  ובסוף המערך יופיעו המספרים החיוביים.
//אין להשתמש במערך נוסף.
//כפלט התוכנית תדפיס את המערך לאחר השינוי.

//#define SIZE 10
//#include <stdio.h>
//int main()
//{
//    int numbers[SIZE], temp;
//    printf("Please insert %d numbers:\n", SIZE);
//    for (int i = 0; i < SIZE; i++)
//    {
//        scanf("%d", &numbers[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = i + 1; j < SIZE; j++)
//        {
//            if(numbers[j] < numbers[i])
//            {
//                temp = numbers[i];
//                numbers[i] = numbers[j];
//                numbers[j] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < SIZE; i++)
//    {
//        printf("%d ", numbers[i]);
//    }
//    printf("\n");
//}
