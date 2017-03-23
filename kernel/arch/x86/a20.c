#include "boot.h"

static const int MAX_8042_LOOPS = 100000;
static const int MAX_8042_FF = 32;

static int empty_8042(void)
{
	u8 status = 0;
	int ffs = MAX_8042_FF;
	
	for(int loops = MAX_8042_LOOPS; loops > 0; loops--) {
		status = inb(0x64);
		if(status == 0xFF) {
			if(!--ffs)
				return -1; /* No Keyboard Controller Present */
		}
		if (status & 1) {
			io_delay();
			(void)inb(0x60);
		}
		else if (!(status & 2))
			return 0;	/* Finished! */
	}
	return -1; /* Timeout */
}

void enable_a20(void)
{

}
