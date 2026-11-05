#include "calendar.h"
int get_days(int year, int month)
{
    int arr[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = arr[month];
    if (month == 2 && is_leap_year(year))
    {
        days++;
    }
    return days;
}
int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}