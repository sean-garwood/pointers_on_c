/* print prime number in range 1-100 */

#include <stdio.h>

int is_prime(int n);

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

int is_prime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
