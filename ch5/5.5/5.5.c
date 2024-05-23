/* write a fn that will store a given value into specified bit positions of an int.*/
#include <stdio.h>
#include <stdlib.h>
#define ARGS 5

short get_mask(const __uint16_t starting_bit, const __uint16_t ending_bit);
void zero_bits(short original_value, short mask);
/*it should have the prototype*/
short store_bit_field(short original_value, short value_to_store,
                      const __uint16_t starting_bit, const __uint16_t ending_bit,
                      short mask);
/*  note: adjusted for 1999 status and to fit the examples below.


some example outputs:

    store_bit_field(0x0, 0x1, 4, 4) -> 0x10
    store_bit_field(0xffff, 0x123, 15, 4) -> 0x123f
    store_bit_field(0xffff, 0x123, 13, 9) -> 0xc7ff

some tips:

    1. construct a mask that contains ones in the bit positions that correspond to
    the desired field.

    2. Using one's complement of the mask, clear all of the bits in the field.

    3. Shift the value to store so that it aligns with the field.

    4. AND the shifted value with the mask to ensure that only the desired bits are
    set.

    5. OR the result with the original value to set the desired bits.*/

short get_mask(const __uint16_t starting_bit, const __uint16_t ending_bit)
{
    short mask = 0;

    /* set the bits from starting_bit to ending_bit to 1
    keep the rest zero

    keep in mind that starting_bit is the most significant bit
    Assume bits in int are numbered from right to left, and that starting bit
    position cannot be less than ending bit position.*/

    for (int i = ending_bit; i <= starting_bit; i++)
    {
        mask |= 1 << i;
    }
    return mask;
}

void zero_bits(short original_value, short mask)
{
    original_value &= ~mask;
}

short store_bit_field(short original_value, short value_to_store,
                      const __uint16_t starting_bit, const __uint16_t ending_bit,
                      short mask)
{
    original_value |= (value_to_store << starting_bit) & mask;
    return original_value;
}

int main(int argc, char *argv[])
{
    if (argc != ARGS)
    {
        printf("Usage: %s <original_value> <value_to_store> <starting_bit> <ending_bit>\n", argv[0]);
        return 1;
    }
    short val = atoi(argv[1]);
    short val_to_store = atoi(argv[2]);
    const __uint16_t start_bit = atoi(argv[3]);
    const __uint16_t end_bit = atoi(argv[4]);

    short mask = get_mask(start_bit, end_bit);
    zero_bits(val, mask);

    short result = store_bit_field(val, val_to_store, start_bit, end_bit, mask);
    printf("changing the %hu-%hu bits of %hd to %hd yields %hd\n",
           start_bit, end_bit, val, val_to_store, result);
    return 0;
}
