ENTRY(main)

MEMORY{
   FLASH (rwx): ORIGIN = 0x0000, LENGTH = 0x1FA0 
   RAM (rwx):   ORIGIN = 0x0100, LENGTH = 0x04FF 
   EEPROM(rw):  ORIGIN = 0x0000, LENGTH = 0x0000
}

SECTIONS {
    .text : {
        . = ALIGN(2);
        *(.isrVectors)
        *(.isrVectors*)
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
    } > FLASH

    _data_flash = .;

    .data : AT ( _data_flash ) {
        . = ALIGN(2);
        _data_begin = .;
        *(.data)
        *(.data*)
        . = ALIGN(2);
        _data_end = .;
    } > RAM

    .bss : {
        . = ALIGN(2);
        _bss_begin = .;
        _bss_start__ = _bss_begin;
        *(.bss)
        *(.bss*)
	*(COMMON)
        . = ALIGN(2);
        _bss_end = .;
        __bss_end__ = _bss_end;
    } > RAM

    _stack_size = 0x001;
    _stack_end = ORIGIN(RAM)+LENGTH(RAM);
    _stack_begin = _stack_end - _stack_size;
    . = _stack_begin;

    ._stack : {
        . = . + _stack_size;
    } > RAM
}

