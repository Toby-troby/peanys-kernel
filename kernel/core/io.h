#ifndef KERN_IO_H
#define KERN_IO_H

#include <core/os.h>
#include <drivers/acpi/acpi.h>

#define kprintf terminal_printf
#define kputc terminal_putchar

// printing stuff
void kputs(const char *s);
void panic(const char *s);

#endif
