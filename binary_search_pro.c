#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int left = 0, mid;
    int right = sizeof(arr)/sizeof(arr[0]) - 1;
    while (left<=right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == k)
        {
            printf("找到了就是%d", arr[mid]);
            break;
        }
        else if (arr[mid] > k)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    return 0;
}