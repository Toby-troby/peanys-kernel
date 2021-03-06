#include "tty.h"

#include <stdbool.h> // since C doesnt have bools, this header adds 'em in
#include <stddef.h>	 // for C definitions
#include <stdint.h>  // for integer types
#include <stdarg.h>  // for ellipsis stuff
#include <crt/string.h>
#include <crt/stdlib.h>
 
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(void) 
{
	size_t x, y;
	size_t index;

	terminal_row = 0;
	terminal_column = -1;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_TTY_ADDR;
	for (y = 0; y < VGA_HEIGHT; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			index = y * VGA_WIDTH + x;
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
 
void terminal_putchar(char c) 
{
	// Formatting stuff
	if (c == '\n') {
		c = '\0';
		terminal_row += 1;
		terminal_column = -2;
	}

	if (++terminal_column == VGA_WIDTH) {
		terminal_column = -1;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
	
	if (terminal_row >= VGA_HEIGHT)
		terminal_scroll(terminal_row - 24);
	
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
}
 
void terminal_write(const char* data, size_t size) 
{
	size_t i;
	for (i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_print(const char* data) 
{
	terminal_write(data, strlen(data));
}

void terminal_printf(const char* s, ...)
{
	va_list ap;

	char buf[16];
	int i, j, size, buflen, neg;

	unsigned char c;
	int ival;
	unsigned int uival;

	va_start(ap, s);

	while ((c = *s++)) {
		size = 0;
		neg = 0;

		if (c == 0)
			break;
		else if (c == '%') {
			c = *s++;
			if (c >= '0' && c <= '9') {
				size = c - '0';
				c = *s++;
			}

			if (c == 'd') {
				ival = va_arg(ap, int);
				if (ival < 0) {
					uival = 0 - ival;
					neg++;
				} else
					uival = ival;
				itoa(buf, uival, 10);

				buflen = strlen(buf);
				if (buflen < size)
					for (i = size, j = buflen; i >= 0;
					     i--, j--)
						buf[i] =
						    (j >=
						     0) ? buf[j] : '0';

				if (neg)
					terminal_printf("-%s", buf);
				else
					terminal_printf(buf);
			}
			 else if (c == 'u') {
				uival = va_arg(ap, int);
				itoa(buf, uival, 10);

				buflen = strlen(buf);
				if (buflen < size)
					for (i = size, j = buflen; i >= 0;
					     i--, j--)
						buf[i] =
						    (j >=
						     0) ? buf[j] : '0';

				terminal_printf(buf);
			} else if (c == 'x' || c == 'X') {
				uival = va_arg(ap, int);
				itoa(buf, uival, 16);

				buflen = strlen(buf);
				if (buflen < size)
					for (i = size, j = buflen; i >= 0;
					     i--, j--)
						buf[i] =
						    (j >=
						     0) ? buf[j] : '0';

				terminal_printf("0x%s", buf);
			} else if (c == 'p') {
				uival = va_arg(ap, int);
				itoa(buf, uival, 16);
				size = 8;

				buflen = strlen(buf);
				if (buflen < size)
					for (i = size, j = buflen; i >= 0;
					     i--, j--)
						buf[i] =
						    (j >=
						     0) ? buf[j] : '0';

				terminal_printf("0x%s", buf);
			} else if (c == 's') {
				terminal_printf(va_arg(ap, const char*));
			} 
		} else
			terminal_putchar(c);
	}

	return;
}

void terminal_clearscreen()
{ 
	size_t y, x;
	for (y = 0; y < VGA_HEIGHT; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
	terminal_row = 0;
	terminal_column = 0;
}

void terminal_setcursorpos(size_t x, size_t y)
{
	terminal_column = x;
	terminal_row = y;
}

void terminal_scroll(unsigned int n)
{
	unsigned char *video, *tmp;

	for(video = (unsigned char *) VGA_TTY_ADDR; video < (unsigned char *) VGA_TTY_ADDR_LIM; video += 2) {
		tmp = (unsigned char *) (video + n * 160);

		if (tmp < (unsigned char *) VGA_TTY_ADDR_LIM) {
			*video = *tmp;
			*(video + 1) = *(tmp + 1);
		} else {
			*video = 0;
			*(video + 1) = 0x07;
		}
	}
	terminal_row -= n;
}

