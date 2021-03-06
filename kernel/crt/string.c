#include "string.h"

size_t strlen(const char* str)
{
	size_t str_length = 0;
	while(str[str_length])
		str_length++;
	return str_length;
}

void memset(void* s, int c, size_t n)
{
	size_t i;
	unsigned char* dst = (unsigned char*) s;
	
	for(i = 0; i < n; i++)
		dst[i] = c;
}

void memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)dest;
	char *csrc  = (char *)src;

	unsigned int i;
	for(i = 0; i < n; i++)
		cdest[i] = csrc[i];
}
