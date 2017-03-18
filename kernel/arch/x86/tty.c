#include "tty.h"

#include <stdbool.h> // since C doesnt have bools, this header adds 'em in
#include <stddef.h>	 // for C definitions
#include <stdint.h>  // for integer types
#include <stdarg.h>  // for ellipsis stuff
#include <libc/string.h>
 
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_TTY_ADDR;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c, size_t format) 
{
	// Formatting stuff
	if(format != 0) {
		if(c == '\n') {
			c = '\0';
			terminal_row += 1;
			terminal_column = -1;
		}
	}

	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}
 
void terminal_write(const char* data, size_t size, size_t format) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i], format);
}
 
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data), 0);
}

void terminal_printf(const char* data, ...)
{
	va_list list;
	va_start(list, data);
	terminal_write(data, strlen(data), 1);
	va_end(list);
}

void terminal_clearscreen()
{
	terminal_row = 0;
	terminal_column =0;
	// TODO: use memset to clear terminal_buffer.
}



