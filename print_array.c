#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @ary_pr: Array to be printed
 * @siz: Total of elements in array
 */

void print_array(const int *ary_pr, size_t siz)
{
	size_t y;

	y = 0;
	while (ary_pr && y < siz)
	{
		if (y > 0)
			printf(", ");
		printf("%d", ary_pr[y]);
		++y;
	}
	printf("\n");
}