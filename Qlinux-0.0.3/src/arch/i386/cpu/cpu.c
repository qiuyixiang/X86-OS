/**
 * Copyright (C) 2024 QIUYIXIANG
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <cpu/cpu.h>
#include <cpu/gdt.h>
#include <cpu/idt.h>
#include <kernel/terminal.h>

void i386_update_segment(uint16_t DS, uint16_t FS, uint16_t GS, uint16_t ES, uint16_t SS){
    __asm__ volatile(
        "movw %0, %%ds \n\t"
        "movw %1, %%fs \n\t"
        "movw %2, %%gs \n\t"
        "movw %3, %%es \n\t"
        "movw %4, %%ss \n\t"
        :: "r"(DS), "r"(FS), "r"(GS), "r"(ES), "r"(SS)
    );
}
void cpu_init(void){

    __cpu_gdt_init();
    __cpu_idt_init();
    terminal_put_string("[INIT ]\tCPU STATE INITIALIZE SUCCESSFULLY!\n");
}