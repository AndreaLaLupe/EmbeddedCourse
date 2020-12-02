#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for multitarget build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - builds <FILE>.o object file
#	build - Builds and links all source files
#	all - Same as build
#	clean - Removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#	ARCH - ARM Architecure (thumb)
#	SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
MARCH = armv7e-m 
MFPU = fpv4-sp-d16
MFLOAT-ABI = hard

#General Flags
STD=c99
G_FLAGS= -std=$(STD) -Wall -Werror -g -O0
ASFLAGS= -S
CPPFLAGs= -E
SIZEFLAGS= -Atd
TARGET = c1m2

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	CCSIZE= size
	LD = ld
	OBJDUMP = objdump
	LDFLAGS = -Wl,-Map=$(TARGET).map	
	CFLAGS = $(G_FLAGS)
	PLATFORM = HOST
	SOURCES = $(HSOURCES)
	INCLUDES = $(HINCLUDES)
else
	CC = arm-none-eabi-gcc
	CCSIZE= arm-none-eabi-size
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	LDFLAGS = -Wl, -Map=$(TARGET).map -T $(LINKER_FILE)	
	CFLAGS = $(G_FLAGS) -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) --specs=$(SPECS) -mfpu=$(MFPU) -mfloat-abi=$(MFLOAT-ABI) 
	PLATFORM = MSP432
	SOURCES = $(MSOURCES)
	INCLUDES = $(MINCLUDES)
endif

OBJS = $(SOURCES: .c=.o)
PRECOMP = $(SOURCES: .c=.i)
ASSEMB= $(SOURCES: .c=.asm)

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -D$(PLATFORM) $(INCLUDES) -o $@

%.i : %.c
	$(CC) -E -D$(PLATFORM) $< $(CFLAGS)  $(INCLUDES) -o $@
	
%.asm : %.c
	$(CC) -S -D$(PLATFORM) $< $(CFLAGS)  $(INCLUDES) $(LDFLAGS)-o $@
	$(OBJDUMP) -S -D$(PLATFORM) $< $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -D$(PLATFORM) $(INCLUDES) -o $@
	
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(PRECOMP) $(ASSEMB)


