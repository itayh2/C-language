//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct
//{
//    int day;
//    int mounth;
//    int year;
//}date;
//
//typedef struct
//{
//    char* name;
//    char phone[10];
//}passenger;
//
//typedef struct
//{
//    char Tname[10];
//    date Tdate;
//    char destinationNmae[10];
//    passenger passengers[10];
//    int truepassengers;
//}trip;
//
//typedef struct
//{
//    trip* trips;
//    int numoftrips;
//}agency;
//
/////////////// functions signs
//trip* searchtrip(agency* P_agency, date date1);
//trip* settrip(trip* trip1);
//void addtrip(agency* P_agency, date date1);
//void setPassenger(passenger* passenger1);
//void addPassengers(agency* P_agency, date date1);
//
//////////////
//void main()
//{
//
//}
//
////////////// the functions
//
//trip* searchtrip(agency* P_agency,date date1) // שאלה 1
//{
//    trip* P_trip;
//    for (int i = 0; i < P_agency->numoftrips; i++)
//    {
//        if ((P_agency->trips->Tdate.day+i)==date1.day && (P_agency->trips->Tdate.mounth+i)==date1.mounth && (P_agency->trips->Tdate.year+i)==date1.year)
//        {
//            P_trip = P_agency->trips;
//            return P_trip;
//        }
//    }
//    return NULL;
//}
//
//void addtrip(agency* P_agency, date date1) // שאלה 2
//{
//    trip trip1;
//    int count;
//
//    count = P_agency->numoftrips;
//    if (searchtrip(P_agency,date1)==NULL)
//    {
//        P_agency->trips = (trip*)malloc((count + 1) * sizeof(trip));
//        if (P_agency->trips==NULL)
//        {
//            printf("ERROR-NO-MEMORY\n");
//            return;
//        }
//        settrip(*(&P_agency->trips + (count + 10)));
//    }
//    else
//    {
//        printf("there is already atrip in this date\n");
//        return;
//    }
//}
//
//void addPassengers(agency* P_agency, date date1) // שאלה 3
//{
//    int i, j, passengersNum;
//    
//    for ( i = 0; i < P_agency->numoftrips ; i++)
//    {
//        if ((P_agency->trips->Tdate.day==date1.day+i) && (P_agency->trips->Tdate.mounth+i)==date1.mounth && (P_agency->trips->Tdate.year+i)==date1.year)
//        {
//            printf("how many passengers would you like to add limited to 10 passengers?\n");
//            scanf("%d", &passengersNum);
//            if (passengersNum > 10)
//            {
//                printf("the trip is limited to 10 passengers only.\n 10 passengers added.");
//                passengersNum = 10;
//            }
//            for (j = 0 ; j < passengersNum ; j++)
//            {
//                setPassenger((P_agency->trips->passengers + j));
//            }
//            P_agency->trips->truepassengers = passengersNum;
//            return;
//        }
//    }
//    printf("current date is unavailable");
//    return;
//}
////
//trip* settrip (trip* trip1)
//{
//    trip* reTrip = NULL;
//    printf("what is the name of the trip?\n");
//    gets(reTrip->Tname);
//    printf("what is the date of the trip?\n");
//    printf("day:\n");
//    scanf("%d", &reTrip->Tdate.day);
//    printf("mounth:\n");
//    scanf("%d", &reTrip->Tdate.mounth);
//    printf("year:\n");
//    scanf("%d", &reTrip->Tdate.year);
//    printf("what is the destinatoin?\n");
//    gets(reTrip->destinationNmae);
//    reTrip->truepassengers = 0;
//    return reTrip;
//}
//
//void setPassenger(passenger* passenger1)
//{
//    char* name = NULL;
//
//    printf("please enter the passenger name\n");
//    gets(name);
//    passenger1->name = (char*)malloc(strlen(name) * sizeof(char));
//    if (passenger1->name==NULL)
//    {
//        printf("ERROR-NO-MEMORY\n");
//        return;
//    }
//    strcpy(passenger1->name, name);
//    printf("please enter passenger phone number\n");
//    gets(passenger1->phone);
//}
