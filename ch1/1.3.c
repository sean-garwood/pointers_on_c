/* reads chars from std input and writes to standard output
computes a checksum of output and prints to newline
the checksum is computed in a `signed char` variable that is initailized to -1.
As each char is read from the stdin, it is added to the checksim. any overflow
from the checksum variable is ignored. when all fo the chars have been written,
the checksum is the written as a decimal integer, which may be negative. then, a
newline follows the checksum*/

#include "1.h"

void compute_checksum(char *line);

int main()
{
    char c[100];
    fgets(c, sizeof(c), stdin);
    compute_checksum(c);
    return 0;
}

void compute_checksum(char *line)
{
    signed char checksum = -1;
    for (int i = 0; line[i] != '\0'; i++)
    {
        checksum += line[i];
    }
    printf("%d\n", checksum);
}
