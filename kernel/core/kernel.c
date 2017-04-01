#include <core/os.h>
#include <core/io.h>
#include <core/dt/gdt.h>
#include <core/paging.h>
#include <core/cmos.h>

static void basic_setup(void)
{
	terminal_initialize();
	kprintf("Booting..\n\n");
	kprintf("Initializing A20 Address..\n");
	enable_a20();
	kprintf("Initializing GDT..\n");
	gdt_init();
	kprintf("Initializing Paging..\n");
	init_paging();
	kprintf("Initializing CMOS..\n");
	init_cmos();
	kprintf("\nDone!\n\n");
}

void kernel_main(void) 
{
	basic_setup();
	kprintf("== Booted on %u/%u/%u at %u:%u:%u ==\n",
		       	ktime_s.month, ktime_s.dayofmonth, ktime_s.year,
			ktime_s.hours, ktime_s.minutes, ktime_s.seconds);	
	kprintf("Hello, World!\n");
	
	/* Idle CPU */
	while(1) {
		/* TODO: Do CPU idling here */
		asm("hlt");
	}
}
