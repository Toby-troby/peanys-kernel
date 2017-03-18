LINKER= arch/$(ARCH)/linker.ld
CFLAG= $(INCDIR) -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAG= -T $(LINKER) -o $(KERNEL) -ffreestanding -O2 -nostdlib $(OBJS) -lgcc

ASM=i686-elf-as
GCC=i686-elf-gcc
LD=i686-elf-gcc

NM=nm
OBJDUMP=objdump

EMU= qemu-system-i386
EMUFLAG= -kernel $(KERNEL)
