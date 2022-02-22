#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4
char *BiggestLetters(char *strArr[], int size);
int main()
{
    char *arr[] = {"hello","and","good","morning"};
    char *res = BiggestLetters(arr, SIZE);
    if (res == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
    printf("Biggest letters string is %s\n", res);
    }
    free(res);
    res = NULL;
}

char *BiggestLetters(char *strArr[], int size)
{

    char *str = (char*)malloc((size + 1) * sizeof(char));
    if (str == NULL)
        {
            return str;
        }
    else
    {
    char max = 'A';
    int length;
    for (int i = 0; i < size; i++)
    {
        length = strlen(strArr[i]);
        for (int j = 0; j < length; j++)
        {
            if(*(*(strArr + i) + j) > max)
            {
                max = *(*(strArr + i) + j);
            }
        }
        str[i] = max;
        max = 'A';
    }
    }
    return str;
}