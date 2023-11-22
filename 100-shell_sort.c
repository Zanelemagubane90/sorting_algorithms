#include "sort.h"

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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @ary_int: Array of integers.
 * @siz: Size of the array.
 * Description: Uses Knuth interval sequence.
 */

void shell_sort(int *ary_int, size_t siz)
{
	size_t xy, z, y;

	if (ary_int == NULL || siz < 2)
		return;

	for (xy = 1; xy < (siz / 3);)
		xy = xy * 3 + 1;

	for (; xy >= 1; xy /= 3)
	{
		for (z = xy; z < siz; z++)
		{
			y = z;
			while (y >= xy && ary_int[y - xy] > ary_int[y])
			{
				exchange_ints(ary_int + y, ary_int + (y - xy));
				y -= xy;
			}
		}
		print_array(ary_int, siz);
	}
}