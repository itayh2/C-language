//
//  Q1.c
//  Task11
//
//  Created by איתי חסיד on 1 Shevat 5781.
//

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef struct Real
//{
//    char* num;
//    char* frac;
//} Real;
//Real buildStruck(int num, int frac);
//int main()
//{
//    Real newArr;
//    int num, frac;
//    printf("Please insert 2 numbers: \n");
//    fseek(stdin, 0, SEEK_END);
//    scanf("%d %d", &num, &frac);
//    newArr = buildStruck(num, frac);
//    if (newArr.num == NULL || newArr.frac == NULL)
//    {
//        printf("The structure has not been updated\n");
//    }
//    else
//    {
//    printf("The structure has been updated and is: %s.%s\n", newArr.num, newArr.frac);
//    }
//    free(newArr.num);
//    newArr.num = NULL;
//    free(newArr.frac);
//    newArr.frac = NULL;
//}
//Real buildStruck(int num, int frac)
//{
//    Real newArr;
//    int countOfDigitsNum = 0, countOfDigitsFrac = 0, tempNum = num, tempFrac = frac;
//    while (num != 0)
//    {
//        num = num / 10;
//        countOfDigitsNum++;
//    }
//    while (frac != 0)
//    {
//        frac = frac / 10;
//        countOfDigitsFrac++;
//    }
//    newArr.num = (char*)malloc((countOfDigitsNum + 1) * sizeof(char));
//    newArr.frac = (char*)malloc((countOfDigitsFrac + 1) * sizeof(char));
//    
//    if (newArr.num == NULL || newArr.frac == NULL)
//    {
//        return newArr;
//    }
//    else
//    {
//    for (char* p = newArr.num + countOfDigitsNum - 1; p >= newArr.num; p--)
//    {
//        *p = (char)(tempNum % 10+48);
//        tempNum = tempNum / 10;
//    }
//    newArr.num[countOfDigitsNum] = 0;
//    
//    for (char* p = newArr.frac + countOfDigitsFrac - 1; p >= newArr.frac; p--)
//    {
//        *p = (char)(tempFrac % 10+48);
//        tempFrac = tempFrac / 10;
//    }
//    newArr.frac[countOfDigitsFrac] = 0;
//    return newArr;
//    }
//}
