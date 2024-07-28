/*
* Copyright (C) QIUYIXIANG
* 
* Main File For Qlinux Kernel And the whole Project
* This File Control all of the project and source files
* And Include the main loop of the kernel procedure
* Including User Space and Kernel Space and also include 
* some general Hardware and Software Interaction parts.
*
* @Date 07-28-2024
*/

#include <kernel/types.h>
#include <arch/i386/multiboot.h>
#include <arch/monitor/vga.h>

/* Kernel Initialization Function Specification
*  This Function will Initialized Some Firmware and Hardware Driver
*  And Create Kernel Data Structure about some Hardware and 
*  Architecture  Related Information Table
*  After Initialization it will call _kernel_main_
*/  
void _kernel_init_(uint32_t __mb_verify, uint32_t* __mb_info_tb){

    // Initialize VGA Monitor
    vga_init(VGA_THEME_DARK);
    vga_put_string("[INIT] \tVGA Text Display Mode Initialized Successfully \n");
    if (__mb_verify == MB_CHECK_SUCCESS)
        vga_put_string("[CHECK]\tMultiBoot Header CHECKSUM Check Finished !\n");
    
    while (1)
    {
        
    }
    
}

