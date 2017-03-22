#ifndef KERN_IO_H
#define KERN_IO_H

#include <core/os.h>

#define kprintf terminal_printf
#define kputc terminal_putchar

void kputs(const char *s);

#endif
