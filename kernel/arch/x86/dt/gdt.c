#include "gdt.h"
#include <stdint.h>

#define GDT_NULL  0
#define GDT_KCODE 1
#define GDT_KDATA 2
#define GDT_UCODE 3
#define GDT_UDATA 4

struct gdt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__ ((packed));
typedef struct gdt_ptr gdt_ptr_t;

struct gdt_entry {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} __attribute__ ((packed));

typedef struct gdt_entry gdt_entry_t;

gdt_entry_t gdt_entries[0xFF]; /* 255 GDT entries */
gdt_ptr_t gdt_ptr;

extern void gdt_flush();

static void gdt_set_entry(uint32_t entry, uint32_t base, uint32_t limit, uint8_t access)
{
	uint8_t granularity = 0xCF;
	if(entry == GDT_NULL) /* detect if entry is supposed to be null segment */
		granularity = 0;

	gdt_entries[entry].base_low    = (base & 0xFFFF);
	gdt_entries[entry].base_middle = (base >> 16) & 0xFF;
	gdt_entries[entry].base_high   = (base >> 24) & 0xFF;
	
	gdt_entries[entry].limit_low   = (limit & 0xFFFF);

	gdt_entries[entry].granularity = (limit >> 16) & 0x0F;
	gdt_entries[entry].granularity |= granularity & 0xF0;
	gdt_entries[entry].access      = access;
}

void gdt_init(void)
{
	/* limit = how m uch gdt can hold :: base = base address of gdt entries */
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 0xFF - 1);
	gdt_ptr.base = (uint32_t)&gdt_entries;

	gdt_set_entry(GDT_NULL, 0, 0, 0); /* null segment */
	gdt_set_entry(GDT_KCODE, 0, 0xFFFFFFFF, 0x9A); /* Kernel Code Segment */
        gdt_set_entry(GDT_KDATA, 0, 0xFFFFFFFF, 0x92); /* Kernel Data Segment */
	gdt_set_entry(GDT_UCODE, 0, 0xFFFFFFFF, 0xFA); /* User Code Segment */
	gdt_set_entry(GDT_UDATA, 0, 0xFFFFFFFF, 0xF2); /* User Data Segment */

	gdt_flush(); /* load gdt into CPU */

	/*
	 * TODO: Do TSS too.
	 */
}
