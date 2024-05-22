#include <stdio.h>
#define NEXP 100;

int value();

static int a = 10, b = -25;
static int c = 0, d = 3;
static int e = 20;

int main(void)
{
    printf("%d\n", value());
    return 0;
}

int value()
{
    int expression;
    expression = (a | b << a & b);
    return expression;
}
