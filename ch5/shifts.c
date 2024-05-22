#include <stdio.h>
#define NEXP 100;

int value();

int main(void)
{
    printf("%d\n", value());
    return 0;
}

int value()
{
    int a = 10, b = -25;
    int c = 0, d = 3;
    int e = 20;
    int expression;
    expression = a <<= d > 20 ? b && c++ : d--;
    return expression;
}
