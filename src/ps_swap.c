/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:15:11 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 16:11:44 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// //  take the first element at the top of a and put it at the top of b.
// //  Do nothing if a is empty

void	push_b(t_ps *a, t_ps *b)
{
	int		i;
	t_pair	tmp;

	if (a->size <= 0)
		exit (1);
	i = b->size + 1;
	tmp = b->stack[0];
	while (--i >= 0)
	{
		b->stack[i + 1] = b->stack[i];
	}
	b->stack[i] = tmp;
	b->stack[0] = a->stack[0];
	b->size++;
	i = -1;
	while (++i <= a->size)
		a->stack[i] = a->stack[i + 1];
	a->size--;
	write (1, "pb\n", 3);
}

// //  take the first element at the top of b and put it at the top of a.
// //  Do nothing if b is empty

void	push_a(t_ps *a, t_ps *b)
{
	int		i;
	t_pair	tmp;

	if (b->size <= 0)
		exit (1);
	i = a->size + 1;
	tmp = a->stack[0];
	while (--i >= 0)
		a->stack[i + 1] = a->stack[i];
	if (i == -1)
		i = 0;
	a->stack[i] = tmp;
	a->stack[0] = b->stack[0];
	a->size++;
	i = -1;
	while (++i <= b->size)
		b->stack[i] = b->stack[i + 1];
	b->size--;
	write (1, "pa\n", 3);
}

//  swap the first 2 elements at the top of stack a. 
//  Do nothing if there is only one or no elements

void	swap_a(t_ps *a)
{
	t_pair	tmp;

	tmp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = tmp;
	write (1, "sa\n", 3);
}

//  swap the first 2 elements at the top of stack b.
//  Do nothing if there is only one or no elements)

void	swap_b(t_ps *b)
{
	t_pair	tmp;

	tmp = b->stack[0];
	b->stack[0] = b->stack[1];
	b->stack[1] = tmp;
	write(1, "sb\n", 3);
}

// swap a + swap b at the same time

void	swap_both(t_ps *a, t_ps *b)
{
	swap_a(a);
	swap_b(b);
}
