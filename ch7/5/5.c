/*
implement the barebones version of printf that meets specs:

1. capable of handling %d, %f, %s, and %c format codes
2. behavior for all other format codes is undefined
3. existence of fns `print_int` and `print_float` to print %d and %f is assumed
    3a. uses `putchar` to print everything else
 */

/*

 * pseudocode:

 void my_pf(string, *format_args)
    string is a char array with format placeholders interspersed
        fmt delimited by '%'

    1. iterate through chars in string, collecting all placeholders (fmt[])
    2. iterate through format_args and match to fmt[]
    3. cast the values in corresponding indices to fmt
    4. insert the values in fmt[] into string
    5. return
    5. print to stdout
        a. if %d || %f then use print_ fn
        b. else use putchar
 */
#include <stdio.h>
#include <stdarg.h>
#define FMT 37 // ASCII for `%`

void print_int(int n);
void print_float(double f);
int fs(char *str, ...); // takes a pointer to a char array and some variables

int main(void)
{
    return fs(
               "Hello, %s %s %s number %c%d, version %f!\n",
               "brave", "new", "world", '#', 100, 2.0)
               ? 1
               : 0;
}

void print_int(int n)
{
    printf("%d", n);
}

void print_float(double f)
{
    printf("%f", f);
}

int fs(char *string, ...)
{
    va_list args;
    va_start(args, string);
    for (char *c = string; *c; c++)
    {
        if (*c == FMT)
        {
            switch (*++c)
            {
            case 'd':
                print_int(va_arg(args, int));
                break;
            case 'f':
                print_float(va_arg(args, double));
                break;
            case 's':
                for (char *s = va_arg(args, char *); *s; s++)
                    putchar(*s);
                break;
            case 'c':
                putchar(va_arg(args, int));
                break;
            default:
                return 0;
            }
        }
        else
        {
            putchar(*c);
        }
    }
    va_end(args);
    return 1;
}
