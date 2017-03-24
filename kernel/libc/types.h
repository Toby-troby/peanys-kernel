#ifndef LIBC_TYPES_H
#define LIBC_TYPES_H

#include <stdint.h>

/* asmv: for general inline assembly stuff */
#ifndef asmv
#define asm volatile
#endif

typedef unsigned char 	u8;
typedef unsigned short	u16;
typedef unsigned int 	u32;
typedef unsigned long long	u64;

typedef signed char 	s8;
typedef signed short	s16;
typedef signed int 		s32;
typedef signed long long s64;

#endif /* LIBC_TYPES_H */
