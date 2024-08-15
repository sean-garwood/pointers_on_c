/*
 * attempt at printing military time. 'Needs fixed,' as my people say.
 */

#include <time.h>
#include <stdio.h>  // this wasn't included, for one thing
#include <stdlib.h> // this wasn't included, for another

int main(void)
{
    struct tm *tm_ptr;
    time_t now;

    now = time(NULL);         // pass NULL as the argument to time() to get the
                              // current time
    tm_ptr = localtime(&now); // need to pass a pointer to a time_t object here,
                              // not the obj itself.

    printf("%d:%02d:%02d %d/%02d/%02d\n",
           tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec,
           // add 1900 to the year, and add 1 to the month
           tm_ptr->tm_year + 1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
    // oops, *time* to go, haha.
    return 0;
}
