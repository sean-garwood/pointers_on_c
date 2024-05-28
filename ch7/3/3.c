/* write the function for the following prototype*/

#include <stdio.h>
int ascii_to_integer(char *string);

/* str must contain one or more digits, and the fn should convert those digits
to an int and return the result. if any nondigit chars are found, return zero
instead.

hint: for each digit you find, multiply the value you have so far and then
add the value represented by the new digit.*/

int ascii_to_integer(char *string)
{
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] < '0' || string[i] > '9')
        {
            return 0;
        }
        result = result * 10 + (string[i] - '0');
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./ascii_to_integer <string>\n");
        return 1;
    }
    printf("ascii_to_integer(%s) = %d\n", argv[1], ascii_to_integer(argv[1]));
    return 0;
}
