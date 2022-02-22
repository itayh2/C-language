////
////  GuyCode.c
////  Task11
////
////  Created by איתי חסיד on 8 Shevat 5781.
////
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct real
//{
//    char* num;
//    char* frac;
//}real;
//
//static real ERORREAL = { NULL,NULL };
//
//real buildStruck(int rationalnum, int frac);
//char* struct2array(real getreal);
//void realAddAsString(real* numToAdd, real* base);
//int countdigit(int num);
//void convertint2char(char* dest, int size, int num);
//void setNumArryForSum(char* str, int lenaddtonum, int lenbasenum);
//void setFracArryForSum(char* str, int lenaddtofrac, int lenbasefrac);
//int addreals(int needadd,char* num, char* frac);
//
//int main()
//{
//    int rationalnum;
//    int erationalnum;
//    printf("Enter the num\n");
//    scanf("%d", &rationalnum);
//    printf("Enter the frac\n");
//    scanf("%d", &erationalnum);
//    real realfirst = buildStruck(rationalnum, erationalnum);
//    if (!realfirst.num)
//    {
//        return 0;
//    }
//    if (!realfirst.frac)
//    {
//        return 0;
//    }
//    printf("The first number is %s.%s\n", realfirst.num, realfirst.frac);
//
//    char* realasstring = struct2array(realfirst);      // the function convert real to string(but write is as a number "xxx.xxx"
//    if (!realasstring)
//    {
//        return 0;
//    }
//    printf("the number is %s\n", realasstring);
//           
//    printf("Enter the num\n");
//    scanf("%d", &rationalnum);
//    printf("Enter the frac\n");
//    scanf("%d", &erationalnum);
//    real base = buildStruck(rationalnum, erationalnum);
//    if (!base.num)
//    {
//        return 0;
//    }
//    if (!base.frac)
//    {
//        return 0;
//    }
//    printf("The first number is %s.%s\n", base.num, base.frac);
//
//    realAddAsString(&base, &realfirst);
//    printf("the sum of the numbers is %s . %s", realfirst.num, realfirst.frac);
//    free(realfirst.num);
//    free(realfirst.frac);
//    free(realasstring);
//    free(base.num);
//    free(base.frac);
//}
//
//real buildStruck(int num, int frac)
//{
//    real rep;
//    int countdigitsofnum = countdigit(num);
//    int countdigitsoffrac = countdigit(frac);
//    rep.num = (char*)malloc((countdigitsofnum + 1) * sizeof(char));
//
//    if (!rep.num)
//    {
//        rep.num = NULL;
//        return ERORREAL;
//    }
//    rep.frac = (char*)malloc((countdigitsoffrac + 1) * sizeof(char));
//
//    if (!rep.frac)
//    {
//        free(rep.num);
//        rep.frac = NULL;
//        return rep;
//    }
//
//    convertint2char(rep.num, countdigitsofnum, num);
//    convertint2char(rep.frac, countdigitsoffrac, frac);
//    return rep;
//}
//
//int countdigit(int num)
//{
//    int countdigits = 0;
//    if (num == 0)
//    {
//        return 1;
//    }
//    while (num != 0)
//    {
//        countdigits++;
//        num = num / 10;
//    }
//    return countdigits;
//}
//
//void convertint2char(char* dest, int size, int num)
//{
//    for (int i = size - 1; i >= 0; i--)
//    {
//        *(dest + i) = num % 10 + '0';
//        num /= 10;
//    }
//    *(dest + size) = 0;
//}
//
//char* struct2array(real getreal)
//{
//    size_t len = 2 + strlen(getreal.num) + strlen(getreal.frac);
//    printf("len size is %ld", len);
//    size_t nlen = strlen(getreal.num);
//    printf("nlen size is %d", nlen);
//    char* arr = (char*)malloc(len * sizeof(char));
//
//    if (!arr)
//    {
//        arr = NULL;
//        return arr;
//    }
//    strcpy(arr, getreal.num);
//
//    printf("arr is %s", arr);
//    arr[nlen] = '.';
//    arr[nlen + 1] = 0;
//    strcat(arr, getreal.frac);
//    return arr;
//}
//
//void realAddAsString(real* numToAdd, real* base)
//{
//    int lenaddtonum = strlen(numToAdd->num);
//    int lenaddtofrac = strlen(numToAdd->frac);
//    int lenbasenum = strlen(base->num);
//    int lenbasefrac = strlen(base->frac);
//
//    if (lenbasenum < lenaddtonum)
//    {
//        setNumArryForSum(base->num, lenaddtonum, lenbasenum);
//        lenbasenum = lenaddtonum;
//    }
//    if (lenbasenum > lenaddtonum)
//    {
//        setNumArryForSum(numToAdd->num, lenbasenum, lenaddtonum);
//        lenaddtonum = lenbasenum;
//    }
//    if (lenbasefrac < lenaddtofrac)
//    {
//        setFracArryForSum(base->frac, lenaddtofrac, lenbasefrac);
//        lenbasefrac = lenaddtofrac;
//    }
//    if (lenbasefrac > lenaddtofrac)
//    {
//        setFracArryForSum(numToAdd->frac, lenbasefrac, lenaddtofrac);
//        lenaddtofrac = lenbasefrac;
//    }
//
//    int needadd = 0;
//
//    if (numToAdd->frac[lenbasefrac] - '0' + base->frac[lenbasefrac] - '0' + needadd >= 10)
//        needadd = 1;
//    needadd = addreals(needadd, lenaddtofrac, numToAdd->frac, base->frac);
//    needadd = addreals(needadd, lenbasenum, numToAdd->num, base->num);
//
//    if (needadd == 1)
//    {
//        base->num = (char*)realloc(base->num, (lenbasenum + 2) * sizeof(char));
//        if (!base->num)
//            return;
//        base->num[lenbasenum + 1] = 0;
//        int counter = 0;
//        for (int i = lenaddtonum; i >= 1; i--)
//        {
//            base->num[i] = base->num[lenbasenum - 1 - counter];
//            counter++;
//        }
//        base->num[0] = '1';
//    }
//}
//
//void setNumArryForSum(char* str, int lenaddtonum, int lenbasenum)
//{
//    str = (char*)realloc(str, (lenaddtonum+1)*sizeof(char));
//    int count = 0;
//    for (int i = lenbasenum-1; i >= 0 ; i--)
//    {
//        *(str + lenaddtonum - 1 - count) = *(str + i);
//        count++;
//    }
//    for (int i = lenaddtonum - lenbasenum - 1; i >= 0; i--)
//    {
//        str[i] = '0';
//    }
//    *(str+lenaddtonum) = 0;
//}
//
//void setFracArryForSum(char* str, int lenaddtofrac, int lenbasefrac)
//{
//    str = (char*)realloc(str, ((lenaddtofrac + 1) * sizeof(char)));
//
//    for (int i = lenbasefrac ; i <= lenaddtofrac - 1; i++)
//    {
//        *(str+i) = '0';
//    }
//    *(str+lenaddtofrac) = 0;
//}
//
//int addreals(int need2add,int len, char* firstnum, char* secondenum)
//{
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (*(firstnum+i) - '0' + *(secondenum+i) - '0' + need2add >= 10)
//        {
//            *(secondenum + i) = *(firstnum+i) - '0' + *(secondenum + i) - 10 + need2add;
//            need2add = 1;
//        }
//        else
//        {
//            *(secondenum + i) = *(firstnum+i) - '0' + *(secondenum + i) + need2add;
//            need2add = 0;
//        }
//    }
//    return need2add;
//}
