/*
 * Write a program that will determine whether int div by 0 or floating-point
 * div by 0 results in a `SIGFPE` signal. Explain results.
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <setjmp.h>

// signal handler for SIGFPE specifically
// test if int div by 0 or floating-point div by 0 results in a `SIGFPE` signal
void sigfpe_handler(int signum);
void div_by_0_int(void);
void div_by_0_float(void);

jmp_buf env;
void sigfpe_handler(int signum)
{
    // use jmp_buf to jump back to main if signal is caught
    printf("Caught signal %d\n", signum);
    div_by_0_float();
    if (setjmp(env) != 0)
    {
        signal(SIGFPE, sigfpe_handler);
    }
    else
    {
        puts("kill the program");
        exit(1);
    }
}

void div_by_0_int(void)
{
    printf("int div by 0\n");
    int a = 1;
    int b = 0;
    printf("%d / %d = %d\n", a, b, a / b);
}

void div_by_0_float(void)
{
    printf("float div by 0\n");
    float c = 1.0;
    float d = 0.0;
    printf("%f / %f = %f\n", c, d, c / d);
    printf("sig not caught if you're reading this\n");
}

// don't need to explicitly write signal, which is in signal.h
// instead pass it as a parameter to the signal handler
int main(void)
{
    // set up signal handler
    signal(SIGFPE, sigfpe_handler); // install signal handler for SIGFPE

    div_by_0_int();

    div_by_0_float();
    return 0;
}
