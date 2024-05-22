#include <stdio.h>
#define START_POS 31
#define END_POS 0

/* write a fn that will store a given value into specified bit positions of an int.
it should have the prototype*/

int store_bit_field(int original_value, int value_to_store,
                    unsigned starting_bit, unsigned ending_bit);

/* Assume bits in int are numbered from right to left, and that starting bit
position cannot be less than ending bit position.*/

/*
assuming 32-bit int size
case: original_value < 0
    take ones compliment to get ||int|| - 1
        this will flip lsb at END_POS
        add 1 to get abs(int)

convert original_value to char array
    for each bit in char array
        if bit is 1, set corresponding bit in int to 1
        else, set corresponding bit in int to 0

get corresponding bits

get length of value_to_store
    starting bit - ending bit
    if length of value_to_store > starting bit - ending bit
        return -1
    toss out overflow bits

*/
