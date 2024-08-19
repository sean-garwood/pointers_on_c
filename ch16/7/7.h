#ifndef _7_H
#define _7_H

#define MINMOD 2
#define MAXMOD 10
#define NTEST 9 // number of ints to test
#define INITARR {0}
#define N 10000                           // number of trials
#define MODS {2, 3, 4, 5, 6, 7, 8, 9, 10} // mods to test

void generate_10k_numbers();

extern const int divisors[NTEST];
extern int numbers[N];
#endif // _7_H
