/*
 * write a program that copies stdin to stdout one char at a time
 */

#include <stdio.h>

int main(void)
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(c);
    return 0;
}
