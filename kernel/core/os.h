#ifndef KERN_OS_H
#define KERN_OS_H

#if !defined (__STDC__)
#error MUST BE BUILT WITH A C COMPILER.
#endif

#define KERNEL_VER_MAJOR 0
#define KERNEL_VER_MINOR 0
#define KERNEL_VER_PATCH 0

/* TODO: Customize your OS stuff! */
#define OS_TITLE_STR "(null)"
#define OS_VER_MAJOR 0
#define OS_VER_MINOR 0
#define OS_VER_PATCH 0

#ifdef __x86__
#include <arch/x86/boot.h>
#include <arch/x86/tty.h>
#endif

#define noreturn _Noreturn

#endif /* KERN_OS_H */

