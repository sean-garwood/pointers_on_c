#include "../ch9.h"
/*
 * write a fn
 */

int palindrome(char *str);

/*
 * it should:
 a) return 1 if str is a palindrome, 0 otherwise
 b) ignore nonalphabetic characters
 c) ignore case
 */

int main(void)
{
    char a_palindrome[] = "Taco \
        Cat ";
    char not_palindrome[] = "Not a \
        palindrome9";
    printf("%s %s a palindrome\n",
           a_palindrome, palindrome(a_palindrome) ? "is" : "is not");
    printf("%s %s a palindrome\n",
           not_palindrome, palindrome(not_palindrome) ? "is" : "is not");
    return 0;
}

int palindrome(char *str)
{
    int left = 0, right = strlen(str) - 1;
    while (left < right)
    {
        // Move left index to either first alpha char or end of string
        while (!isalpha(str[left]) && str[left] != '\0')
            left++;
        // Move right index to the last alphabetic character
        while (!isalpha(str[right]) && right >= 0)
            right--;

        if (left == right)
            break; // If pointers cross, all checks are done

        if (tolower(str[left]) != tolower(str[right]))
            return 0;

        left++;
        right--;
    }
    return 1;
}
