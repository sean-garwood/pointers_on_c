/*call increment and negate on values 10, 0 and -10. print result.*/

#include "headers.h"

int main()
{
    int tests[] = {10, 0, -10};
    for (int i = 0; i < 3; i++)
    {
        printf("increment(%d) = %d\n", tests[i], increment(tests[i]));
        printf("negate(%d) = %d\n", tests[i], negate(tests[i]));
    }
    return 0;
}
