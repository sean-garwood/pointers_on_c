/*
 * a busted jump
 * the problem is that the buffer is set in the function that is called
 * the stack pointer is moved to the function that is called
 * here's a fix
 */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer(void);
void set_buffer(void)
{
    if (setjmp(jbuf) != 0) // initialize jbuf to zero first call to setjmp
                           // setjmp initially returns 0
                           // need to check the return value of setjmp
    {
        // this is now the top-level function on the stack
        printf("After longjmp\n");
        exit(0); // to avoid infinite loop
    }
}

int main(void)
{
    int a = 2;
    int b = 2;

    set_buffer(); // set the buffer. This is the first call to setjmp, so it:
                  // returns 0
                  // executes the code below
    printf("%d + %d = %d\n", a, b, a + b);
    longjmp(jbuf, 1); // jump back to setjmp, restore state information
                      // pass second arg (1) to setjmp

    return 0;
}
