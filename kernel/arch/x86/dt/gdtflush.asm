.global gdt_flush
.extern gdt_ptr

gdt_flush:
	lgdt gdt_ptr

	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
	ljmp $0x08, $flush2
flush2:
	ret
