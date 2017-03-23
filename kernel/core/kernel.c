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
	
	kprintf("Peany's Kernel\n");
	kprintf("Version: %d.%d.%d\n",
		KERNEL_VER_MAJOR,
		KERNEL_VER_MINOR,
		KERNEL_VER_PATCH
	);
}
