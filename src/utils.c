/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:05:06 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 21:02:56 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	struct_swap(t_pair *one, t_pair *two)
{
	t_pair	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
	return (1);
}

int	numlen_base2(long num)
{
	int	bits;

	bits = 0;
	if (num < 0 || num > 2147483647)
		return (42);
	while (num >> bits != 0)
		bits++;
	return (bits);
}

void	reset_pos(t_ps *a)
{
	int	i;
	int	swaps;

	swaps = 1;
	while (swaps != 0)
	{
		i = 0;
		swaps = 0;
		while (++i < a->size)
			if (a->stack[i - 1].pos > a->stack[i].pos)
				swaps += struct_swap(&a->stack[i - 1], &a->stack[i]);
	}
}
