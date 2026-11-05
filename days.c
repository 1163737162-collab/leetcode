#include <stdio.h>
int get_days(int year, int month);
int is_leap_year(int year);
int main()
{
    int year = 0;
    int month = 0;
    scanf("%d %d", &year, &month);
        int days = get_days(year, month);
        printf("%d年%d月有%d天\n", year, month, days);
    return 0;
}
int get_days(int year, int month)
{
    int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      int days = arr[month];
    if (is_leap_year(year) && month == 2)
        days = 29;
    return days;
}
int is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}