#define SIZE 30
#include <stdio.h>
#include <string.h>
void left_Trim(char str[]);
void right_Trim(char str[]);
void my_trim(char str[]);
int main()
{
    char str[SIZE];
    printf("Please insert a string up to %d words: \n", SIZE - 1);
    gets(str);
    my_trim(str);
    printf("%s", str);
}
void my_trim(char str[])
{
    left_Trim(str);
    right_Trim(str);
}
void left_Trim(char str[])
{
    int counttav = strlen(str);
    while (str[counttav-1] == ' ')
    {
        str[counttav-1] = '\0';
        counttav--;
    }
}
void right_Trim(char str[])
{
    int countOfTav = strlen(str);
    int i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    for (int j = 0; j < countOfTav; j++)
    {
        str[j] = str[i];
        i++;
    }
}
