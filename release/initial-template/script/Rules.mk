# Makefile Rules And General Functions For The Project 
# @Copyright Copyright (C) QIUYIXIANG
# date: 07-27-2024
# This Makefile Rules All used for Main Makefile Except some Special Global Tools
# These Tools will export to the sub-makefile for more utility

# Definition for Global Tools Chain
ARCH		:=		i386
OS_NAME		:=		Qlinux
export ARCH OS_NAME

# Command For T (Used for specify particular tool chain prefix)
ifndef T
TOOLCHAIN_PREFIX	:=	i686-elf-
else
TOOLCHAIN_PREFIX	:=	$(T)
endif
# Command For Command S (Used to Silent the operation)
ifndef S
SILENT				:=	1
else
SILENT				:=	$(S)
endif
# Options for Command D (Used for debugger flags)
ifndef D
DEBUGGER			:=	0
else
DEBUGGER			:=	$(D)
endif

export SILENT
export DEBUGGER

# Definition For Directory Path
# Main Path Entry (Which Means these paths appear in the root directory)
INCLUDE_GLOBAL_PATH		:=	./include
BUILD_GLOBAL_PATH		:=	./build
KERNEL_GLOBAL_PATH		:=	./kernel
ARCH_GLOBAL_PATH		:=	./arch
LIB_GLOBAL_PATH			:=	./lib
SCRIPT_GLOBAL_PATH		:=	./script
USER_GLOBAL_PATH		:=  ./user

# Definition For GNU Tool Chain
GCC			:=		$(TOOLCHAIN_PREFIX)gcc
AS			:=		$(TOOLCHAIN_PREFIX)as
LD			:=		$(TOOLCHAIN_PREFIX)ld
OBJDUMP		:=		$(TOOLCHAIN_PREFIX)objdump
OBJCOPY		:=		$(TOOLCHAIN_PREFIX)objcopy
# Export Tool Chain Name for global environment
export GCC
export AS
export OBJDUMP
export OBJCOPY

# Other Tools
GRUB_PREFIX		:=	grub-
GRUB_FILE		:= 	$(GRUB_PREFIX)file
GRUB_MKRESCUE	:=	$(GRUB_PREFIX)mkrescue 
BOCHS			:=	bochs
QEMU			:=	qemu

# GNU Compilation Flags
ifeq ($(DEBUGGER),1)
GCC_FLAGS		:=	-O0
else
GCC_FLAGS		:=	-O3
endif 
GCC_FLAGS		+=	-Wall -Wextra
GCC_FLAGS		+=	-std=gnu99 -m32
GCC_FLAGS		+=	-fno-builtin -fno-builtin-function -ffreestanding -fhosted
GCC_FLAGS		+=	-nostdlib -nolibc -nostdinc

# LD Linker Flags
LD_FLAGS		:=	-m elf_i386 -EL 
LD_FLAGS		+=	-nostdlib -nolibc -nodefaultlibs -nostartfiles
LD_FLAGS		+=	-T $(SCRIPT_GLOBAL_PATH)/linker.ld

# AS Assembler Flags
AS_FLAGS		:=	--warn
AS_FLAGS		+=	--32
AS_FLAGS		+=	-march=$(ARCH) -mtune=$(ARCH) 
AS_FLAGS		+=	-msyntax=att -mmnemonic=att

ifeq ($(DEBUGGER),1)
GCC_FLAGS		+=	-g
AS_FLAGS		+=	-D --gstabs
endif

export GCC_FLAGS
export LD_FLAGS
export AS_FLAGS

# define some helper function
define execute
$(if $(filter $(SILENT), 1), @$(1), $(1))
endef

define print
	@echo $1
endef