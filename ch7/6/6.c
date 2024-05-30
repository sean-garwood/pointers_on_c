#include <stdio.h>
#include <string.h>
#define MAX_POWER 15
// chop off least significant digits and add them to buffer
int reverse(int dollars, int *rev_digits);
// the length of the number can be derived from this function, as well.

/* the objective is to print the number out in english words.
 *    example: 1234 -> one thousand two hundred thirty four
 *    example: 123456 -> one hundred twenty three thousand four hundred fifty
 *    six
 *    example: 123456789 -> one hundred twenty three million four hundred fifty
 *    six thousand seven hundred eighty nine
 */
int reverse(int dollars, int *buffer);
void print_num(int dollars, char *buffer);

// write the digits to an int array in reverse order. return the number of digits
int reverse(int dollars, int *buffer)
{
    int i = 0;
    while (dollars > 0)
    {
        buffer[i++] = dollars % 10;
        dollars /= 10;
    }
    buffer[i] = -1;
    return i - 1; // to be used in the print_num function
}

void print_num(int dollars, char *buffer)
{
    /*
     * declare some arrays of character pointers to map numbers to words    */

    char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen"};
    char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                    "eighty", "ninety"};
    char *hundreds[] = {"", "one hundred", "two hundred", "three hundred", "four hundred",
                        "five hundred", "six hundred", "seven hundred", "eight hundred",
                        "nine hundred"};
    char *powers[] = {"", "thousand", "million", "billion", "trillion"};
    int index, power, length, thousands_index;
    int rev_digits[MAX_POWER]; // store the digits of the number in reverse order
}

int main(int argc, char *argv[])
{
    // if no args, prompt user for input
    if (argc < 2)
    {
        int dollars;
        printf("Enter a dollar amount: ");
        scanf("%u", &dollars);
        print_num(dollars, NULL);
    }
    else
    {
        int dollars = atoi(argv[1]);
        print_num(dollars, NULL);
    }
    return 0;
}
