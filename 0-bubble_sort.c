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
 * bubble_sort - Sort an array of integers in ascending order.
 * @int_ary: Array of integers to be sort.
 * @siz: Size of the array.
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *int_ary, size_t siz)
{
	size_t x, bub = siz;
	bool xava = false;

	if (int_ary == NULL || siz < 2)
		return;

	while (xava == false)
	{
		xava = true;
		for (x = 0; x < bub - 1; x++)
		{
			if (int_ary[x] > int_ary[x + 1])
			{
				exchange_ints(int_ary + x, int_ary + x + 1);
				print_array(int_ary, siz);
				xava = false;
			}
		}
		bub--;
	}
}
