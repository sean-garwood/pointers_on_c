/*
 * write a program that reads from stdin and computes pct of chars it finds in
 * each of the following categories:
 *     control chars
 *     whitespace chars
 *    digit chars
 *  lower case chars
 * upper case chars
 * punctuation chars
 * non-printable chars
 *
 * Use the char categories that are deined for the ctype.h library.
 */

#include "../ch9.h"

int main(void)
{
    int c;
    int control = 0;
    int whitespace = 0;
    int digit = 0;
    int lower = 0;
    int upper = 0;
    int punct = 0;
    int non_print = 0;
    int total = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        c = input[0];
        {
            if (iscntrl(c))
                control++;
            else if (isspace(c))
                whitespace++;
            else if (isdigit(c))
                digit++;
            else if (islower(c))
                lower++;
            else if (isupper(c))
                upper++;
            else if (ispunct(c))
                punct++;
            else if (!isprint(c))
                non_print++;
            total++;
        }
    }

    printf("Control: %.2f%%\n", (double)control / total * 100);
    printf("Whitespace: %.2f%%\n", (double)whitespace / total * 100);
    printf("Digit: %.2f%%\n", (double)digit / total * 100);
    printf("Lower: %.2f%%\n", (double)lower / total * 100);
    printf("Upper: %.2f%%\n", (double)upper / total * 100);
    printf("Punctuation: %.2f%%\n", (double)punct / total * 100);
    printf("Non-printable: %.2f%%\n", (double)non_print / total * 100);

    return 0;
}
