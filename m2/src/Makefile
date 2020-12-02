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

#Variables & Line Continuance
FLAGS = -Wall \ 
	-Werror \
	-g \
	-O0 \
	-std =c99  \
	-l

 
# Platform Overrides
PLATFORM = msp432

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
BASENAME = c1m2
TARGET = $(BASENAME).out
LDFLAGS = -Wl, -Map=$(BASENAME).map -T $(LINKER_FILE)
CFLAGS = -mcpu = $(CPU) -m$(ARCH) -march=armv7e-m -mfpu=fpv4-sp-d16
--specs=$(SPECS) -$(FLAGS) -E main.i -S main.asm
CPPFLAGs = -I. \
	   -I(/home/aa/ese-coursera-course1/assesments/m2)

OBJS = $(SRCS: .c=.o)

%.o = %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGs) -o $@
	
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map main.i main.asm

ifeq ($(PLATFORM),HOST)
	CC = arm-none-eabi-gcc
	# etc
else
	CC = gcc
	# etc
endif
