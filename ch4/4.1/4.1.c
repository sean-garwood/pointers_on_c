/*this program will read a value and compute and print its square root using the
following approximation method:

a_i+1 = (a_i + (n / a_i)) / 2

the approximation is 'close enough' when a_i = a_i+1
*/
#include <stdio.h>
#define MAX_APPROXES 100

int get_n(void);
void sqrt_approx(int n, float *approxes);

int main(void)
{
    float approx = 1.0;
    float approxes[MAX_APPROXES] = {approx};
    int n = get_n();
    sqrt_approx(n, approxes);
    // print approximations
    for (int i = 1; i < MAX_APPROXES; i++)
    {
        if (approxes[i] == 0)
        {
            break;
        }
        printf("Approximation %d: %f\n", i, approxes[i]);
    }
    return 0;
}

int get_n(void)
{
    // get a char from user
    // return the char as an int
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

void sqrt_approx(int n, float *approxes)
{
    for (int i = 1; i < MAX_APPROXES; i++)
    {
        approxes[i] = (approxes[i - 1] + (n / approxes[i - 1])) / 2.0;
        if (i > 1 && approxes[i] == approxes[i - 1])
        {
            break;
        }
    }
}
