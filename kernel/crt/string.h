#ifndef CRT_STRING_H
#define CRT_STRING_H

#include <stddef.h>

size_t strlen(const char* str);
void memset(void* s, int c, size_t n);
void memcpy(void *dest, void *src, size_t n);

int memcmp(const void *ptr1, const void *ptr2, size_t bytes);
void *memmove(void *dest, const void *src, size_t bytes);

#endif /* CRT_STRING_H */

