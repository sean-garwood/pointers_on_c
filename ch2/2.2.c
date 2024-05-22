/* write a program that reads C source code from stdin
and ensure that the braces are paired correctly. One need not worry about braces
between comments, string liteals, or character constants.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int brace = 0;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '{')
        {
            brace++;
        }
        else if (ch == '}')
        {
            brace--;
        }
    }
    if (brace < 0)
    {
        printf("Extra closing braces\n");
    }
    else if (brace > 0)
    {
        printf("Extra opening braces\n");
    }
    else
    {
        printf("Braces are paired correctly\n");
    }
    return 0;
}
