#ifndef __LEXI__
#define __LEXI__

#include "../inc/fillit.h"

#endif

int		next_lexicorder(int *order, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = n - 1;
	while (i > 0 && order[i - 1] >= order[i])
		i--;
	if (i == 0)
		return (0);
	j = n - 1;
	while (order[j] <= order[i - 1])
		j--;
	ft_swap(&order[i - 1], &order[j]);
	while (i < n--)
		ft_swap(&order[i++], &order[n]);
	return (1);
}
