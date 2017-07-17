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
	$(ASM) --32 $< -o $@

%.o: %.s
	$(ASM) $< -o $@

help:
	@echo '{ help, debug, disasm, run, clean, clean-o }'
	@echo 'help - prints this'
	@echo 'debug - prints symbols'
	@echo 'disasm - disassembles binary'
	@echo 'run - runs binary'
	@echo 'clean - removes binary and object files'
	@echo 'clean-o - removes object files'
	
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
	
