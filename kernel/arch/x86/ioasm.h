#ifndef x86_IO_ASM_H
#define x86_IO_ASM_H

#include <stdint.h>
#include "boot.h"

void outb(uint32_t addr, uint8_t val);
void outw(uint32_t addr, uint16_t val);
void outl(uint32_t addr, uint32_t val);

uint8_t inb(uint32_t addr);
uint16_t inw(uint32_t addr);
uint32_t inl(uint32_t addr);

#endif
