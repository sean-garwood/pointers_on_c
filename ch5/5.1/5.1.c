// get chars from sstd input and write them to sstd output as lowercase

#include <stdio.h>
#define EXIT '0'

int main()
{
    char c;
    printf("enter a char. 0 to exit.");
    while ((c = getchar()) != EXIT)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 'a' - 'A';
        }
        putchar(c);
    }
    return 0;
}
