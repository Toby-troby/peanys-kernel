#ifndef KERN_PMM_H
#define KERN_PMM_H

#include <core/os.h>
#include <core/io.h>
#include <crt/string.h>

#define PAGE_SIZE 	(uint32_t) 4096
#define PAGE_PER_SECTOR (uint32_t) 8

#define PAGE_ALIGN(addr) (((addr) & 0xFFFFF000) + 0x1000)

#define SET_USED(i)  bitmap[i / PAGE_PER_SECTOR] = bitmap[i / PAGE_PER_SECTOR] |   (1 << (i % PAGE_PER_SECTOR))
#define SET_FREE(i)  bitmap[i / PAGE_PER_SECTOR] = bitmap[i / PAGE_PER_SECTOR] & (~(1 << (i % PAGE_PER_SECTOR)))
#define  IS_USED(i) ((bitmap[i / PAGE_PER_SECTOR] >> (i % PAGE_PER_SECTOR)) & 0x1)

uint8_t *bitmap;
uint32_t bitmap_size;
uint32_t total_pages;

void 	 pmm_init(uint32_t mem_size);
uint32_t pmm_alloc_page();
void 	 pmm_free_page(uint32_t page);
uint32_t pmm_get_free_page();

#endif /* KERN_PMM_H */

