/*
 * the information saved by the telephone company when you make a long-distance
 * call (lol 1999) includes:
 *  * date and time call was placed
 *  * number called from
 *  * number called
 *  * number to be billed
 *
 * each phone number includes
 *  * area code
 *  * exchange
 *  * station
 *
 * write a structure declaration for this billing information.
 */

#include "../10.h"

/*
 * date type is a structure with three members: month, day, year
 * time type is a structure with two members: hour, minute
 * phone number type is a structure with three members: area code, exchange, station
 */

typedef struct
{
    int month;
    int day;
    int year;
} date_t;

typedef struct
{
    int hour;
    int minute;
} time_t;

typedef struct
{
    int area_code;
    int exchange;
    int station;
} phone_number_t;

typedef struct
{
    date_t date;
    time_t time;
    phone_number_t called_from;
    phone_number_t called;
    phone_number_t billed;
} billing_info_t;

int main(void)
{
    date_t call_date = {12, 25, 1999};
    time_t call_time = {11, 59};
    phone_number_t caller = {123, 456, 7890};
    phone_number_t recipient = {987, 654, 3210};
    phone_number_t bill_to = caller;
    billing_info_t call_info;

    call_info.date = call_date;
    call_info.time = call_time;
    call_info.called_from = caller;
    call_info.called = recipient;
    call_info.billed = bill_to;

    printf("Billing information:\n");
    printf("Date: %d/%d/%d\n", call_info.date.month, call_info.date.day, call_info.date.year);
    printf("Time: %d:%d\n", call_info.time.hour, call_info.time.minute);
    printf("Called from: %d-%d-%d\n", call_info.called_from.area_code, call_info.called_from.exchange, call_info.called_from.station);
    printf("Called: %d-%d-%d\n", call_info.called.area_code, call_info.called.exchange, call_info.called.station);
    printf("Recipient: %d-%d-%d\n", call_info.called.area_code, call_info.called.exchange, call_info.called.station);
    printf("Billed: %d-%d-%d\n", call_info.billed.area_code, call_info.billed.exchange, call_info.billed.station);

    return 0;
}
