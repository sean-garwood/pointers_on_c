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

/*
 * declare some arrays of constant character pointers to map numbers to words*/
const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"};
const char *tees[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                      "eighty", "ninety"};
const char *hundreds[] = {"", "one hundred", "two hundred", "three hundred", "four hundred",
                          "five hundred", "six hundred", "seven hundred", "eight hundred",
                          "nine hundred"};
const char *powers[] = {"", "thousand", "million", "billion", "trillion"};

/*
 * write the digits to an int array in reverse order. return the number of
 * digits */
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
    int rev_digits[MAX_POWER]; // store the digits of the number in reverse order
    int digits = reverse(dollars, rev_digits);
    // now the buffer is distributed into three-digit chunks
    int power = 0;
    for (int i = 0; i <= digits; i += 3)
    {
        int chunk = rev_digits[i] + 10 * rev_digits[i + 1] + 100 * rev_digits[i + 2];
        if (chunk > 0)
        {
            if (buffer)
            {
                strcat(buffer, hundreds[rev_digits[i + 2]]);
                if (rev_digits[i + 1] == 1)
                {
                    strcat(buffer, teens[rev_digits[i]]);
                }
                else
                {
                    strcat(buffer, tees[rev_digits[i + 1]]);
                    strcat(buffer, ones[rev_digits[i]]);
                }
                strcat(buffer, powers[power]);
            }
            else
            {
                printf("%s %s %s %s\n", hundreds[rev_digits[i + 2]], rev_digits[i + 1] == 1 ? teens[rev_digits[i]] : tees[rev_digits[i + 1]], ones[rev_digits[i]], powers[power]);
            }
        }
        power++;
    }
}

int main(int argc, char *argv[])
{
    char buffer[MAX_POWER];
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
