#include "sort.h"

int get_greatest(int *ary_int, int siz);
void a_counting_sort(int *ary_int, size_t siz, int sg, int *bff_r);
void radix_sort(int *ary_int, size_t siz);

/**
 * get_greatest - Get the maximum value in an array of integers.
 * @ary: an array of integers.
 * @siz: The size of the array.
 * Return: The maximum integer in the array.
 */

int get_greatest(int *ary, int siz)
{
	int limit, y;

	for (limit = ary[0], y = 1; y < siz; y++)
	{
		if (ary[y] > limit)
			limit = ary[y];
	}

	return (limit);
}

/**
 * a_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @ary_int: an array of integers.
 * @siz: The siz of the array.
 * @sg: The significant digit to sort on.
 * @bff_r: A buffer to store the sorted ary_int.
 */

void a_counting_sort(int *ary_int, size_t siz, int sg, int *bff_r)
{
	int toll[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < siz; x++)
		toll[(ary_int[x] / sg) % 10] += 1;

	for (x = 0; x < 10; x++)
		toll[x] += toll[x - 1];

	for (x = siz - 1; (int)x >= 0; x--)
	{
		bff_r[toll[(ary_int[x] / sg) % 10] - 1] = ary_int[x];
		toll[(ary_int[x] / sg) % 10] -= 1;
	}

	for (x = 0; x < siz; x++)
		ary_int[x] = bff_r[x];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @ary_int: an array of integers.
 * @siz: The siz of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */

void radix_sort(int *ary_int, size_t siz)
{
	int lmt, sg, *bff_r;

	if (ary_int == NULL || siz < 2)
		return;

	bff_r = malloc(sizeof(int) * siz);
	if (bff_r == NULL)
		return;

	lmt = get_greatest(ary_int, siz);
	for (sg = 1; lmt / sg > 0; sg *= 10)
	{
		a_counting_sort(ary_int, siz, sg, bff_r);
		print_array(ary_int, siz);
	}

	free(bff_r);
}