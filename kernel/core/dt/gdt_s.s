.text
.globl gdt_flush
.extern gdt_ptr

gdt_flush:
	lgdtl gdt_ptr
	
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	
	ljmp $0x08, $flush0 // 0x08 is offset to code segment
flush0:
	ret

