#include <stdio.h>
#include <ctype.h>

#define MAXARGS 2
#define DEFAULT_STREAM stdin
#define OUTPUT_FILE "hexdump.txt"
#define INPUT_FILE argv[1]
#define CHUNK 16
