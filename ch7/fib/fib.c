/*

Write a fibonacci program using recursive calls. Then, add a global int that
counts the number of calls to fib(n)*/

#include <stdio.h>

int count;

int fib(int n);

int fib(int n)
{
    count++;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        count = 0;
        printf("fib(%d) = %d\n", nums[i], fib(nums[i]));
        printf("Number of calls: %d\n", count);
    }
}
