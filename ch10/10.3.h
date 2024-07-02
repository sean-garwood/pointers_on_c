#include "10.h"

// only one instruction can be received at a time, so we can use a union to
// delineate the five types of instructions, which are as follows:
/*
single operand (sgl_op)
double operand (dbl_op)
branch
register source (reg_src)
miscellaneous (misc)
*/
/* the dst_reg and dst_mode fields are common to more than one instruction

the src_reg field is in bits 6-8 for the double operand instruction as well
as the register source instruction

the opcode always comes last as well.

the goal is to pare down this struct to the bare minimum, so we can use a
union and enum the instruction types to get the proper bit fields
 */

typedef struct machine_inst
{
    union
    {
        struct
        {
            unsigned short dst_reg : 3;
            unsigned short dst_mode : 3;
            unsigned short opcode : 10;
        } sgl_op;
        struct
        {
            unsigned short dst_reg : 3;
            unsigned short dst_mode : 3;
            unsigned short src_reg : 3;
            unsigned short src_mode : 3;
            unsigned short opcode : 4;
        } dbl_op;
        struct
        {
            unsigned short offset : 8;
            unsigned short opcode : 8;
        } branch;
        struct
        {
            unsigned short dst_reg : 3;
            unsigned short dst_mode : 3;
            unsigned short src_reg : 3;
            unsigned short opcode : 7;
        } reg_src;
        struct
        {
            unsigned short opcode : 16;
        } misc;
    } bit_field;
    unsigned short mem_addr : 16;
} machine_inst;
