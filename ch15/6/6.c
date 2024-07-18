/*
 * wrire a fn 1palindrome_int that takes an int as an argument and returns 1 if the int is a palindrome and 0 otherwise
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(int num);

int main(void)
{
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num))
    {
        while (getchar() != '\n')
            ;
    }
    else
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("%d is%s a palindrome\n", num, palindrome(num) ? "" : " not");

    return 0;
}

int palindrome(int num)
{
    char num_str[10];            // ints wont be bigger than 10 digits
    sprintf(num_str, "%d", num); // convert num to string
    if (num_str[0] == '-')       // negative numbers are not palindromes
        return 0;

    int len = (int)strlen(num_str);
    for (int i = 0; i < len; i++) // validate chars are ints
    {
        if (!isdigit(num_str[i]))
        {
            printf("Invalid input\n");
            exit(1);
        }
    }
    for (int i = 0; i < len / 2; i++) // check if palindrome
    {
        if (num_str[i] != num_str[len - i - 1])
            return 0;
    }
    return 1;
}
