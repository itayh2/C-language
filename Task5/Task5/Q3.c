//
//  Q3.c
//  Task5
//
//  Created by איתי חסיד on 8 Kislev 5781.
//

//int checkDate(unsigned int day,unsigned int month,unsigned int year);
//int helpYear(unsigned int year1);
//#include <stdio.h>
//int main()
//{
//    int day, month, year;
//    int check;
//    printf("Insert a day:\n");
//    scanf("%d", &day);
//    printf("Insert a month:\n");
//    scanf("%d", & month);
//    printf("Insert a year:\n");
//    scanf("%d", &year);
//    check = checkDate(day, month, year);
//    if(check == 1)
//    {
//        printf("The date is valid\n");
//    }
//    else
//    {
//        printf("The date is invalid\n");
//    }
//
//
//}
//int checkDate(unsigned int day,unsigned int month,unsigned int year)
//{
//    int countdayoffeb = 0;
//    if(month >= 1 && month <= 12)
//        {
//       if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//       {
//           if(day >= 1 && day <= 31)
//           {
//               return  1;
//           }
//           else
//           {
//               return 0;
//           }
//       }
//           if (month == 4 || month == 6 || month == 9 || month == 11 )
//            {
//                if (day >= 1 && day <= 30)
//                {
//                    return 1;
//                }
//                else
//                {
//                    return 0;
//                }
//            }
//            if(month == 2)
//            {
//                countdayoffeb = helpYear(year);
//                if(countdayoffeb == 29)
//                {
//                    if(day >= 1 && day <= 29)
//                    {
//                        return 1;
//                    }
//                    else
//                    {
//                        return 0;
//                    }
//                }
//                if (countdayoffeb == 28)
//                {
//                    if(day >= 1 && day <= 28)
//                    {
//                        return 1;
//                    }
//                    else
//                    {
//                        return 0;
//                    }
//                }
//            }
//        }
//    return 0;
//}
//int helpYear(unsigned int year1)
//{
//    int countday = 0;
//    if(year1 % 4 == 0)
//    {
//        if(year1 % 100 == 0)
//        {
//            if(year1 % 400 == 0)
//            {
//                countday = 29;
//            }
//            else
//            {
//                countday = 28;
//            }
//        }
//        else
//        {
//            countday = 29;
//        }
//    }
//    else
//    {
//        countday = 28;
//    }
//    return countday;
//}

