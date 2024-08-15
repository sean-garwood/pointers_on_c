#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// testing the strtol function

int main(void) {
    char *str = "12345";
    int num = -5;
    long result;

    result = strtol(str, NULL, num);
    printf("strtol(\"%s\", NULL, -5) = %ld\n", str, result);}
