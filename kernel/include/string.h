#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

size_t strlen(const char *str);
char *strcpy(char *dst, const char *src);

void *memset(void *ptr, int value, size_t num);

#endif
