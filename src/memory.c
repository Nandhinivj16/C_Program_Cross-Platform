/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include "../include/common/memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  uint8_t * tmpptr = (uint8_t *)malloc(length * sizeof(uint8_t));
  my_memcopy(src, tmpptr, length);
  my_memcopy(tmpptr, dst, length);
  free(tmpptr);
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  uint8_t * tpptr = dst;
  while (tpptr < dst + length) {
    *tpptr++ = *src++;
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  uint8_t * sptr = src;
  while (sptr < src + length) {
    *sptr++ = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  uint8_t * p = src;
  while (p < src + length) {
    *p++ = 0;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  uint8_t tmp;
  uint8_t * pstart = src;
  uint8_t * pend = src + length - 1;
  while (pstart < pend) {
    tmp = *pstart;
    *pstart++ = *pend;
    *pend-- = tmp;
  }
  return src;
}

int32_t * reserve_words(size_t length) {
  return (int32_t *) malloc(length * sizeof(int32_t));
}

void free_words(uint32_t * src) {
  free(src);
}
