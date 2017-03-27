ENTRY(_start)

SECTIONS
{
	. = 1M;
	
	.text :{
		s_text = .;
		*(.multiboot)
		*(.text)
		e_text = .;
	}

	/* Read-only data. */
	.rodata ALIGN (0x1000) : {
		s_rodata = .;
		*(.rodata)
		e_rodata = .;
	}
	
	.data ALIGN (0x1000) : {
		s_data = .;
		*(.data)
		e_data = .;
	}

	.bss : {
		s_bss = .;
		*(COMMON)
		*(.bss)
		e_bss = .;
		e_kernel = .;
	}
}
