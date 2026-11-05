#include <stdio.h>
#include "calendar.h"

int main ()
{
    int days = get_days(2024, 2);
    printf("2024年2月有%d天\n", days);
}