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
