ARCH=x86
KERNEL=kernel.bin
INCDIR= -I.

include ./arch/$(ARCH)/config.make

include ./core/Makefile
include ./drivers/Makefile
include ./crt/Makefile
include ./arch/$(ARCH)/Makefile

CFLAG:=$(CFLAG) -D__$(ARCH)__

all: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) $(LDFLAG)

%.o: %.c
	$(GCC) $(CFLAG) $(INCDIR) -c $< -o $@
	
%.o: %.asm
	$(ASM) $< -o $@
	
help:
	@echo This is a makefile for the kernel.
	@echo kernel: $(KERNEL)
	
debug:
	$(NM) -n $(KERNEL)
	
disasm:
	$(OBJDUMP) -d $(KERNEL) > disasm.txt
	
run:
	$(EMU) $(EMUFLAG)

clean:
	rm -f $(OBJS) $(KERNEL) disasm.txt
	
clean-o:
	rm -f $(OBJS)
	
