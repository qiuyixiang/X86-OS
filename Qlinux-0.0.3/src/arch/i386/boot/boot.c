/**
 * Copyright (C) 2024 QIUYIXIANG
 * Project : Qlinux
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

#include <kernel/terminal.h>
#include <kernel/config.h>

// Include MultiBoot Header 
#if defined(__CXX_MULTIBOOT__) && (__CXX_MULTIBOOT__ != 0)
#if (__CXX_MULTIBOOT__ == 1)
#include <boot/multiboot.h>
#endif 

#if (__CXX_MULTIBOOT__ == 2)
#include <boot/multiboot.h>
#endif
#endif

void boot_init(uint32_t _mb_checksum, uint32_t * _mb_info_table){
    if (_mb_checksum == MB_VALID_CHECKSUM_EAX)
        terminal_put_string("[CHECK]\tMULTIBOOT HEADER CHECKSUM CHECK SUCCESSFULLY!\n");
    else
        terminal_put_string("[ERROR]\tMULTIBOOT HEADER CHECKSUM CHECK FAILED!!!\n");
    
    (void)_mb_info_table;
}