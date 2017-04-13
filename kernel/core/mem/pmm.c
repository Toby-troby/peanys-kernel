#include <core/mem/pmm.h>

uint8_t *bitmap = (uint8_t *)(&e_kernel);

/*
 * What this does is:
 * 1. Calculate Things such as:
 * 	a. total pages that can go into bitmap
 * 	b. bitmap size
 * 
 * 2. Clear out Bitmap.
 */
void pmm_init(uint32_t mem_size)
{
	total_pages = mem_size / PAGE_SIZE;
	bitmap_size = total_pages / PAGE_PER_SECTOR;
	
	if(bitmap_size * PAGE_PER_SECTOR < total_pages)
		bitmap_size++;

	memset(bitmap, 0, bitmap_size); /* Clear Bitmap. */
}

uint32_t pmm_alloc_page()
{
	uint32_t i = pmm_get_free_page();
	SET_USED(i);
	return i;
}

void pmm_free_page(uint32_t page)
{
	SET_FREE(page);
}

uint32_t pmm_get_free_page()
{
	uint32_t i;
	for(i = 0; i <= total_pages; i++) {
		if(!IS_USED(i))
			return i;	
	}
	panic("Ran out of memory!");
	return 0;
}

