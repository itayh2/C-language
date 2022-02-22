//
//  Q5.c
//  Task10
//
//  Created by איתי חסיד on 20 Tevet 5781.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define SIZE2 100
void BreakWord(char str[], char *arr[], int size, int *newSize);
int countOfDigits(char str[]);
int countOfWords(char str[]);
int main()
{
    int newSize;
    char *str[SIZE];
    char string[SIZE2];
    printf("Please insert a sentence: \n");
    gets(string);
    BreakWord(string, str, SIZE, &newSize);
    if (*str == NULL)
    {
        printf("No Memory\n");
    }
    else
    {
    printf("the new array is: \n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%s ", str[i]);
        free(str[i]);
        str[i] = NULL;
    }
    str[newSize] = NULL;
    printf("\n");
    }
}
void BreakWord(char str[], char *arr[], int size, int *newSize)
{
    int countDigits;
    *newSize = countOfWords(str);
    for (int i = 0; i < *newSize; i++)
    {
        countDigits = countOfDigits(str);
        *(str + countDigits) = 0;
        arr[i] = (char *)calloc((countDigits + 1), sizeof(char));
        strcpy(arr[i], (str));
        str = str + countDigits+1;
    }
}
int countOfDigits(char str[])
{
    int countOfDigitsOfWord = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            countOfDigitsOfWord++;
        }
        else
        {
            break;
        }
    }
    return countOfDigitsOfWord;
}
int countOfWords(char str[])
{
    int countOfOfWord = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            countOfOfWord++;
        }
    }
    return (countOfOfWord + 1);
}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define SIZE 10
//#define SIZE2 100
//char** BreakWord(char* str, char** arr, int size, int* newSize);
//int countOfDigits(char* str);
//int countOfWords(char* str);
//int main()
//{
//    int newSize = 0;
//    char** str[SIZE];
//    char string[SIZE2];
//    printf("Please insert a sentence: \n");
//    gets(string);
//    char** res = BreakWord(string, *str, SIZE, &newSize);
//    for (int i = 0; i <= newSize; i++)
//    {
//        if (*(res + i) != NULL)
//        {
//            printf("%s\n", *(res + i));
//            free(*(res + i));
//            *(res + i) = NULL;
//        }
//        else
//        {
//            printf("No Memory\n");
//        }
//    }
//}
//
//char** BreakWord(char* str, char** arr, int size, int* newSize)
//{
//    int countDigits;
//    *newSize = countOfWords(str);
//    for (int i = 0; i <= *newSize; i++)
//    {
//        countDigits = countOfDigits(str);
//        *(arr+i) = (char*)malloc((countDigits + 1) * sizeof(char));
//        if (*(arr + i) == NULL)
//        {
//            return arr;
//        }
//        strcpy(*(arr+i), str);
//        str = str + countDigits;
//    }
//    return arr;
//}
//int countOfWords(char* str)
//{
//    int countOfWord = 0;
//    long long len = strlen(str);
//    for (int i = 0; i < len ; i++)
//    {
//       if(*(str+i) == ' ' || *(str+i) == 0)
//        {
//            countOfWord++;
//        }
//    }
//    return countOfWord;
//}
//
//int countOfDigits(char* str)
//{
//    int countOfDigits = 0;
//    long long len = strlen(str);
//    for (int i = 0; i < len; i++)
//    {
//        countOfDigits++;
//        if (*(str+i) == ' ' || *(str+i) == 0 )
//        {
//           *(str+i)= 0;
//            break;
//        }
//    }
//    return countOfDigits;
//}
