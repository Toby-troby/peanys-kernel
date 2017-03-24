ENTRY(_start)

SECTIONS
{
	. = 1M;
	
	.text :{
		*(.multiboot)
		*(.text)
	}

	/* Read-only data. */
	.rodata ALIGN (0x1000) : {
		*(.rodata)
	}
	
	.data ALIGN (0x1000) : {
		*(.data)
	}

	.bss : {
		*(COMMON)
		*(.bss)
	}
}