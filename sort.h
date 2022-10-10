#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_2(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void merge_sort(int *array, size_t size);
void mergeSort(int *array, int start, int end, int *temp_array);
void merge(int *array, int start, int mid, int end, int *temp_array);
void print_half(int *array, int start, int end);
void heap_sort(int *a, size_t size);
void heapify(int *a, int size, int p, int len);
void swap(int *x, int *y);
void radix_sort(int *array, size_t size);
int get_max_int(int *array, size_t size);

#endif
