#include "string.h"

size_t strlen(const char* str)
{
	size_t str_length = 0;
	while(str[str_length])
		str_length++;
	return str_length;
}
