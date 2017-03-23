#ifndef x86_IO_ASM_H
#define x86_IO_ASM_H

#include <stdint.h>

#ifndef asmv
#define asmv asm volatile
#endif

void outb(uint32_t addr, uint8_t val);
void outw(uint32_t addr, uint16_t val);
void outl(uint32_t addr, uint32_t val);

uint8_t inb(uint32_t addr);
uint16_t inw(uint32_t addr);
uint32_t inl(uint32_t addr);

/* 
copied straight from linux kernel, fuckin RIP.
linus dont sue me please, i need my shekels!!
*/
struct biosregs {
	union {
		struct {
			u32 edi;
			u32 esi;
			u32 ebp;
			u32 _esp;
			u32 ebx;
			u32 edx;
			u32 ecx;
			u32 eax;
			u32 _fsgs;
			u32 _dses;
			u32 eflags;
		};
		struct {
			u16 di, hdi;
			u16 si, hsi;
			u16 bp, hbp;
			u16 _sp, _hsp;
			u16 bx, hbx;
			u16 dx, hdx;
			u16 cx, hcx;
			u16 ax, hax;
			u16 gs, fs;
			u16 es, ds;
			u16 flags, hflags;
		};
		struct {
			u8 dil, dih, edi2, edi3;
			u8 sil, sih, esi2, esi3;
			u8 bpl, bph, ebp2, ebp3;
			u8 _spl, _sph, _esp2, _esp3;
			u8 bl, bh, ebx2, ebx3;
			u8 dl, dh, edx2, edx3;
			u8 cl, ch, ecx2, ecx3;
			u8 al, ah, eax2, eax3;
		};
	};
};

#endif
