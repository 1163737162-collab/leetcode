#include <stdio.h>
int main()
{
    int num;
    int res = 0;
    scanf("%i",&num);
    while(num != 0)
    {
        if ( num %2==0)
        {
            num /=2;
            res++;
        }
        else
        {
            num -=1;
            res++;
        }
        
    }
    printf("%i",res);
    return 0;
}