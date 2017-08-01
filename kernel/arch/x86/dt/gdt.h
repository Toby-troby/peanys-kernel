#ifndef x86_GDT_H
#define x86_GDT_H

#define utext_segment
#define udata_segment
#define ktext_segment
#define kdata_segment
#define stack_segment

void gdt_init(void);

#endif

