#include "boot.h"

static void enable_a20_fast(void)
{
	u8 port_a;
	
	port_a = inb(0x92);
	port_a |= 0x02;
	port_a &= ~0x01;
	outb(port_a, 0x92);
}

void enable_a20(void)
{
	/* TODO: Check to see if A20 Line is enabled first. */
	enable_a20_fast();
}
