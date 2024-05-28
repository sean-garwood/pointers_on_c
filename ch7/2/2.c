/* write a function `gcd` that takestow int args and returns the greatest common
divisor of those numbers. if either arg is not greater than zero, gcd returns
0.*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./gcd a b\n");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    return 0;
}

int gcd(int a, int b)
{
    // sort a and b from greatest to least
    if (a <= 0 || b <= 0)
    {
        return 0;
    }
    else
    {
        int m = a > b ? a : b;
        int n = a > b ? b : a;
        int rem = m % n;
        return (rem == 0) ? n : gcd(n, rem);
    }
}
