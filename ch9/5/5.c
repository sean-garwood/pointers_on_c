#include "../ch9.h"
// write a function:
void my_strncat(char *dest, char *src, int dest_len);

/*
 * it should:
 * concat the str in src to the end of the str in dest
 * does not overflow dest, which has a len of dest_len
 * always null-terminate dest
 */

int main(void)
{
    char dest[SIZE] = "foo";
    char src[] = "barbazbat";
    int dest_len = strlen(dest);
    // cat src to dest
    my_strncat(dest, src, dest_len);
    // print result
    printf("%s\n", dest);
    return 0;
}

void my_strncat(char *dest, char *src, int dest_len)
{
    for (int i = 0; i < SIZE - dest_len - 1; i++)
        dest[dest_len + i] = src[i];
    dest[SIZE - 1] = '\0';
}
