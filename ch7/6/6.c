#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_POWER 15
int num_digits(int dollars);
int tent_to_the(int power);
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

// calculate the number to divide dollars by when creating chunk
int ten_to_the(int power)
{
    if (!power)
    {
        return 1;
    }
    else
    {
        int p = 1;
        for (int i = 0; i < power; i++)
        {
            p *= 1000;
        }
        return p;
    }
}

void print_num(int dollars, char *buffer)
{
    int power = num_digits(dollars) / 3;
    while (power >= 0)
    {
        // first group of dollars.
        int chunk, o, t, h;
        chunk = power ? dollars / ten_to_the(power) : dollars % 1000;
        o = chunk % 10;         // ones
        t = (chunk / 10) % 10;  // tens
        h = (chunk / 100) % 10; // hundreds

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
        strcat(buffer, powers[power]);

        power--;
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
    }
    else
    {
        dollars = atoi(argv[1]);
    }
    print_num(dollars, buffer);
    printf("%s\n", buffer);
    return 0;
}
