#ifndef KERN_IO_H
#define KERN_IO_H

#include <core/os.h>

#define kprintf terminal_printf
#define kputc terminal_putchar

// printing stuff
void kputs(const char *s);
noreturn void panic(const char *s);

#endif /* KERN_IO_H */

