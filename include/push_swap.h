/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:10:12 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 21:04:09 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_pair
{
	int	value;
	int	simp;
	int	pos;
}	t_pair;

typedef struct s_ps
{
	t_pair	*stack;

	int		size;
	int		alloc_size;
	int		maxnum;
	int		bitnum;
	int		error;
	int		skip;
	int		len;
}	t_ps;

/****************************\
      PUSH SWAP FUNCTIONS
\****************************/

int		a_is_sorted(t_ps *a);
int		struct_swap(t_pair *one, t_pair *two);
void	sort_small(t_ps *a, t_ps *b);
void	sort_mini(t_ps *a);

int		count_nums(char *input, t_ps *a);
int		numlen_base2(long num);
long	*atol_split(char *input, t_ps *a, int i, int j);
long	ps_atol(const char *nb, t_ps *a);
void	init_structs(t_ps *a, t_ps *b, int ac, char **av);
void	radix(t_ps *a, t_ps *b);
void	reset_pos(t_ps *a);
void	ps_error(void);

/****************************\
  	PUSH_SWAP INSTRUCTIONS
\****************************/

void	swap_a(t_ps *a);
void	swap_b(t_ps *b);
void	swap_both(t_ps *a, t_ps *b);
void	push_a(t_ps *a, t_ps *b);
void	push_b(t_ps *a, t_ps *b);

void	rotate_a(t_ps *a);
void	rotate_b(t_ps *b);
void	rotate_both(t_ps *a, t_ps *b);

void	reverse_rotate_a(t_ps *a);
void	reverse_rotate_b(t_ps *b);
void	reverse_rotate_both(t_ps *a, t_ps *b);

#endif