#ifndef x86_BINSECTIONS_H
#define x86_BINSECTIONS_H

/* Access these with & */

extern unsigned int s_text;
extern unsigned int e_text;

extern unsigned int s_rodata;
extern unsigned int e_rodata;

extern unsigned int s_data;
extern unsigned int e_data;

extern unsigned int s_bss;
extern unsigned int e_bss;

extern unsigned int e_kernel;

#endif /* x86_BINSECTIONS_H */
