#include <stdio.h>
void print_arr(int arr[3][5], int rows, int cols);
int main()
{
    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    print_arr(arr, 3,5);
    return 0;
}
void print_arr(int arr[3][5], int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
