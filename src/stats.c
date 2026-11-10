/**
 * @file stats.c
 * @brief Statistical analysis of a data set
 *
 * The program sorts a test array, computes its minimum, maximum,
 * mean and median, and prints the results.
 *
 * @author Your Name
 * @date October 2026
 */
#include <stdio.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

#define SIZE (40)

int test_stats(void) {
  unsigned char test[SIZE] = {
    34, 201, 190, 154,   8, 194,   2,   6, 114,  88,
    45,  76, 123,  87,  25,  23, 200, 122, 150,  90,
    92,  87, 177, 244, 201,   6,  12,  60,   8,   2,
     5,  67,   7,  87, 250, 230,  99,   3, 100,  90
  };

  printf("Original array:\n");
  print_array(test, SIZE);

  sort_array(test, SIZE);
  printf("\nSorted array (largest to smallest):\n");
  print_array(test, SIZE);

  print_statistics(find_minimum(test, SIZE),
                   find_maximum(test, SIZE),
                   find_mean(test, SIZE),
                   find_median(test, SIZE));
  return 0;
}

void print_statistics(unsigned char min, unsigned char max,
                      unsigned char mean, unsigned char median) {
  printf("\nStatistics:\n");
  printf("  Minimum: %u\n", min);
  printf("  Maximum: %u\n", max);
  printf("  Mean:    %u\n", mean);
  printf("  Median:  %u\n", median);
}

void print_array(unsigned char *array, unsigned int length) {
#ifdef VERBOSE
	unsigned int i;
	for(i=0;i<length;i++){
		PRINTF("%d ,",array[i]);
	}
		PRINTF("\n");
#endif
}

void sort_array(unsigned char *array, unsigned int length) {
  unsigned int i, j;
  unsigned char tmp;
  for (i = 0; i + 1 < length; i++) {
    for (j = 0; j + 1 < length - i; j++) {
      if (array[j] < array[j + 1]) {
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

unsigned char find_median(unsigned char *array, unsigned int length) {
  unsigned int mid;
  if (length == 0) {
    return 0;
  }
  sort_array(array, length);
  mid = length / 2;
  if (length % 2 == 0) {
    return (unsigned char)(((unsigned int)array[mid - 1] + array[mid]) / 2);
  }
  return array[mid];
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
  unsigned int i, sum = 0;
  if (length == 0) {
    return 0;
  }
  for (i = 0; i < length; i++) {
    sum += array[i];
  }
  return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
  unsigned int i;
  unsigned char max;
  if (length == 0) {
    return 0;
  }
  max = array[0];
  for (i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
  unsigned int i;
  unsigned char min;
  if (length == 0) {
    return 0;
  }
  min = array[0];
  for (i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}
