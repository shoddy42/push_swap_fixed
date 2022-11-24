/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 17:12:36 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 15:05:24 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// //  shift up all elements of stack a by 1.
// //  The first element becomes the last one.

void	rotate_a(t_ps *a)
{
	int		i;
	t_pair	tmp;

	i = -1;
	tmp = a->stack[0];
	while (++i < a->size - 1)
		a->stack[i] = a->stack[i + 1];
	a->stack[a->size -1] = tmp;
	write (1, "ra\n", 3);
}

// //  shift up all elements of stack b by 1.
// //  The first element becomes the last one.

void	rotate_b(t_ps *b)
{
	int		i;
	t_pair	tmp;

	i = -1;
	tmp = b->stack[0];
	while (++i < b->size - 1)
		b->stack[i] = b->stack[i + 1];
	b->stack[b->size - 1] = tmp;
	write (1, "rb\n", 3);
}

void	rotate_both(t_ps *a, t_ps *b)
{
	rotate_a(a);
	rotate_b(b);
}
