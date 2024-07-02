/*
 * given a machine with word size of 16 bits and bits numbered right to left
 * (something endian? big? little? i forget), what is the size of the following
 *
 * i remember. it is little endian. the least significant bit is on the right.
 * the user can check endianness on ubuntu 22.04 with the command:
 *
 * $ lscpu | grep Endian
 *
 * the output will be either "Endian: Little" or "Endian: Big"
 *
 * Here's our yucky little-endian machine:
 *
 * Single operand (sgl_op) bits and field names:
 *
 * | Bits | Field Name | Description |
 * | ---- | ---------- | ----------- |
 * | 0-2  | dst_reg    | store result of op here |
 * | 3-5  | dst_mode   | calc to use on addr |
 * |6-15  | opcode     | operation code |
 *
 *
 * Double operand (dbl_op) bits and field names:
 *
 * | Bits | Field Name | Description |
 * | ---- | ---------- | ----------- |
 * | 0-2  | dst_reg    | destination register |
 * | 3-5  | dst_mode   | destination addressing mode |
 * | 6-8  | src_reg    | source register |
 * | 9-11 | src_mode   | source addressing mode |
 * | 12-15| opcode     | operation code |
 *
 *
 * Branch (branch) bits and field names:
 *
 * | Bits | Field Name | Description |
 * | ---- | ---------- | ----------- |
 * | 0-7  | offset     | offset from current program counter \
 * \\\\\\\\\\\\\\\\\\\\\ determines where to jump in code    |
 * | 8-15 | opcode     | operation code |
 *
 * Register source (reg_src) bits and field names:
 *
 * | Bits | Field Name | Description |
 * | ---- | ---------- | ----------- |
 * | 0-2  | dst_reg    | destination register |
 * | 3-5  | dst_mode   | destination addressing mode |
 * | 6-8  | src_reg    | source register |
 * | 9-15 | opcode     | operation code |
 *
 * Miscellaneous (misc) bits and field names:
 *
 * | Bits | Field Name | Description |
 * | ---- | ---------- | ----------- |
 * | 0-15 | opcode     | operation code |
 *
 * Write a declaration that will allow a program to interpret an instruction in
 * any of these formats. your destination must also have an unsigned short field
 * called `addr` that accesses all 16 bits. Use a typedef in your declaration to
 * create a new type called machine_inst.
 *
 * Given the declaration:
 *
 *  machine_inst x;
 *
 * the expressions below should access the indicated bits:
 *
 * | Expression | Bits |
 * | ---------- | ---- |
 * | x.addr     | 0-15 |
 * | x.misc.opcode | 0-15 |
 * | x.branch.opcode| 8-15 |
 * | x.sgl_op.dst_mode | 3-5 |
 * | x.reg_src.src_reg | 6-8 |
 * |x.dbl_op.opcode | 12-15 |
 */

#include "../10.3.h"

int main(void)
{
    machine_inst u;
    machine_inst *u_ptr = &u;
    printf("u_ptr->addr: %d\n", u_ptr->mem_addr = 0xBABE);
    printf("u_ptr->misc.opcode: %d\n", u_ptr->bit_field.misc.opcode = 0xFFFF);

    printf("u_ptr->addr: %d\n", u_ptr->mem_addr);
    printf("u_ptr->branch.opcode: %d\n", u_ptr->bit_field.branch.opcode = 0xFF);
    printf("u_ptr->addr: %d\n", u_ptr->mem_addr);
    printf("u_ptr->sgl_op.dst_mode: %d\n", u_ptr->bit_field.sgl_op.dst_mode = 7);
    printf("u_ptr->addr: %d\n", u_ptr->mem_addr);
    printf("u_ptr->reg_src.src_reg: %d\n", u_ptr->bit_field.reg_src.src_reg = 7);
    printf("u_ptr->addr: %d\n", u_ptr->mem_addr);
    printf("u_ptr->dbl_op.opcode: %d\n", u_ptr->bit_field.dbl_op.opcode = 15);
    printf("u_ptr->addr: %d\n", u_ptr->mem_addr);

    return 0;
}
