#include "sort.h"
#include "stdio.h"

/**
 * count_sort - sorts given array using Count Sort algorithm
 * @array: original array
 * @temp_arr: array to be sorted
 * @size: size of the array
 * @place: the place of the significant digit being sorted
 * Return: the newly sorted temp_arr
 */
int *count_sort(int *array, int *temp_arr, int size, int place)
{
	int y, z, num, min = 0;
	int *count_arr;

	count_arr = malloc(sizeof(int) * 10);
	if (!count_arr)
		return (temp_arr);
	/* set count_arr to all 0 */
	for (y = 0; y < 10; y++)
		count_arr[y] = 0;
	/* moves through array and increments the positions of count_arr */
	/* for each significant digit found */
	for (y = 0; y < size; y++)
	{
		num = (array[y] / place) % 10;
		count_arr[num]++;
	}
	/* finds cumulative frequency of significant digits */
	for (y = 1; y < 10; y++)
		count_arr[y] += count_arr[y - 1];
	/* fixes values into the temp_arr */
	for (z = (size - 1); z >= min; z--)
	{
		num = (array[z] / place) % 10;
		temp_arr[count_arr[num] - 1] = array[z];
		count_arr[num]--;
	}
	free(count_arr);
	return (temp_arr);
}

/**
 * radix_sort - sorts given array based on Least Significant Digit version
 *              of Radix Sort algorithm.
 * @array: pointer to the array to be sorted.
 * @size: size of the array to be sorted.
 */
void radix_sort(int *array, size_t size)
{
	size_t x, y, n_dig;
	int place, max;
	int *temp_arr;

	if (!array || size < 2)
		return;
	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
		return;
	/* find the maximum number in the elements of the array */
	max = array[0];
	for (x = 1; x < size; x++)
	{
		if (max < array[x])
			max = array[x];
	}
	/* find the number of significant digits in max */
	n_dig = 0;
	while (max > 0)
	{
		n_dig++;
		max /= 10;
	}
	/* set value for current place of digit */
	place = 1;
	/* starting with LSD, sort each element */
	for (x = 0; x < n_dig; x++)
	{
		/* using Counting Sort algorithm to set element positions */
		/* for current place */
		count_sort(array, temp_arr, size, place);
		/* update array to the current sort */
		for (y = 0; y < size; y++)
			array[y] = temp_arr[y];
		/* print the array and update place variable */
		print_array(array, size);
		place *= 10;
	}
	free(temp_arr);
}
