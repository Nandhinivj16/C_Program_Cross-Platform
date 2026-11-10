/**
 * @file data.h
 * @brief declaration and documentation of some basic data manipulation functions
 *
 * This header file contains an abstraction of the basic data manipulation,
 * converting data from integer to ASCII and vice-versa
 *
 * @author
 * @date
 *
 */

#ifndef __data_H__
#define __data_H__

#include <math.h>
#include <stdint.h>

/**
 * @brief Converting given data from integer to ASCII string
 *
 * Given a pointer of a char dataset, this will set a provided
 * index into that dataset to the value provided.
 * Regarding the signed numbers, the function handles the base 10 signed numbers only.
 *
 * @param data int number to be converted
 * @param ptr pointer of data array
 * @param base base to convert to
 *
 * @return length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converting given data from ASCII string to integer
 *
 * Given a pointer of a char dataset, this will set a provided
 * index into that dataset to the value provided.
 * The function handles the base 10 signed numbers.
 *
 * @param ptr pointer of the string to be converted
 * @param digits number of digits in the character set
 * @param value base to convert to
 *
 * @return converted integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif

