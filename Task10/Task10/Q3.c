//
//  Q3.c
//  Task10
//
//  Created by איתי חסיד on 17 Tevet 5781.
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define SIZE 4
//char *BiggestLetters(char *strArr[], int size);
//int main()
//{
//    char *arr[] = {"hello","and","good","morning"};
//    char *res = BiggestLetters(arr, SIZE);
//    if (res == NULL)
//    {
//        printf("Memory allocation failed\n");
//    }
//    else
//    {
//    printf("Biggest letters string is %s\n", res);
//    }
//    free(res);
//    res = NULL;
//}
//
//char *BiggestLetters(char *strArr[], int size)
//{
//
//    char *str = (char*)malloc((size + 1) * sizeof(char));
//    if (str == NULL)
//        {
//            return str;
//        }
//    else
//    {
//    char max = 'A';
//    int length;
//    for (int i = 0; i < size; i++)
//    {
//        length = strlen(strArr[i]);
//        for (int j = 0; j < length; j++)
//        {
//            if(*(*(strArr + i) + j) > max)
//            {
//                max = *(*(strArr + i) + j);
//            }
//        }
//        str[i] = max;
//        max = 'A';
//    }
//    }
//    return str;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define SIZE 4
//
//char *biggestLetter(char **strArr, int size);
//
//void main()
//{
//    char *strArr[SIZE] = { "hello","and","good","morniny" }, *newStr;
//
//    newStr = biggestLetter(strArr, SIZE);
//    if (!newStr)
//        printf("Not enough memory");
//
//    else
//        printf("the new stirng is: '%s'", newStr);
//
//}
//
//
//char *biggestLetter(char **strArr, int size)
//{
//    char *sentence = NULL, tav = 'a';
//    int indx;
//
//    sentence = (char *)malloc(size + 1);
//    if (!sentence)
//        return NULL;
//
//    for (indx = 0; indx < size; *strArr++,indx++)
//    {
//        for ( ; *(*strArr); *(*strArr)++)
//
//            tav = (tav < *(*strArr)) ? *(*strArr) : tav;
//
//        sentence[indx] = tav;
//        tav = 'a';
//    }
//
//    sentence[indx] = '\0';
//
//    return sentence;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define TEMPSIZE 100
//char *MaxLetters(char **str, int size)
//{
//char *BigStr;
//int i,j = 0;
//char max = '0';
//BigStr = (char *)malloc(size +1 * sizeof(char *));
//if (!BigStr)
//{
//printf("Out of memory\n");
//}
//for (i = 0; i < size; i++)
//{
//while (*(*(str+i)+j)!='\0')
//{
//if (*(*(str + i) + j) > max)
//{
//max = *(*(str + i) + j);
//}
//j++;
//}
//*(BigStr + i) = max;
//max = '0';
//j = 0;
//}
//*(BigStr + i) = NULL;
//return BigStr;
//}
//void main()
//{
//int wordsnum, i;
//char tempstr[TEMPSIZE];
//char **ptrst;
//char *BIG;
//printf("Please enter how many wors u like to add:\n");
//scanf("%d", &wordsnum);
//ptrst = (char**)malloc(wordsnum * sizeof(char*));
//if (!ptrst)
//{
//printf("Out of memory\n");
//}
//for (i = 0; i < wordsnum; i++)
//{
//printf("Please enter word in the %dnd place:\n", i+1);
//scanf("%s", tempstr);
//*(ptrst +i) = (char *)malloc((strlen(tempstr) + 1) * sizeof(char));
//strcpy(*(ptrst + i), tempstr);
//if (!*(ptrst + i))
//{
//printf("Out of memory\n");
//}
//}
//for (i = 0; i <
