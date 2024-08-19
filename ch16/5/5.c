#ifndef HEADERS_H
#include "../headers.h"
#endif // HEADERS_H
/*
 * write a fn with the following prototype to compute the wind chill:
 */

double wind_chill(double temp, double velocity);

/*
 * `temp` is the temperature in Celsius
 * `velocity` is wind speed in m/s.
 * return value is the wind chill temperature in C.
 *
 * The formula to compute is:
 *
 * W = ((A + B*sqrt(V) + CV)(delta t)) / (A + B * sqrt(X) + CX)
 *
 * For given air temp and velocity, it gives the temp that produces the same
 * cooling effect with a 4mph wind (the wind chill standard).
 *
 * `V` is the wind velocity in meters per second.
 * `delta t` is (33 - t) the difference between neutral skin temp of 33C and the
 * air temp.
 *
 * The constants are:
 *
 * A = 10.45
 * B = 10
 * C = -1
 * and X = 1.78816, which is the wind speed in m/s that corresponds to 4mph.
 */

double wind_chill(double temp, double velocity)
{
    return ((A + B * sqrt(velocity) + C * velocity) * delta_t(temp)) / (A + B * sqrt(X) + C * X);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s temp velocity\n", argv[0]);
        return 1;
    }

    double temp = atof(argv[1]);
    double velocity = atof(argv[2]);

    printf("Wind chill: %.2f\n", wind_chill(temp, velocity));

    return 0;
}
