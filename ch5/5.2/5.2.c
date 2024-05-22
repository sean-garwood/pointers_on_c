/*caesar cipher
mask input from stdin by shifting 13 positions, maintaining capitalization*/

#include <stdio.h>
#define EXIT '0'
#define SHIFT 13

int main()
{
    char c;
    printf("enter a char. 0 to exit.");
    while ((c = getchar()) != EXIT)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + SHIFT) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + SHIFT) % 26 + 'a';
        }
        else
            (c = (c - ' ' + SHIFT) % 95 + ' ');
        putchar(c);
    }
    return 0;
}
