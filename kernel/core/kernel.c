#include <core/os.h>
#include <core/io.h>
#include <core/cmos.h>

static void basic_setup(void)
{
	enable_a20();
	init_cmos();
	terminal_initialize();
}

void kernel_main(void) 
{
	basic_setup();
	kprintf("Booted on %u/%u/%u\n", ktime_s.month, ktime_s.dayofmonth, ktime_s.year);	
	kprintf("Hello, World!\n");
	
	/* Idle CPU */
	while(1) {
		/* TODO: Do CPU idling here */
		asm("hlt");
	}
}
