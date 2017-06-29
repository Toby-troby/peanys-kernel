#include "ioasm.h"

// output stuff
void outb(uint32_t addr, uint8_t val)
{
	asmv("outb %%al, %%dx" :: "d" (addr), "a" (val));
}

void outw(uint32_t addr, uint16_t val)
{
	asmv("outw %%ax, %%dx" :: "d" (addr), "a" (val));
}

void outl(uint32_t addr, uint32_t val)
{
	asmv("outl %%eax, %%dx" :: "d" (addr), "a" (val));
}

// input stuff
uint8_t inb(uint32_t addr)
{
	uint8_t r;
	asmv("inb %%dx, %%al" : "=a" (r) : "d" (addr));
	return r;
}

uint16_t inw(uint32_t addr)
{
	int8_t r;
	asmv("inw %%dx, %%ax" : "=a" (r) : "d" (addr));
	return r;
}

uint32_t inl(uint32_t addr)
{
	uint8_t r;
	asmv("inl %%dx, %%eax" : "=a" (r) : "d" (addr));
	return r;
}

