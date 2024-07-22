#include <stdio.h>
#include <string.h>

#define DEFAULT_FILE stdin
#define F_FLAG "-f"
#define F_FLAG_LEN 2
#define F_FLAG_GIVEN argv[1] && !strncmp(argv[1], F_FLAG, F_FLAG_LEN)

unsigned int checksum(FILE *file);
