#define SIZE 30
#include <stdio.h>
#include <string.h>
int maxLen(char str[]);
int main()
{
    char str[SIZE];
    int countMaxWord = 0;
    printf("Please insert a string up to %d words: \n", SIZE - 1);
    gets(str);
    countMaxWord = maxLen(str);
    printf("The count letters of Max Word is: %d\n", countMaxWord);

}
int maxLen(char str[])
{
    int countOfTav = strlen(str);
    int countMax = 0, tempMaxWord = 0;
    for (int i = 0; i < countOfTav; i++)
    {
        if(str[i] != ' ')
        {
            countMax++;
        }
        else
        {
            if (countMax > tempMaxWord)
            {
                tempMaxWord = countMax;
            }
            countMax = 0;
        }
    }
    if (countMax > tempMaxWord)
    {
        tempMaxWord = countMax;
    }
    return tempMaxWord;
}

