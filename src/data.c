/**
 * @file data.c
 * @brief Implementations of the functions that do basic data manipulation operations
 *
 * This file contains an implementations of the functions that do basic data manipulation operations
 * like converting integer to string and vice versa by using function calls.
 * 
 * @author Nandhini
 * @date Nov 4, 2026
 *
 */

#include "../include/common/data.h"
#include "../include/common/memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  
  uint8_t digitCounter= 0;
  uint8_t remainder= 0;
  uint8_t Negative;  

  if (data == 0)
  {
    *(ptr) = '0';
    *(ptr + 1) = '\0';
    return 2;
  }
  
  else if (data < 0)
  {
    Negative = 1;
    data = data*-1;
  }  

  while (data != 0)
  {
    remainder = data % base;
    *(ptr + digitCounter)= ( remainder > 9 ) ? ( remainder - 10 ) + 'a' : remainder + '0';
    digitCounter++;
    data= data / base;
  }  

  if (Negative)
  {
    *(ptr + digitCounter) = '-';
    digitCounter++;
  }  
  digitCounter++;
  *(ptr + digitCounter) = '\0';

 
  my_reverse(ptr, (digitCounter - 1));
  
  return digitCounter;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int32_t number = 0;
  uint8_t Negative;

  
  if(*ptr == '-')
  {
    Negative = 1;
    
    ptr++;

    digits--;
  }

  digits--;
  int i;
  for(i = 0; i < digits; i++)
  {
    number = number * base + *ptr - '0';
    ptr++;
  }

  if(Negative)
  {
    number = -number;
  }

  return number;
}



