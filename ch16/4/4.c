/*
 * write a program that takes three int cli args and interprets them as a month,
 * a day and a year. it should then print the day of the week on which th
 * especified date fell (or will fall). for what range of years is it accurate?
 */

#include "../headers.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s month day year\n", argv[0]);
        return 1;
    }

    int month = atoi(argv[1]);
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);

    if (month < 1 || month > 12)
    {
        fprintf(stderr, "Invalid month: %d\n", month);
        return 2;
    }

    if (day < 1 || day > 31)
    {
        fprintf(stderr, "Invalid day: %d\n", day);
        return 3;
    }

    if (year < 1)
    {
        fprintf(stderr, "Invalid year: %d\n", year);
        return 4;
    }

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    local->tm_mon = month - 1;
    local->tm_mday = day;
    local->tm_year = year - 1900;
    time_t then = mktime(local);
    struct tm *then_local = localtime(&then);
    unsigned int day_of_week = then_local->tm_wday;

    printf("The date %d/%d/%d fell on a ", month, day, year);
    switch (day_of_week)
    {
    case 0:
        printf("Sunday\n");
        break;
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    default:
        printf("Invalid day of the week: %d\n", day_of_week);
        break;
    }

    return 0;
}
