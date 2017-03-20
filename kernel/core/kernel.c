 #include <core/os.h>

void kernel_main(void) 
{
	terminal_initialize();
	terminal_printf("Hello, World!\n");
}
