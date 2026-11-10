## Files

## Build and run
    gcc -Wall -Werror -o stats stats.c
    ./stats

## Author
Nandhini Rajapandiyan

## Description

This repository contains a small C application for a course on embedded
systems.

stats.c - functions will analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set. In addition,It will reorder this data set from large to small. All statistics are rounded down to the nearest integer.

Makefile and sources.mk - Compile multiple files, link them together and create a final output executable. Support two platforms; the host environment and the target embedded system MSP432. The host system will allow to simulate software on a host platform. The target system build is created to support MSP432.
Sample build commands:
make build PLATFORM=MSP432
make build PLATFORM=HOST
make main.i PLATFORM=HOST
make main.asm PLATFORM=MSP432


Course1.c:
int8_t test_data1() - This function will test to atoi and itoa conversions for you.

int8_t test_data2() - This function will test to atoi and itoa conversions for you.

int8_t test_memmove1() - This function will test non-overlapped memmove.

int8_t test_memmove2() - This function will test overlapped memmove where there is overlap of the end of destination and start of the source regions.

int8_t test_memmove3() - This function will test overlapped memmove where there is overlap of the start of destination and end of the source regions.

int8_t test_memcopy() -This function will test memcopy.

int8_t test_memset() - This function will test memset and memzero.

iInt8_t test_reverse() - This function will test reverse.
