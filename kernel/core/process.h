#ifndef KERN_PROCESS_H
#define KERN_PROCESS_H

#include <core/os.h>

struct process_t {
	regs_t regs;
	/* TODO: Add page directory to this struct. */
	struct process_t *next;
};

#endif /* KERN_PROCESS_H */

