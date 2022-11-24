/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 12:00:16 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 21:03:35 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_setup(t_ps *a)
{
	int	i;
	int	swaps;

	swaps = 1;
	while (swaps != 0)
	{
		i = 0;
		swaps = 0;
		while (++i < a->size)
			if (a->stack[i - 1].value > a->stack[i].value)
				swaps += struct_swap(&a->stack[i - 1], &a->stack[i]);
	}
	i = -1;
	while (++i < a->size)
		a->stack[i].simp = i + 1;
	i = 0;
	while (++i < a->size)
		if (a->stack[i - 1].value == a->stack[i].value)
			a->error = 2;
	a->bitnum = a->stack[i - 1].simp;
}

void	parse_input(char **av, t_ps *a)
{
	long	*input;
	int		pos;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = -1;
	pos = 1;
	while (av[++i])
	{
		j = -1;
		input = atol_split(av[i], a, -1, -1);
		while (++j < a->len && x + 1 < a->alloc_size)
		{
			a->stack[++x].value = (int)input[j];
			a->stack[x].simp = a->stack[x].value;
			a->stack[x].pos = pos++;
			a->size++;
		}
		free (input);
	}
}

void	init_structs(t_ps *a, t_ps *b, int ac, char **av)
{
	int	i;
	int	alloc;
	int	nums;

	if (ac)
		alloc = 0;
	i = 0;
	alloc = 1;
	nums = 0;
	while (av[++i])
	{
		nums = count_nums(av[i], a);
		alloc += nums;
		if (nums == -1)
			ps_error();
	}
	if (alloc < 1)
		exit (1);
	a->alloc_size = alloc;
	a->stack = ft_calloc(sizeof(t_pair), alloc + 1);
	if (!a->stack)
		exit (1);
	b->stack = ft_calloc(sizeof(t_pair), alloc + 1);
	if (!b->stack)
		exit (1);
}

void	setup(t_ps *a, char **av)
{
	if (a->error != 0)
		ps_error();
	parse_input(av, a);
	if (a_is_sorted(a) == 1)
		exit (0);
	radix_setup(a);
	if (a->error != 0)
		ps_error();
	reset_pos(a);
}

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;

	if (ac < 2)
		exit (0);
	a = ft_calloc(1, sizeof(t_ps));
	b = ft_calloc(1, sizeof(t_ps));
	if (!a || !b)
		exit (1);
	init_structs(a, b, ac, av);
	setup(a, av);
	if (a->size == 2)
	{
		swap_a(a);
		exit(0);
	}
	if (a->size <= 2)
		sort_mini(a);
	if (a_is_sorted(a) == 1)
		exit (0);
	if (a->size <= 5)
		sort_small(a, b);
	if (a->size > 5)
		radix(a, b);
	return (0);
}
