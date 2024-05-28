#include <stdio.h>
#include <string.h>
#define K 1000
#define HUNDRED "hundred"
/*
assignment: write a function with the following prototype:
 */
void write_out(unsigned int n, char *buffer);
unsigned int get_power(unsigned int n);

/*
 * it **must** have this prototype.
 * Converts the value in amount to words and stores the result in the
 * buffer
 *   - e.g., if value is 16312, store 'sixteen thousand three hundred twelve' in
 *     the buffer
 *   - dont worry about size, caller's responsibility to check that
 */

// define some arrays to point buffer to
char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *powers[] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion"};

int main(void)
{
    unsigned int n = 192019;
    char buffer[100];
    write_out(n, buffer);
    printf("%s\n", buffer);
    return 0;
}

const unsigned int get_power(unsigned int n)
{
    int power = 0;
    while (n >= K)
    {
        n /= K;
        power++;
    }
    return power;
}

void write_out(unsigned int n, char *buffer)
{
    /*
     * there are four different array indices to keep track of:
     *
     *   1. ones
     *   2. tens
     *   3. teens
     *   4. powers
     *
     * we need to get n down to 1000 or less, so we can just use
     * the powers array to keep track of the current power of 1000.
     *
     * so if num is in the billions, start with breaking down n to see how many
     * hundreds of billions there are, then how many tens of billions, then how
     * many billions, then how many hundreds of millions, etc.
     *
     * we can use the modulus operator to get the least significant digits, and
     * integer division to get the most significant digits.
     */
    // store the word corresponding to n to buffer
    if (n >= K)
    {
        const unsigned int power = get_power(n);
        write_out(n % K, buffer); // write out the preceding value between 1 and 999
        sprintf(buffer + strlen(buffer), " %s", powers[power]);
        n %= K;
    }
    if (n >= 100)
    {
        write_out(n / 100, buffer); // write out the preceding value between 1 and 9
        sprintf(buffer + strlen(buffer), " %s", HUNDRED);
        n %= 100;
    }
    if (n >= 20)
    {
        sprintf(buffer + strlen(buffer), " %s", tens[n / 10]);
        n %= 10;
    }
    if (n >= 10)
    {
        sprintf(buffer + strlen(buffer), " %s", teens[n - 10]);
    }
    else if (n > 0)
    {
        sprintf(buffer + strlen(buffer), "%s", ones[n]);
    }
    else if (n == 0)
    {
        sprintf(buffer + strlen(buffer), "zero");
    }
    else
    {
        sprintf(buffer + strlen(buffer), "error");
    }
}
