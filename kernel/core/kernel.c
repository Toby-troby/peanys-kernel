#include <core/os.h>
#include <core/io.h>

static void basic_setup(void)
{
	enable_a20();
	terminal_initialize();
}

void kernel_main(void) 
{
	basic_setup();
	
	kprintf("Hello, World!\n");
	
	/* Idle CPU */
	while(1) {
		asmv("nop");
	}
}
