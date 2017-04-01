#include <core/dt/gdt.h>

#define GDT_ENTRY_SIZE 8
#define GDT_BASE 0x00000000
#define GDT_LIMIT 0xFFFFFFFF

static void gdt_init_entry(int index, uint32_t limit, uint8_t access)
{
	uint32_t base = 0;
	uint8_t gran = 0xCF;
	gdt_entries[index].base_low = (base & 0xFFFF);
	gdt_entries[index].base_middle = (base >> 16) & 0xFF;
	gdt_entries[index].base_high = (base >> 24) & 0xFF;

	gdt_entries[index].limit_low = (limit & 0xFFFF);
	gdt_entries[index].granularity = (limit >> 16) & 0x0F;

	gdt_entries[index].granularity |= gran & 0xF0;
	gdt_entries[index].access = access;
}

void gdt_init()
{
	gdt_ptr.limit = (sizeof(struct gdt_entry_t) * GDT_ENTRY_SIZE) - 1;
	gdt_ptr.base = (uint32_t)&gdt_entries;

	gdt_init_entry(0, 0, 0); /* Null Segment (MUST HAVE) */
	gdt_init_entry(1, GDT_LIMIT, 0x9A); /* Code Segment */
	gdt_init_entry(2, GDT_LIMIT, 0x92); /* Data Segment */
	gdt_init_entry(3, GDT_LIMIT, 0xFA); /* User Code Segment */
	gdt_init_entry(4, GDT_LIMIT, 0xF2); /* User Data Segment */

	gdt_flush();
}

