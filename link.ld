ENTRY(bootstrap)
OUTPUT_FORMAT("binary")
SECTIONS {
    . = 0xF000;

    .text :
    {
        *(.bootstrap)
        *(.text)
    }
    .rodata : 
    {
        *(.rodata)
    }
    .data : 
    {
        *(.data)
    }
    .bss : 
    {
        *(.bss)    
    }
}
