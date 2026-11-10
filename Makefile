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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      Example commands:
#      make main.i PLATFORM=HOST
#      make main.asm PLATFORM=HOST
#      make main.o PLATFORM=HOST
#      make build PLATFORM=HOST
#      make clean PLATFORM=HOST
#      make main.i PLATFORM=MSP432
#      make main.asm PLATFORM=MSP432
#      make main.o PLATFORM=MSP432
#      make build PLATFORM=MSP432
#      make clean PLATFORM=MSP432
#
# Platform Overrides:
#      PLATFORM can be 'MSP432' or 'HOST'
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = $(PLATFORM)

# Architectures Specific Flags
ifeq ($(PLATFORM),MSP432)
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
endif

TARGET = c1m2
CPPFLAGS =  $(INCLUDES)
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
CC = gcc
SIZE = size

ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE), TRUE)
	CFLAGS += -DVERBOSE
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM),MSP432)
CC = arm-none-eabi-gcc 
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS += -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfpu=fpv4-sp-d16  -mfloat-abi=hard --specs=$(SPECS)
endif



OBJS = $(SOURCES:.c=.o)

%.i : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -E -o $@

%.asm : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -S -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: build
build: all size

.PHONY: all 
all: $(TARGET).out

.PHONY: compile-all 
compile-all: $(OBJS)

size: $(TARGET).out
	@$(SIZE) $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map
