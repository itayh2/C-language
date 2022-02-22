//
//  Q2.c
//  Task7
//
//  Created by איתי חסיד on 24 Kislev 5781.
//

//#define ROWS 3
//#define COLS 4
//#include <stdio.h>
//int arrCheck(int arr[][COLS], int rows, int cols);
//int main()
//{
//    int arr[ROWS][COLS];
//    printf("Insert %d numbers to the array %dx%d: \n", ROWS * COLS, ROWS, COLS);
//    for (int i = 0; i < ROWS; i++)
//    {
//        for (int j = 0; j < COLS; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    printf("The maximum number in the frame is: %d\n", arrCheck(arr, ROWS, COLS));
//}
//int arrCheck(int arr[][COLS], int rows, int cols)
//{
//    int max = arr[0][0];
//    for (int i = 0; i < cols; i++)
//    {
//        if (arr[0][i] > max)
//        {
//            max = arr[0][i];
//        }
//        if (arr[rows - 1][i] > max)
//        {
//            max = arr[rows - 1][i] = max;
//        }
//    }
//    for (int i = 0; i < rows; i++)
//    {
//        if (arr[i][0] > max)
//        {
//            max = arr[i][0];
//        }
//        if (arr[i][cols - 1] > max)
//        {
//            max = arr[i][cols - 1];
//        }
//    }
//    return max;
//}
