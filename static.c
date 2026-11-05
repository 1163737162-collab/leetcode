#include <stdio.h>
extern int get_days(int year, int month);
int main ()
{
    int days = get_days(2024, 2);
    printf("2024年2月有%d天\n", days);
    return 0;
}