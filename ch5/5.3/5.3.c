#include <stdio.h>

/*
get a value from stdin in decimal
store it in an unsigned int
reverse the bits such that the least significant bit becomes the most
significant bit, the second-least significant bit becomes the second-most
significant, etc.
*/
#define UINT_SIZE sizeof(unsigned int) * 8

int get_input();

int main()
{
    unsigned int x;
    unsigned int y = 0;
    int i;
    printf("Enter a positive number: ");
    x = get_input();
    for (i = 0; i < UINT_SIZE; i++)
    {
        y <<= 1;
        // y becomes y shifted left by 1, so if y = 0b1, y <<= 1 makes y = 0b10
        y |= (x & 1); // y = y OR (x & 1)
        // x & 1 is the least significant bit of x
        // so y becomes y OR the least significant bit of x
        // let y = 25d = 0b11001
        // let x = 5d = 0b101
        // this op becomes (11001 | (101 & 1)
        // (11001 | 1) = 11001
        // this is becuase it checks column by column whether each bit in x and
        // y at the same index is 1, if so, it sets the bit in y at that index
        // to 1
        x >>= 1;
        // do this until i = 32, but not when i = 32.
    }
    printf("%u\n", y);
    return 0;
}

int get_input()
{
    int input;
    unsigned int result;
    scanf("%u", &input);
    if (input < 0)
    {
        printf("negative number input. converting to absolute value...\n");
        input *= -1;
    }
    result = input;
    return result;
}
