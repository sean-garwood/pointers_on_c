#include "../ch9.h"
/*
 * write a `strcpy` replacement that returns a pointer to the end of the
 * destination string (the nul byte at the end of the string) rather than the
 * pointer to the beginning of the destination.
 */

char *my_strcpy(char *dest, const char *src);

int main(void)
{
    char dest[SIZE] = "foo";
    const char src[] = "bar";

    printf("original dest: %s\n", dest);
    printf("return value of `my_strcpy` is pointer to null: %s\n", my_strcpy(dest, src));
    printf("whole dest: %s\n", dest);
    return 0;
}

char *my_strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++))
        ;
    return dest - 1;
}
