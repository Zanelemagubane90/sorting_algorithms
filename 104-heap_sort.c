#include "sort.h"

void exchange_ints(int *first, int *second);
void greatest_heap(int *ary_int, size_t siz, size_t min, size_t a_root);
void heap_sort(int *ary_int, size_t siz);

/**
 * exchange_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */

void exchange_ints(int *first, int *second)
{
	int impermanent;

	impermanent = *first;
	*first = *second;
	*second = impermanent;
}

/**
 * greatest_heap - Turn a binary tree into a complete binary heap.
 * @ary_int: an array of integers representing a binary tree.
 * @siz: Size of the array/tree.
 * @min: The index of the min row of the tree.
 * @a_root: The root node of the binary tree.
 */

void greatest_heap(int *ary_int, size_t siz, size_t min, size_t a_root)
{
	size_t s_left, s_right, s_large;

	s_left = 2 * a_root + 1;
	s_right = 2 * a_root + 2;
	s_large = a_root;

	if (s_left < min && ary_int[s_left] > ary_int[s_large])
		s_large = s_left;
	if (s_right < min && ary_int[s_right] > ary_int[s_large])
		s_large = s_right;

	if (s_large != a_root)
	{
		exchange_ints(ary_int + a_root, ary_int + s_large);
		print_array(ary_int, siz);
		greatest_heap(ary_int, siz, min, s_large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @ary_int: an array of integers.
 * @siz: Size of the array.
 * Description: Implements the sift-DESCENDING heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *ary_int, size_t siz)
{
	int x;

	if (ary_int == NULL || siz < 2)
		return;

	for (x = (siz / 2) - 1; x >= 0; x--)
		greatest_heap(ary_int, siz, siz, x);

	for (x = siz - 1; x > 0; x--)
	{
		exchange_ints(ary_int, ary_int + x);
		print_array(ary_int, siz);
		greatest_heap(ary_int, siz, x, 0);
	}
}