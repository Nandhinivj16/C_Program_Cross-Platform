/**
 * @file stats.h
 * @brief Declarations of statistical analysis functions for an array
 *
 * This header declares functions that compute the minimum, maximum,
 * mean and median of an array, and that sort and print an array.
 *
 * @author Your Name
 * @date October 2026
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array: minimum, maximum, mean, median
 *
 * @param min     Minimum value of the array
 * @param max     Maximum value of the array
 * @param mean    Mean value of the array
 * @param median  Median value of the array
 *
 * @return None
 */
void print_statistics(unsigned char min, unsigned char max,
                      unsigned char mean, unsigned char median);

/**
 * @brief Prints the elements of an array
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return None
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median of an array
 *
 * The array is sorted (largest to smallest). For an even number of
 * elements the median is the mean of the two middle elements.
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return Median of the array (unsigned char)
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean of the elements of an array
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return Mean value (unsigned char, integer part)
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum element of an array
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return Maximum value (unsigned char)
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum element of an array
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return Minimum value (unsigned char)
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Sorts an array from largest to smallest
 *
 * The sort is performed in place.
 *
 * @param array   Pointer to the data array
 * @param length  Number of elements in the array
 *
 * @return None
 */
void sort_array(unsigned char *array, unsigned int length);
int test_stats(void);

#endif /* __STATS_H__ */
