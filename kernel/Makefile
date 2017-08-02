ARCH=x86
KERNEL=kernel.bin
IMAGE=kernel.iso
IMAGEDIR = ../image
BINDIR = ./bin
INCDIR= -I.

include ./arch/$(ARCH)/config.make

include ./core/Makefile
include ./crt/Makefile
include ./arch/$(ARCH)/Makefile

CFLAG:=$(CFLAG) -D__$(ARCH)__

all: $(OBJS)
	@echo "LD    $(KERNEL)"
	$(LD) $(LDFLAG)
	mv $(OBJS) $(BINDIR)/objs
	mv $(KERNEL) $(BINDIR)

%.o: %.c
	@echo "GCC   $<"
	$(GCC) $(CFLAG) $(INCDIR) -c $< -o $@
	
%.o: %.asm
	@echo "ASM   $<"
	$(ASM) --32 $< -o $@

help:
	@echo 'Recipes:'
	@echo 'help - prints this'
	@echo 'debug - prints symbols'
	@echo 'disasm - disassembles binary'
	@echo 'run - runs binary'
	@echo 'clean - removes binary and object files'
	
debug:
	$(NM) -n $(BINDIR)/$(KERNEL)
	
disasm:
	$(OBJDUMP) -d $(BINDIR)/$(KERNEL) > disasm.txt
	
run:
	$(EMU) $(EMUFLAG)

clean:
	@echo "RM    OBJS"
	rm -rf $(BINDIR)/objs/*.o
	@echo "RM    BIN" 
	rm -rf $(BINDIR)/$(KERNEL)
	rm -rf $(IMAGEDIR)/boot/$(KERNEL)
	@echo "RM    ISO"
	rm -rf ../*.iso

iso:
	cp $(BINDIR)/$(KERNEL) ../image/boot/$(KERNEL)
	grub-mkrescue -o ../$(IMAGE) $(IMAGEDIR)
	
$(V).SILENT: