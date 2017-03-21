#include <core/os.h>
#include <core/io.h>

void kernel_main(void) 
{
	terminal_initialize();
	kprintf("Peany's Kernel\n");
	kprintf("Version: %d.%d.%d\n",
		KERNEL_VER_MAJOR,
		KERNEL_VER_MINOR,
		KERNEL_VER_PATCH
	);
	
	return;
}
