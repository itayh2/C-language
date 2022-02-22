//
//  Q3.c
//  Task11
//
//  Created by איתי חסיד on 2 Shevat 5781.
//
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20
typedef struct Real
{
    char* num;
    char* frac;
} Real;
Real buildStruck(int num, int frac);
char *struct2array(Real *s);
void real_add_as_String(Real *numToAdd, Real *base);
int main()
{
        Real newArr; // שאלה 1
        int num, frac; // שאלה 1
        char *newString = NULL; // 2 שאלה
        printf("Q1. Please insert 2 numbers: \n"); // שאלה 1
        fseek(stdin, 0, SEEK_END); // שאלה 1
        scanf("%d %d", &num, &frac); // שאלה 1
        newArr = buildStruck(num, frac); // שאלה 1
        if (newArr.num == NULL || newArr.frac == NULL) // שאלה 1
            {
                printf("Q1. The structure has not been updated\n"); // שאלה 1
            }
        else
            {
            printf("Q1. The structure has been updated and is: %s.%s\n", newArr.num, newArr.frac); // שאלה 1
            }
        printf("----------------------------------------------------------------\n");
        newString = struct2array(&newArr); // שאלה 2
        if (newString == NULL)  // שאלה 2
        {
            printf("Q2. No space was allocated for the string\n"); // שאלה 2
        }
        else
        {
            printf("Q2. The updated string is: %s\n", newString);  // שאלה 2

        }
        free(newArr.num); // שאלה 1
        newArr.num = NULL; // שאלה 1
        free(newArr.frac); // שאלה 1
        newArr.frac = NULL; // שאלה 1
        free(newString); // שאלה 2
        newString = NULL; // שאלה 2
    printf("----------------------------------------------------------------\n");
    Real base, numToAdd; // שאלה 3
    char *newBase = NULL; // שאלה 3
    char baseNum[SIZE],baseFrac[SIZE],numAdd[SIZE], numFrac[SIZE]; // שאלה 3
    printf("Q3. Insert please number:\n"); // שאלה 3
    fseek(stdin, 0, SEEK_END);
    printf("The whole part: ");
    gets(baseNum); // שאלה 3
    fseek(stdin, 0, SEEK_END);
    printf("The incomplete part: ");
    gets(baseFrac); // שאלה 3
    printf("Q3. Insert please number:\n"); // שאלה 3
    fseek(stdin, 0, SEEK_END);
    printf("The whole part: ");
    gets(numAdd); // שאלה 3
    fseek(stdin, 0, SEEK_END);
    printf("The incomplete part: ");
    gets(numFrac); // שאלה 3
    base.num = baseNum; // שאלה 3
    base.frac = baseFrac; // שאלה 3
    numToAdd.num = numAdd; // שאלה 3
    numToAdd.frac = numFrac; // שאלה 3
    real_add_as_String(&numToAdd, &base); // שאלה 3
    if (base.num == NULL) // שאלה 3
    {
        printf("Q3. The whole part of the number is empty\n"); // שאלה 3
    }
    newBase = struct2array(&base); // שאלה 3
    if (newBase == NULL) // שאלה 3
        {
            printf("Q3. No space was allocated for the string\n"); // שאלה 3
        }
        else
        {
            printf("Q3. The sum of the operation of the connection between the two structures is: %s\n",  newBase); // שאלה 3
        }

    free(base.num); // שאלה 3
    base.num = NULL; // שאלה 3
    free(base.frac); // שאלה 3
    base.frac = NULL; // שאלה 3
    free(newBase); // שאלה 3
    newBase = NULL; // שאלה 3
}
Real buildStruck(int num, int frac) // שאלה 1
{
    Real newArr;
    int countOfDigitsNum = 0, countOfDigitsFrac = 0, tempNum = num, tempFrac = frac;
    while (num != 0)
    {
        num = num / 10;
        countOfDigitsNum++;
    }
    while (frac != 0)
    {
        frac = frac / 10;
        countOfDigitsFrac++;
    }
    newArr.num = (char*)malloc((countOfDigitsNum + 1) * sizeof(char));
    newArr.frac = (char*)malloc((countOfDigitsFrac + 1) * sizeof(char));

    if (newArr.num == NULL || newArr.frac == NULL)
    {
        return newArr;
    }
    else
    {
    for (char* p = newArr.num + countOfDigitsNum - 1; p >= newArr.num; p--)
    {
        *p = (char)(tempNum % 10+48);
        tempNum = tempNum / 10;
    }
    newArr.num[countOfDigitsNum] = 0;

    for (char* p = newArr.frac + countOfDigitsFrac - 1; p >= newArr.frac; p--)
    {
        *p = (char)(tempFrac % 10+48);
        tempFrac = tempFrac / 10;
    }
    newArr.frac[countOfDigitsFrac] = 0;
    return newArr;
    }
}
char *struct2array(Real *s) // שאלה 2
{
    long long count1 = strlen(s->num);
    long long count2 = strlen(s->frac);
    char *newString = (char *)malloc((count1 + count2 + 2) * sizeof(char));
    if (newString == NULL)
    {
        return NULL;
    }
    else
    {
        strcpy(newString, s->num);
        strcat(newString, ".");
        strcat(newString, s->frac);
        newString[count1+count2+1] = 0;
    }
    return newString;
}

void real_add_as_String(Real *numToAdd, Real *base) // שאלה 3
{
    int numAdd = 0, fracAdd = 0, numBase = 0, fracBase = 0, TempFracAdd, TempfracBase;
    int countDigits = 0, countDigits1 = 0, countmax = 0, countShalem = 0, countSherit = 0;
    int tempNumAdd = 0;
    int j = 0, index = 0, modolo = 0;
    while (numToAdd->num[j] != 0)
    {
        countDigits++;
        j++;
    }
    for (int i = countDigits - 1; i >= 0; i--)
    {
        numAdd = (numAdd * 10) + ((int)numToAdd->num[index] - 48);
        index++;
    }
    countDigits = 0;
    j = 0;
    index = 0;

    while (numToAdd->frac[j] != 0)
    {
        countDigits++;
        j++;
    }
    for (int i = countDigits - 1; i >= 0; i--)
    {
        fracAdd = (fracAdd * 10) + ((int)numToAdd->frac[index] - 48);
        index++;
    }
    countDigits = 0;
    j = 0;
    index = 0;

    while (base->num[j] != 0)
    {
        countDigits++;
        j++;
    }
    for (int i = countDigits - 1; i >= 0; i--)
    {
        numBase = (numBase * 10) + ((int)base->num[index] - 48);
        index++;
    }
    countDigits = 0;
    j = 0;
    index = 0;

    while (base->frac[j] != 0)
    {
        countDigits++;
        j++;
    }
    for (int i = countDigits - 1; i >= 0; i--)
    {
        fracBase = (fracBase * 10) + ((int)base->frac[index] - 48);
        index++;
    }
    countDigits = 0;
    numAdd = numAdd + numBase;
    TempFracAdd = fracAdd;
    TempfracBase = fracBase;
    while(fracAdd != 0)
    {
        fracAdd = fracAdd / 10;
        countDigits++;
    }
    while(fracBase != 0)
    {
        fracBase = fracBase / 10;
        countDigits1++;
    }
    if (countDigits > countDigits1)
    {
        countmax = pow(10, countDigits);
        TempfracBase = TempfracBase * (pow(10, (countDigits - countDigits1)));
        countSherit = countDigits;
    }
    if(countDigits1 > countDigits)
    {
        countmax = pow(10, countDigits1);
        TempFracAdd = TempFracAdd * (pow(10,(countDigits1 - countDigits)));
        countSherit = countDigits1;
    }
    if(countDigits == countDigits1)
    {
        countmax = pow(10, countDigits1);
        countSherit = countDigits;
    }
    
    fracAdd = TempFracAdd + TempfracBase;

    if (fracAdd > countmax)
    {
        modolo = fracAdd % countmax;
        numAdd++;
        fracAdd = modolo;
    }
    tempNumAdd = numAdd;
    while (numAdd != 0)
    {
        numAdd = numAdd / 10;
        countShalem++;
    }
    base->num = (char*)malloc((countShalem + 1) * sizeof(char));
    if (base->num == NULL)
    {
        return;
    }
    base->frac = (char*)malloc((countSherit + 1) * sizeof(char));
    if (base->frac == NULL)
    {
        return;
    }

    for (char* p = base->num + countShalem - 1; p >= base->num; p--)
        {
            *p = (char)(tempNumAdd % 10+48);
            tempNumAdd = tempNumAdd / 10;
        }
        base->num[countShalem] = 0;

        for (char* p = base->frac + countSherit - 1; p >= base->frac; p--)
        {
            *p = (char)(fracAdd % 10+48);
            fracAdd = fracAdd / 10;
        }
        base->frac[countSherit] = 0;
}
