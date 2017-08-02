#ifndef x86_BOOT_H
#define x86_BOOT_H

#include <crt/types.h>
#include <crt/string.h>

#include "asm.h"
#include "ioasm.h"
#include "binsections.h"

#include "dt/gdt.h"

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

typedef uint32_t addr_t;

/* TODO: Do initialisation functions. */
void enable_a20(void);

struct multiboot_info_t {
	u32 flags;
	u32 mem_lower;
	u32 mem_upper;
	u32 boot_device;
	u32 cmdline;
	u32 mods_count;
	u32 mods_addr;
	struct elf_sec {
		u32 num;
		u32 size;
		u32 addr;
		u32 shndx;
	};
	u32 drives_length;
	u32 drives_addr;
	u32 mmap_length;
	u32 mmap_addr;
	u32 config_table;
	u32 boot_loader_name;
	u32 apm_table;
	u32 vbe_control_info;
	u32 vbe_mode_info;
	u32 vbe_mode;
	u16 vbe_interface_seg;
	u16 vbe_interface_off;
	u16 vbe_interface_len;
};

struct multiboot_info_t *mbi;

#endif

