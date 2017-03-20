#include "ioasm.h"

// output stuff
void outb(uint32_t addr, uint8_t val)
{
	asmv("outb %0, %1" : : "a" (val), "Nd" (addr));
}

void outw(uint32_t addr, uint16_t val)
{
	asmv("outw %0, %1" : : "a" (val), "Nd" (addr));
}

void outl(uint32_t addr, uint32_t val)
{
	asmv("outl %0, %1" : : "a" (val), "Nd" (addr));
}

// input stuff
uint8_t inb(uint32_t addr
{
	uint8_t r;
	asmv("inb %1, %0" : "=a" (r) : "Nd" (addr));
	return r;
}

uint16_t inw(uint32_t addr)
{
	int8_t r;
	asmv("inw %1, %0" : "=a" (r) : "Nd" (addr));
	return r;


uint32_t inl(uint32_t addr)
{
	uint8_t r;
	asmv("inl %1, %0" : "=a" (r) : "Nd" (addr));
	return r;
}
