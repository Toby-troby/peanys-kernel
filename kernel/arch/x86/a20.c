#include "boot.h"

#define FAST_A20_GATE 0x92

static void enable_a20_fast(void)
{
	u8 port_a;
	
	port_a = inb(FAST_A20_GATE);
	port_a |= 0x02;
	port_a &= ~0x01;
	outb(port_a, FAST_A20_GATE);
}

void enable_a20(void)
{
	/* TODO: Check to see if A20 Line is enabled first. */
	enable_a20_fast();
}
