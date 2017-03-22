#include "io.h"

void kputs(const char *s) {
	if(s == 0) {
		kprintf("\n");
	}
	else {
		kprintf("%s\n", s);
	}
}
