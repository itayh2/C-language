#include <stdio.h>

int dateCheck(int day, int month, int year);
int checkYear(int year);
int main()
{
    int day, month, year;
    printf("Please enter the day:\n");
    scanf("%d", &day);
    printf("Please enter the mounth:\n");
    scanf("%d", &month);
    printf("Please enter the year:\n");
    scanf("%d", &year);
    if (day < 1 || month < 1 || year < 1)
        printf("The date is not valid\n");
    else
    {
        if (dateCheck(day, month, year) == 1)
            printf("The date is valid\n");
        else
            printf("The date is not valid\n");
    }
}

int dateCheck(int day, int month, int year)
{
    int check=0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        if (day <= 31)
            check = 1;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (day <= 30)
            check = 1;
        break;
    case 2:
        if (checkYear(year)==1)
        {
            if (day <= 29)
                check = 1;
        }
        else
        {
            if (day <= 28)
                check = 1;
        }
        break;
    default:
        break;
    }
    return check;
    }

int checkYear(int year)
    {
        int check = 1;
        if (year % 4 == 0 && year % 100 != 0)
            check = 1;
        else
        {
            if (year % 400 == 0)
                check = 1;
            else
                check = 0;
        }
        return check;
    }
