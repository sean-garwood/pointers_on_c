#include <stdio.h>
#include <string.h>

// chop off least significant digits and add them to buffer
void build_reversed(unsigned int dollars, char *buffer);
// the length of the number can be derived from this function, as well.

/* the objective is to print the number out in english words.
 *    example: 1234 -> one thousand two hundred thirty four
 *    example: 123456 -> one hundred twenty three thousand four hundred fifty
 *    six
 *    example: 123456789 -> one hundred twenty three million four hundred fifty
 *    six thousand seven hundred eighty nine
 */
void print_num(unsigned int dollars, char *buffer);

void build_reversed(unsigned int dollars, char *buffer)
{
    int i = 0;
    while (dollars > 0)
    {
        buffer[i++] = dollars % 10 + '0';
        dollars /= 10;
    }
    buffer[i] = '\0';
}

void print_num(unsigned int dollars, char *buffer)
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
    int digits, index, power, length, thousands_index;

    build_reversed(dollars, buffer);
    length = strlen(buffer);
    power = (length - 2);
    thousands_index = 0;
}

int main(void)
{

    return 0;
}
