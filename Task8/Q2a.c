#define SIZE 30
#include <stdio.h>
#include <string.h>
void left_Trim(char str[]);
int main()
{
    char str[SIZE];
    printf("Please insert a string up to %d words: \n", SIZE-1);
    gets(str);
    left_Trim(str);
    printf("%s", str);
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
