#ifndef x86_ASM_H
#define x86_ASM_H

#ifndef asmv
#define asmv asm volatile
#endif

#define sti() asm ("sti");
#define cli() asm ("cli");

#endif
