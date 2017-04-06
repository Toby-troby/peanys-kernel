#ifndef KERN_OS_H
#define KERN_OS_H

#ifdef __cplusplus
#error THIS KERNEL MUST NOT BE BUILT WITH A C++ COMPILER.
#elif __OBJC__
#error THIS KERNEL MUST NOT BE BUILT WITH A OBJECTIVE-C COMPILER.
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

enum kernel_build_info_t {
	build_date = __DATE__,
	build_time = __TIME__,
	build_stdc = __STDC__,
	build_stdc_ver = __STDC_VERSION__
};

#endif//OS_H
