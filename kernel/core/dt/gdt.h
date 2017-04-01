#ifndef KERN_GDT_H
#define KERN_GDT_H

#include <core/os.h>

#define GDT_ENTRY_SIZE 8

struct gdt_ptr_t {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct gdt_entry_t {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
} __attribute__((packed));

extern void gdt_flush();

struct gdt_ptr_t gdt_ptr;
struct gdt_entry_t gdt_entries[GDT_ENTRY_SIZE];

void gdt_init();

#endif

