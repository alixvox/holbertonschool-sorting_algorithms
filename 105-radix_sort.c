#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts and returns an array of ints using the radix sort method.
 *
 * @array: A pointer to the array to be sorted.
 * @size: The size_t size of the array.
 */

void radix_sort(int *array, size_t size)
{
  int max = get_max_int(array, size);
  int *output;
  int *count;
  int maxPos, i, pos;

  for (pos = 1; max / pos > 0; pos *= 10)
  {
    output = malloc((size + 1) * sizeof(int));
    maxPos = (array[0] / pos) % 10;

    for (i = 1; i < (int)size; i++)
      if (((array[i] / pos) % 10) > maxPos)
        maxPos = array[i];

    count = malloc((max + 1) * sizeof(int));
    for (i = 0; i < maxPos; ++i)
      count[i] = 0;
    for (i = 1; i < (int)size; i++)
      count[(array[i] / pos) % 10]++;

    for (i = 1; i < 10; i++)
      count[i] += count[i - 1];

    for (i = (int)size; i >= 0; i--)
    {
      output[count[(array[i] / pos) % 10] - 1] = array[i];
      count[(array[i] / pos) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
      array[i] = output[i];

    print_array(array, size);

    free(output);
    free(count);
  }
}

/**
 * get_max_int - Get the max int object
 *
 * @array: The int array to be skimmed
 * @size: The size of array
 * Return: The max int object
 */
int get_max_int(int *array, size_t size)
{
  int max = 0;
  int i;
  for (i = 0; i < (int)size; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
