#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    for (int i = 0; i < 255; ++i)
    {
        const char *message = strerror(i);
        if (message)
        {
            printf("Error %d: %s\n", i, message);
        }
    }
    return 0;
}
