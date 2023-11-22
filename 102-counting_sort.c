#include "sort.h"

/**
 * get_greatest  - Get the limit value in an array of integers.
 * @ary: An array of integers.
 * @siz: Size of the array.
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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @ary:array of integers.
 * @siz: Size of the array.
 * Description: Prints the counting array after setting it ASCENDING.
 */

void counting_sort(int *ary, size_t siz)
{
	int *cast_up, *resolved, limit, y;

	if (ary == NULL || siz < 2)
		return;

	resolved = malloc(sizeof(int) * siz);
	if (resolved == NULL)
		return;
	limit = get_greatest(ary, siz);
	cast_up = malloc(sizeof(int) * (limit + 1));
	if (cast_up == NULL)
	{
		free(resolved);
		return;
	}

	for (y = 0; y < (limit + 1); y++)
		cast_up[y] = 0;
	for (y = 0; y < (int)siz; y++)
		cast_up[ary[y]] += 1;
	for (y = 0; y < (limit + 1); y++)
		cast_up[y] += cast_up[y - 1];
	print_aryay(cast_up, limit + 1);

	for (y = 0; y < (int)siz; y++)
	{
		resolved[cast_up[ary[y]] - 1] = ary[y];
		cast_up[ary[y]] -= 1;
	}

	for (y = 0; y < (int)siz; y++)
		ary[y] = resolved[y];

	free(resolved);
	free(cast_up);
}