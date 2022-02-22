#define SIZE 30
#include <stdio.h>
#include <string.h>
int findLastIndex(char str[], char tav);
int main()
{
    char str[SIZE], tav;
    int index;
    printf("Please insert a String up to %d words: \n", SIZE-1);
    gets(str);
    printf("Please insert a Char: ");
    scanf(" %c", &tav);
    index = findLastIndex(str, tav);
    printf("'%c' found at index: %d\n", tav, index);
}
int findLastIndex(char str[], char tav)
{
    int countOfTav = strlen(str);
    int check = 0;
    for (int i = 0; i < countOfTav; i++)
    {
        if (str[i] == tav)
        {
            check = i + 1;
        }
    }
    if (check != 0)
    {
        return check - 1;
    }
    return -1;
}
