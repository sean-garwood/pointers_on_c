/*
 * tell time like a little kid
 * 'big hand on the 12, little hand on the 3'
 */

#include "../headers.h"

int main(void)
{
    // get the current time
    time_t now = time(NULL);

    // convert time to local time
    struct tm *local = localtime(&now);

    // get the hour and minute
    unsigned int hour = HOURHAND(local->tm_hour);
    unsigned int minute = MINUTEHAND(local->tm_min);

    printf("big hand on the %d, little hand on the %d\n", hour, minute);
    if ((hour % 4 == 4) && (minute == 4))
        printf("special time!\n");
    return 0;
}
