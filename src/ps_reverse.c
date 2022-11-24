/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_reverse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 17:14:24 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 15:05:24 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//  shift down all elements of stack a by 1.
//  The last element becomes the first one.

void	reverse_rotate_a(t_ps *a)
{
	int		i;
	t_pair	tmp;

	i = a->size;
	tmp = a->stack[a->size - 1];
	while (--i > 0)
		a->stack[i] = a->stack[i - 1];
	a->stack[0] = tmp;
	write (1, "rra\n", 4);
}

//  shift down all elements of stack b by 1.
//  The last element becomes the first one.

void	reverse_rotate_b(t_ps *b)
{
	int		i;
	t_pair	tmp;

	i = b->size;
	tmp = b->stack[b->size - 1];
	while (--i > 0)
		b->stack[i] = b->stack[i - 1];
	b->stack[0] = tmp;
	write (1, "rrb\n", 4);
}

void	reverse_rotate_both(t_ps *a, t_ps *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
