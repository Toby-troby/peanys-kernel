#ifndef x86_TTY_H
#define x86_TTY_H

#include <stddef.h>
#include "vga.h"

void terminal_initialize(void);
void terminal_putchar(char c, size_t format);
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_write(const char* data, size_t size, size_t format);
void terminal_writestring(const char* data);
void terminal_printf(const char* data, ...);
void terminal_clearscreen();

#endif
