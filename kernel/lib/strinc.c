#include "../include/string.h"

#include <stddef.h>

size_t strlen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return (s - str);
}

char *strcpy(char *dst, const char *src) {
    while (*src != '\0')
    {
        *dst++ = *src++;
    }

    return dst;
}

void *memset(void *ptr, int value, size_t num) {
  char *mptr = (char *)ptr;
  for (size_t i = 0; i < num; i++) {
    mptr[i] = value;
  }

  return ptr;
}