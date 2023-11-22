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
 * selection_sort - Sort an array of integers in ascending order.
 * @ints_ary: Array of integers.
 * @siz: Size of the array.
 * Description: Prints the ints_arr after each swap.
 */

void selection_sort(int *ints_ary, size_t siz)
{
	int *asd;
	size_t z, y;

	if (ints_ary == NULL || siz < 2)
		return;

	for (z = 0; z < siz - 1; z++)
	{
		asd = ints_ary + z;
		for (y = z + 1; y < siz; y++)
			asd = (ints_ary[y] < *asd) ? (ints_ary + y) : asd;

		if ((ints_ary + z) != asd)
		{
			exchange_ints(ints_ary + z, asd);
			print_array(ints_ary, siz);
		}
	}
}