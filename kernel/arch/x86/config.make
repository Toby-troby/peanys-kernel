LINKER= arch/$(ARCH)/linker.ld
CFLAG= -I. -std=gnu89 -O0 -Wall -Wextra -Werror -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs -ffreestanding -fms-extensions -m32
LDFLAG= -m elf_i386 -static -T $(LINKER) -o $(KERNEL) $(OBJS)

ASM=as
GCC=gcc
LD=ld

NM=nm
OBJDUMP=objdump

EMU= qemu-system-i386
EMUFLAG= -kernel $(KERNEL)

