#define _CRT_SECURE_NO_WARNINGS
#define SIZE 60
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
}Date;
typedef struct
{
    char* passengername;
    char phonenum[10];
}Passenger;
typedef struct
{
    char tripname[10];
    Date tripdate;
    char destination[10];
    Passenger passenger[10];
    int actualpassenger;
}Trip;
typedef struct
{
    Trip* trips;
    int tripsnum;
}Agency;

void SetPassenger(Passenger* passenger);
Trip* SearchTrip(Agency* agency, Date date);
void AddTrip(Agency* agency, Date date);
void AddPassenger(Agency* agency, Date date);
void setTrip(Trip* set);
void printTravelAgencyDetails(Agency* agency);
void printTrip(Trip* trip);
int main()
{
    Date A;
    Agency Travelist = {NULL,0};
    int decision;
    printf("Please enter what you want to do: To Trips 1, To add passengers 2, To Exit 0\n");
    scanf("%d", &decision);
    while (decision <= 2 && decision >=0)
    {
        if (decision == 1)
        {
            printf("Please enter the date for the trip you are looking for,order by date, month, year:\n");
            scanf(" %d %d %d", &A.day, &A.month, &A.year);
            AddTrip(&Travelist,A);
        }
        else if (decision == 2)
        {
            printf("Please enter the date for the trip you are looking for, order by date - month - year:\n");
            fseek(stdin, 0, SEEK_END);
            scanf(" %d %d %d", &A.day, &A.month, &A.year);
            AddPassenger(&Travelist, A);
        }
        else if (decision == 0)
        {
            printf("Thank you\n");
            break;
        }
        printf("Please enter another choice: To Trips 1, To add passengers 2, To Exit 0\n");
        scanf("%d", &decision);
    }
        printTravelAgencyDetails(&Travelist);
        free(Travelist.trips);
        Travelist.trips = NULL;        
}
Trip* SearchTrip(Agency* agency, Date date)
{
    int temp = agency->tripsnum;
    for (Trip* ptr=agency->trips;ptr<agency->trips+temp;ptr++)
    {
        if (ptr->tripdate.day == date.day && ptr->tripdate.month == date.month&&ptr->tripdate.year == date.year)
        {
            return ptr;
        }
    }
    return NULL;
}
void AddTrip(Agency* agency, Date date)
{
    if (SearchTrip(agency,date))
    {
        printf("trip already exist\n");
        return;
    }
    agency->tripsnum++;
    if (agency->tripsnum == 1)
    {
        agency->trips = (Trip*)malloc(sizeof(Trip));
        if (agency->trips == NULL)
        {
            return;
        }
    }
    else
    {
        agency->trips = (Trip*)realloc(agency->trips, agency->tripsnum*sizeof(Trip));
        if (agency->trips == NULL)
        {
            return;
        }
    }
    setTrip(agency->trips);
}
void AddPassenger(Agency* agency, Date date)
{
    int Passenger, tmp = 0;
    if (SearchTrip(agency, date))
    {
        printf("How many passengers do you want to enter:\n\n");
        scanf("%d", &Passenger);
        if (agency->trips->actualpassenger+Passenger < 10)
        {
            tmp = agency->trips->actualpassenger;
            for (int i=0;i <Passenger;i++)
            {
                SetPassenger(&agency->trips->passenger[i+tmp]);
                agency->trips->actualpassenger++;
            }
        }
        else
            printf("The trip is full\n");
    }
}
void setTrip(Trip* set)
{
    printf("Please enter the trip name:\n");
    fseek(stdin, 0, SEEK_END);
    gets(set->tripname);
    printf("Please enter the destination:\n");
    gets(set->destination);
    printf("Please enter the date order by day - month - year:\n");
    scanf("%d", &set->tripdate.day);
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &set->tripdate.month);
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &set->tripdate.year);
    set->actualpassenger = 0;
}
void SetPassenger(Passenger* passenger)
{
    char name[10];
    printf("Please enter your name:\n");
    fseek(stdin, 0, SEEK_END);
    gets(name);
    long long size = strlen(name);
    passenger->passengername = (char*)malloc((size+1)*sizeof(char));
    if (!passenger->passengername)
    {
        return;
    }
    strcpy(passenger->passengername,name);
    fseek(stdin, 0, SEEK_END);
    printf("Please insert your phone number: \n");
    gets(passenger->phonenum);
}
void printTravelAgencyDetails(Agency* agency)
{
    for (int i = 0;i < agency->tripsnum;i++)
    {
        printTrip(&agency->trips[i]);
    }
}
void printTrip(Trip* trip)
{
    printf("Trip Name: %s\n", trip->tripname);
    printf("Trip Date: %d.%d.%d\n", trip->tripdate.day, trip->tripdate.month, trip->tripdate.year);
    printf("Destination: %s\n", trip->destination);
    printf("Actual Passenger: %d\n", trip->actualpassenger);
    for (int i = 0; i < trip->actualpassenger; i++)
    {
        printf("Passenger Name: %s ", trip->passenger[i].passengername);
        printf("and his Phone Number: %s\n", trip->passenger[i].phonenum);
    }
    
}




