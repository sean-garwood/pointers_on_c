#include <stdio.h>

void binary_to_ascii(unsigned int n)
{
    unsigned int q;
    q = n / 10;
    if (q != 0)
        binary_to_ascii(q);
    putchar(n % 10 + '0');
}

int main(void)
{
    unsigned int n;
    printf("Enter a number: ");
    scanf("%u", &n);
    binary_to_ascii(n);
    putchar('\n');
    return 0;
}
