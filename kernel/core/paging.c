#include <core/paging.h>

void wipe_pdir(void)
{
	int pdir_i; /* Page Directory Index */
	for(pdir_i = 0; pdir_i < PAGE_DIR_SIZE; pdir_i++)
		page_directory[pdir_i] = 0x00000002;

	ptable_count = 0;
}

void init_paging(void)
{
	wipe_pdir();
	load_pdir(page_directory);
	enable_paging();
}

/*
 *  Please do __attribute__((aligned(4096))) for ptable for now.
 *  I know doing that is shit, but it's temporary.
 *  I will write a page frame allocator as soon as possible.
 *
 *  Also, DO NOT MAP PTABLE. This function will do it for you.
 */
void add_ptable(unsigned int ptable[], size_t pt_size)
{
	if(pt_size != PAGE_TABLE_SIZE)
		panic("Invalid Page Table Size!");
	
	/*
	 *  Attributes : supervisor level, read/write, present.
	 */
	unsigned int index;
	for(index = 0; index < pt_size; index++)
		ptable[index] = (index * 0x1000) | 3; 

	page_directory[ptable_count] = (unsigned int)ptable | 3;
}

