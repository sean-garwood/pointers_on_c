/* write a fn called max_list that returns the largest
of an arbitrary number of integer args, which are terminated by an arg <0.*/

#include <stdio.h>
#include <stdarg.h>

int max_list(int first, ...);

int main(int argc, char *argv[])
{
    printf("max_list(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1) = %d\n", max_list(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1));
    return 0;
}

int max_list(int first, ...)
{
    int max = first;
    va_list args;
    va_start(args, first);
    for (int arg = va_arg(args, int); arg >= 0; arg = va_arg(args, int))
    {
        if (arg > max)
        {
            max = arg;
        }
    }
    va_end(args);
    return max;
}
