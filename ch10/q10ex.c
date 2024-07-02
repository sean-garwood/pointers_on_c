#include <stdio.h>
int main(void)
{
    union
    {
        int a;
        float b;
        char c;
    } x;

    // ...
    x.a = 25;
    x.b = 3.14;
    x.c = 'x';
    printf("%d %g %c\n", x.a, x.b, x.c);
    printf("size of char pointer: %d\n", (int)sizeof(char *));
    printf("size of int: %d\n", (int)sizeof(int));
    return 0;
}
