#include <stdio.h>
#include <string.h>

char **do_args(int argc, char **argv, char *control,
               void (*do_arg)(int ch, char *value),
               void (*illegal_arg)(int ch));
void do_arg(int ch, char *value);
void illegal_arg(int ch);
