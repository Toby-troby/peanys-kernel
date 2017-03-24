#include "acpi.h"

void reboot(void)
{
	uint8_t tmp = 0x02;
	
	while(tmp & 0x02)
		tmp = inb(0x64);
	
	outb(0x64, 0xFE); /* reboot system. CPU might get triggered */
	asm("hlt"); /* halt CPU if it got really triggered */
}
