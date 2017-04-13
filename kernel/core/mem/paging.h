#ifndef KERN_PAGING_H
#define KERN_PAGING_H

#include <core/os.h>
#include <core/io.h>
#include <core/mem/pmm.h>

/* Assembly Functions */
extern void load_pdir(unsigned int*);
extern void enable_paging(void);


#define PAGE_DIR_SIZE 1024
#define PAGE_TABLE_SIZE 1024

/* Page Directory containing all Page Tables. */
unsigned int ptable_count;
unsigned int page_directory[PAGE_DIR_SIZE] __attribute__((aligned(4096)));

void wipe_pdir(void);
void init_paging(void);
void add_ptable(unsigned int ptable[], size_t pt_size);

#endif

