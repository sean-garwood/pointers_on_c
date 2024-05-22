#include <stdio.h>
// this fn should remove excess whitespace form a string of chars:
void deblank(char *string);

int main(void)
{
    char string[] = "  this   is  a  test  ";
    printf("original: %s\n", string);
    deblank(string);
    printf("deblanked: %s\n", string);
    return 0;
}

void deblank(char *string)
{
    int i, j;
    for (i = 0, j = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ' || (i > 0 && string[i - 1] != ' '))
        {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}
