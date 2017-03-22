#include "acpi.h"

void reboot(void)
{
	uint8_t tmp = 0x02;
	
	while(tmp & 0x02)
		tmp = inb(0x64);
	
	outb(0x64, 0xFE); // Pulse the CPU Reset Line, so it resets the system.
	asmv("hlt"); // halt CPU if fail
}
