/* The Hermite Polynomials are defined as follows:

H_n(x) = 2xH_n - 1x - 2(n-1)H_n -2x

where H_0(x) = 1 and H_1(x) = 2x. Write a recursive function that computes
the value of H_n(x) for a given n and x. Use the function to compute H_n(x) for
a given n and x. It should have this prototype:*/

#include <stdio.h>

int hermite(int n, int x);

int hermite(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2 * x;
    }
    else
    {
        return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
    }
}

int main(void)
{
    int n_range[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int n = 0; n < 10; n++)
    {
        printf("H_%d(x)\n", n_range[n]);
        for (int x = 0; x < 10; x++)
        {
            printf("H_%d(%d) = %d\n", n_range[n], x, hermite(n_range[n], x));
        }
    }
    return 0;
}
