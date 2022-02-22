//
//  main.c
//  Task11
//
//  Created by איתי חסיד on 1 Shevat 5781.
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define SIZE_ID 10
//#define SIZE_NAME 20
//typedef struct Student
//{
//    char id[SIZE_ID];
//    char fullName[SIZE_NAME];
//    int *grades;
//    int numOfGrades;
//} Student;
//
//void PrintStudent(Student *s);
//void readStudent(Student *s);
//void addGrade(Student *s, int grade);
//void freeStudent(Student *s);
//int main()
//{
//    int grade;
//    Student s;
//    readStudent(&s);
//    printf("Insert grade: ");
//    scanf("%d", &grade);
//    addGrade(&s, grade);
//    PrintStudent(&s);
//    freeStudent(&s);
//}
//void readStudent(Student *s)
//{
//    printf("Insert Student name: \n");
//    fseek(stdin, 0, SEEK_END);
//    gets(s->fullName);
//    printf("Insert Student Id: ");
//    fseek(stdin, 0, SEEK_END);
//    scanf("%s", s->id);
//    printf("How many grades?\n");
//    scanf("%d", &(s->numOfGrades));
//    if (s->numOfGrades)
//    {
//        s->grades = (int *)malloc(s->numOfGrades * sizeof(int));
//    }
//    else
//    {
//        s->grades = NULL;
//    }
////    if (s->grades = NULL)
////    {
////        to fill
////    }
//    if (s->numOfGrades)
//    {
//        printf("Insert %d grades: \n", s->numOfGrades);
//        for (int i = 0; i < s->numOfGrades; i++)
//        {
//            scanf("%d", &(s->grades[i]));
//        }
//    }
//    
//}
//
//void PrintStudent(Student *s)
//{
//    printf("Name is %s, Id is %s, ", s->fullName, s->id);
//    if (s->numOfGrades == 0)
//    {
//        printf("No Grades\n");
//    }
//    else
//    {
//        printf("Grades are: ");
//        for (int i = 0; i < s->numOfGrades; i++)
//        {
//            printf("%d, ", s->grades[i]);
//        }
//        printf("\n");
//    }
//}
//void addGrade(Student *s, int grade)
//{
//    s->grades = (int *)realloc(s->grades, (s->numOfGrades+1) * sizeof(int));
//    s->grades[s->numOfGrades] = grade;
//    s->numOfGrades++;
//}
//void freeStudent(Student *s)
//{
//    free(s->grades);
//    s->grades = NULL;
//}
