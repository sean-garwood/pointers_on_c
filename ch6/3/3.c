#include <stdio.h>
void reverse_str(char *str)
{
    /*reverse a string without:
    1. using indices
    2. copying a local/temp array
    3. using string.h*/

    // savepoint. will ref to terminate reverse printing
    char *end = str;
    while (*end != '\0')
    {
        ++end;
    }
    // end is now pointing to the last char in the char array
    // move back one step to point to the last char
    --end;
    // loop until the start of the string, printing each character to stdout
    while (end >= str)
    {
        end == str ? printf("%c\n", *end) : printf("%c", *end);
        end--;
    }
}

int main(void)
{
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    // point to string
    reverse_str(str);
    return 0;
}
