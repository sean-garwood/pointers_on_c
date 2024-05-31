#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_POWER 15
int reverse(int dollars, int *rev_digits);
void print_num(int dollars, char *buffer);

/* declare some arrays of constant character pointers to map numbers to words*/
const char *ones[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
const char *teens[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ",
                       "eighteen ", "nineteen "};
const char *tees[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ",
                      "eighty ", "ninety "};
const char *hundreds[] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ",
                          "five hundred ", "six hundred ", "seven hundred ", "eight hundred ",
                          "nine hundred "};
const char *powers[] = {"", "thousand ", "million ", "billion ", "trillion "};

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

int num_digits(int dollars)
{
    int digits = 0;
    while (dollars > 0)
    {
        digits++;
        dollars /= 10;
    }
    return digits;
}

// void print_num(int dollars, char *buffer)
// {
//     int rev_digits[MAX_POWER]; // store the digits of the number (big endian)
//     int digits = reverse(dollars, rev_digits);
//     const char **power = powers;

//     for (int index = 0; index < digits; index += 3)
//     {
//         int o = rev_digits[index];
//         int t = index + 1 < digits ? rev_digits[index + 1] : 0;
//         int h = index + 2 < digits ? rev_digits[index + 2] : 0;
//         int is_more = index + 3 < digits;
//         // initialize a pointer to address of digits[index + 2]
//         int chunk[3] = {h, t, o};
//         int chunk_index = index % 3;
//         printf("Chunk: %d %d %d\n", h, t, o);

//         is_more ? strcat(buffer, *++power) : 0;
//         strcat(buffer, hundreds[h]);
//         if (t == 1)
//         {
//             strcat(buffer, teens[o]);
//             continue;
//         }
//         else
//             strcat(buffer, tees[t]);
//         strcat(buffer, ones[o]);
//     }
// }
void print_num(int dollars, char *buffer)
{
    if (dollars == 0)
        return;

    int last_three_digits = dollars % 1000;
    print_num(dollars / 1000, buffer);

    int h = last_three_digits / 100;
    int t = (last_three_digits % 100) / 10;
    int o = last_three_digits % 10;

    strcat(buffer, hundreds[h]);
    if (t == 1)
    {
        strcat(buffer, teens[o]);
    }
    else
    {
        strcat(buffer, tees[t]);
        strcat(buffer, ones[o]);
    }
    if ((dollars / 1000) > 0)
    {
        strcat(buffer, powers[num_digits(dollars) / 3]);
    }
}

int main(int argc, char *argv[])
{
    int dollars;
    char *buffer = malloc(MAX_POWER * MAX_POWER + 1);
    // if no args, prompt user for input
    if (argc < 2)
    {
        printf("Enter a dollar amount: ");
        scanf("%u", &dollars);
        print_num(dollars, buffer);
    }
    else
    {
        dollars = atoi(argv[1]);
        printf("Dollars: %d\n", dollars);
        print_num(dollars, buffer);
    }
    printf("%s\n", buffer);
    return 0;
}
