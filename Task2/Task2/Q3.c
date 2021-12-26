//
//  Q3.c
//  Task2
//
//  Created by איתי חסיד on 17 Heshvan 5781.
//

//#include <stdio.h>
//int main()
//{
//    int number = 32359, day, hours, minutes;
//    int addminutes = 800, sumOfMin, day1, hours1, minutes1;
//    day = number / 10000;
//    hours = number / 100 % 100;
//    minutes = number % 100;
//    sumOfMin = minutes + addminutes; // חיבור הדקות למספר חדש שסוכם אותו
//    hours1 = hours + sumOfMin / 60; // לוקח את מספר השעות בשלמים ושם בתוך משתנה השעות
//    minutes1 = sumOfMin % 60; // לוקח את השארית של הדקות ומכניס לתוך משתנה הדקות
//    day1 = day + (hours1 / 24); // מוסיף את מספר הימים מהשעות
//    hours1 = hours1 % 24; // שומר את השעות לאחר שהוספנו את הימים
//    day1 = day1 % 7;
//    printf("Today is the %dth day of Week, and the Time is %d:%d\n", day, hours, minutes);
//    printf("After %d min addition: The day is the %dth day of week, and the time is %d:%d\n", addminutes, day1, hours1, minutes1);
//}
