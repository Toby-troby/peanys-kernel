#include <core/os.h>
#include <core/io.h>
#include <core/dt/gdt.h>
#include <core/mem/paging.h>
#include <core/cmos.h>

static void check_boot(uint32_t mb_magic, void* mb_header)
{
	/* Check if bootloader follows bootloader specification. */
	if(mb_magic != MULTIBOOT_BOOTLOADER_MAGIC)
		panic("Not booted by compliant bootloader!");

	mbi = (struct multiboot_info_t*)mb_header;
	if((mbi->flags & (1<<6)) == 0)
		panic("No memory map was provided by bootloader!");
}

static void basic_setup(void)
{
	terminal_initialize();
	kprintf("Booting..\n\n");
	kprintf("Initializing A20 Address..\n");
	enable_a20();
	kprintf("Initializing CMOS..\n");
	init_cmos();
	kprintf("\nDone!\n\n");
	
	kprintf("Peany's Kernel (%d.%d.%d)\n",
		KERNEL_VER_MAJOR, 
		KERNEL_VER_MINOR, 
		KERNEL_VER_PATCH);
	kprintf("OS: %s (%d.%d.%d)\n\n", OS_TITLE_STR,
		OS_VER_MAJOR,
		OS_VER_MINOR,
		OS_VER_PATCH);
}

void kernel_main(uint32_t mb_magic, void* mb_header)
{
	check_boot(mb_magic, mb_header);
	basic_setup();
	kprintf("== Booted on %u/%u/%u at %u:%u:%u ==\n",
		       	ktime_s.month, ktime_s.dayofmonth, ktime_s.year,
			ktime_s.hours, ktime_s.minutes, ktime_s.seconds);	
	kprintf("Hello, World!\n"); /* Print "Hello, World!" after boot. */

	/* Idle CPU */
	while(1) {
		/* TODO: Do CPU idling here instead of making the machine hang on a while(1) loop */
		asm("hlt");
	}
}

