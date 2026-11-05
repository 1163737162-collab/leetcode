#include <stdio.h>
int main()
{
    int num, digits;
    int res = 0;
    scanf("%i", &num);
    if (num >= 0 && num <= 9)
        res = num;
    else
    {
        while (num >=10)
        {
            int res = 0;
            while (num>0)
            {
                digits = num % 10;
                num /=10;
                res += digits;
            }
            num = res;
        }
    }
    printf("%i", res);
    return 0;
}