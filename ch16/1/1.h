#ifndef _1_H
#define _1_H

#define MINBASE 10
#define MAXBASE 36
#define MAXBASEAGE 29
#define TWENTYNINE "29"
#define MAXAGE (2 * (MAXBASE) + 9)
#define MINAGE 0

int check_args(int argc, const char **argv);
int find_lowest_base(const char *age);

#endif // _1_H
