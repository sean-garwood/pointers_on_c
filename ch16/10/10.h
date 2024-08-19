#ifndef _10_H
#define _10_H

#include "../headers.h"

int intcmp(const void *a, const void *b);
void isort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

#endif // _10_H
