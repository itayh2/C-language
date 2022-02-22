//
//  Q2.c
//  Task10
//
//  Created by איתי חסיד on 15 Tevet 5781.
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define SIZE 10
//char* NewStr(char* str1, char* str2, int index);
//int main()
//{
//    char str1[SIZE];
//    char str2[SIZE];
//    char* str3;
//    int index;
//    printf("Please insert 2 word up to %d letters: \n", SIZE - 1);
//    printf("1.");
//    gets(str1);
//    printf("2.");
//    gets(str2);
//    int count1 = strlen(str1), count2 = strlen(str2);
//    printf("Please insert a index: ");
//    scanf("%d", &index);
//    if (index > count1 || index > count2)
//    {
//        printf("Memory allocation failed");
//        return 0;
//    }
//    str3 = NewStr(str1, str2, index);
//    if (str3 == NULL)
//        printf("Memory allocation failed\n");
//    else
//    printf("the new word is : %s\n", str3);
//    free(str3);
//    str3 = NULL;
//
//}
//
//char* NewStr(char* str1, char* str2, int index)
//{
//    int len = index + strlen(str2) - index;
//    str1[index] = 0;
//    char* str3 = (char*)malloc((len +1)* sizeof(char));
//    if (str3 == NULL)
//    {
//        return str3;
//    }
//    else
//    {
//        strcpy(str3,str1);
//        strcat(str3 , str2 + index);
//        return str3;
//    }
//}
