#include "ioasm.h"

// output stuff
void outb(uint32_t addr, uint8_t val)
{
	asmv("outb %%al, %%ds" :: "d" (addr), "a" (val));
}

void outw(uint32_t addr, uint16_t val)
{
	asmv("outw %%al, %%ds" :: "d" (addr), "a" (val));
}

void outl(uint32_t addr, uint32_t val)
{
	asmv("outl %%al, %%ds" :: "d" (addr), "a" (val));
}

// input stuff
uint8_t inb(uint32_t addr)
{
	uint8_t r;
	asmv("inb %%ds, %%al" : "=a" (r) : "d" (ad));
	return r;
}

uint16_t inw(uint32_t addr)
{
	int8_t r;
	asmv("inb %%ds, %%al" : "=a" (r) : "d" (ad));
	return r;
}

uint32_t inl(uint32_t addr)
{
	uint8_t r;
	asmv("inb %%ds, %%al" : "=a" (r) : "d" (ad));
	return r;
}
