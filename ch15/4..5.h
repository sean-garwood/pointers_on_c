#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

#define MAX_LINE_LEN 82 // leave space for newline and null byte
#define SUCCESS 0
#define FAILURE 1

void get_file_names(char *in, char *out);
int open_files(FILE **input, FILE **output, const char *in, const char *out);
void copy_in_chunks(char *buffer, FILE *in, FILE *out);
void close_io(FILE *input, FILE *output);
