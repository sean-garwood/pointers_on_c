#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int digits = 0;
    while (dollars > 0)
    {
        buffer[digits++] = dollars % 10;
        dollars /= 10;
    }
    return digits;
}

void print_num(int dollars, char *buffer)
{
    int rev_digits[MAX_POWER]; // store the digits of the number (big endian)
    int digits = reverse(dollars, rev_digits);
    const char **power = powers;
    int index = 0;
    printf("Digits: %d\n", digits);
    while (index < digits)
    {
        int num = rev_digits[index];
        int next_num = index + 1 < digits ? rev_digits[index + 1] : 0;
        switch (index % 3)
        {
        case 0:
            if (next_num == 1)
            {
                strcat(buffer, teens[num]);
                strcat(buffer, " ");
                index += 2;
            }
            else
            {
                strcat(buffer, ones[num]);
                strcat(buffer, " ");
                index++;
            }
            break;
        case 1:
        {

            strcat(buffer, tees[num]);
            strcat(buffer, " ");
            index++;
            break;
        }
        case 2:
            strcat(buffer, hundreds[num]);
            strcat(buffer, " ");
            if (next_num)
                strcat(buffer, *++power);
            index++;
            break;
        }
    }
    // reverse the buffer order if possible?
    char *end = buffer + strlen(buffer) - 1;
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
        print_num(dollars, buffer);
    }
    else
    {
        int dollars = atoi(argv[1]);
        printf("Dollars: %d\n", dollars);
        print_num(dollars, buffer);
    }
    printf("%s\n", buffer);
    return 0;
}
