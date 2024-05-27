#include <stdio.h>
/* write a del_substr function with prototype*/

int del_substr(char *str, const char *substr);

/* which

    * returns 0 if substr is not found in str
    * if substr is found, write the chars in str appearing after the first
    * appearance of substr over the substr. return 1
    * e.g. if 'abcdef' is substr, str is 'abcdefgh', then str is modified to
    * 'gh' and 1 is returned
    * **DO NOT USE STRING.H***/

int main(void)
{
    char str[] = "abcdefghdef";
    const char substr[] = "def";
    printf("substring: %s\n", substr);
    printf("string: %s\n", str);
    if (del_substr(str, substr))
        printf("After removal:     %s\n", str);
    else
        printf("Substring not found\n");
    return 0;
}

int del_substr(char *str, const char *substr)
{
    char *p = str;
    const char *q = substr;
    while (*p)                  // while not end of string
    {
        if (*p == *q)        // if characters match
        {
            char *temp = p; //initialize a temp pointer that points to the current position of p
            while (*q && *p == *q)  // while not end of substring and characters match
            {
                p++;
                q++;
            }   // increment both pointers
            if (!*q) //if end of substring is reached
            {
                while (*p) //copy the rest of the string to the position of the first character of the substring
                {
                    *temp = *p;
                    temp++;
                    p++;
                }
                *temp = '\0';
                return 1;
            }
            q = substr;
            p = temp + 1;
        }
        else
            p++;
    }
    return 0;
}
