#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 510
#define DEFAULT_INPUT stdin
#define NO_ARGS_GIVEN argc == 1
#define NO_FILE_GIVEN argc == 2
#define STRING argv[1]

void fgrep(const char *str, FILE *file, const char *filename);
