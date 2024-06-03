#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int main(void)
{
    char buffer[SIZE] = {"abc"};

    // ***rewrite to use pointers
    // int front, rear;
    // front = 0;
    // rear = strlen(buffer) - 1;
    // while (front < rear)
    // {
    //     if (buffer[front] != buffer[rear])
    //         break;

    //     front += 1;
    //     rear -= 1;
    // }
    // if (front >= rear)
    //     printf("it's a palindrome!\n");

    char *front_ptr = buffer;
    char *rear_ptr = buffer + sizeof(buffer);

    while (*rear_ptr == '\0')
    {
        rear_ptr--;
    }
    while (rear_ptr > front_ptr)
    {
        if (*rear_ptr != *front_ptr)
        {
            printf("sorry, no pally\n");
            return 0;
        }
        front_ptr++;
        rear_ptr--;
    }
    if (front_ptr >= rear_ptr)
    {
        printf("it's a palindrome!\n");
    }
    return 0;
}
