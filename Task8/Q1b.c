#define SIZE 30
#include <stdio.h>
#include <string.h>
int findNndAppereanceIndex(char str[], char tav, int num);
int main()
{
    char str[SIZE], tav;
    int index, num;
    printf("Please insert String up to %d words: \n", SIZE-1);
    gets(str);
    printf("Please insert a Char: ");
    scanf(" %c", &tav);
    printf("Please insert a number: ");
    scanf("%d", &num);
    index = findNndAppereanceIndex(str, tav, num);
    printf("%drd '%c' found at index: %d\n", num, tav, index);
}
int findNndAppereanceIndex(char str[], char tav, int num)
{
    int countOfTav = strlen(str);
    int check = 0, count = 0;
    for (int i = countOfTav - 1; i >= 0; i--)
    {
        if (str[i] == tav)
        {
            check = i;
            count++;
        }
        if (count == num)
        {
            return check;
        }
    }
    return -1;
}
