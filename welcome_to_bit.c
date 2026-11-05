#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    char arr1[] = "welcome to bit!!!!!";
    char arr2[] = "###################";
    int left = 0;
    int right =  strlen(arr1) - 1;
    while (left<=right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s", arr2);
        fflush(stdout);
        sleep(1);
        printf("\r");
        left++;
        right--;

    }
    return 0;
}
