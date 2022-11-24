/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 17:27:01 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 21:03:14 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	a_is_sorted(t_ps *a)
{
	int	i;

	i = 0;
	if (a->error != 0)
		ps_error();
	if (a->size == 1)
		return (1);
	while (++i < a->size)
	{
		if (a->stack[i - 1].value == a->stack[i].value)
			ps_error();
		if (a->stack[i - 1].simp > a->stack[i].simp)
			return (0);
	}
	return (1);
}

void	sort_mini(t_ps *a)
{
	if (a->stack[0].simp > a->stack[1].simp
		&& a->stack[1].simp > a->stack[2].simp)
		swap_a(a);
	if (a->stack[1].simp > a->stack[2].simp
		&& a->stack[2].simp > a->stack[0].simp)
		reverse_rotate_a(a);
	else if (a->stack[2].simp > a->stack[0].simp
		&& a->stack[0].simp > a->stack[1].simp)
		swap_a(a);
	else if (a->stack[1].simp > a->stack[0].simp
		&& a->stack[0].simp > a->stack[2].simp)
		reverse_rotate_a(a);
	else if (a->stack[0].simp > a->stack[2].simp
		&& a->stack[2].simp > a->stack[1].simp)
		rotate_a(a);
	if (a->stack[0].simp > a->stack[1].simp)
		swap_a(a);
}

void	sort_small(t_ps *a, t_ps *b)
{
	int	last;

	last = a->size;
	while (a->size > 3)
	{
		if (a->stack[0].simp == 1 || a->stack[0].simp == 2)
			push_b(a, b);
		else
			rotate_a(a);
	}
	sort_mini(a);
	while (b->size > 0)
	{
		push_a(a, b);
		if (a->stack[0].simp == last)
			rotate_a(a);
	}
	if (a->stack[0].simp == 2)
		swap_a(a);
}

void	radix(t_ps *a, t_ps *b)
{
	int		i;
	int		bit;
	int		maxbit;

	bit = 0;
	maxbit = numlen_base2(a->bitnum);
	while (bit < maxbit)
	{
		i = -1;
		while (++i < a->size)
		{
			if (((a->stack[0].simp >> bit) & 1) == 1)
				rotate_a(a);
			else
			{
				push_b(a, b);
				i--;
			}
		}
		while (b->size > 0)
			push_a(a, b);
		bit++;
	}
}
