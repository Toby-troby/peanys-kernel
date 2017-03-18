#ifndef OS_H
#define OS_H

#define KERNEL_VER_MAJOR "0"
#define KERNEL_VER_MINOR "0"

#ifdef __x86__
#include <arch/x86/vga.h>
#include <arch/x86/tty.h>
#endif

#endif//OS_H
