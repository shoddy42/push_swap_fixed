/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atol_split.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 21:22:56 by wkonings      #+#    #+#                 */
/*   Updated: 2022/11/24 21:03:23 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_nums(char *str, t_ps *a)
{
	int	nums;
	int	i;

	if (ft_strcontains(str, "1234567890") == false)
		ps_error();
	i = 0;
	nums = 0;
	str[ft_strlen(str)] = '\0';
	while (str[i] && a->error == 0)
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] && (str[i] < '0' || str[i] > '9'))
			if (str[i] && str[i] != '-' && str[i] != '+')
				ps_error();
		if (str[i] && ((str[i] >= '0' && str[i] <= '9') || \
			str[i] == '-' || str[i] == '+'))
		{
			nums++;
			i++;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
		}
	}
	return (nums);
}

long	ps_atol(const char *nb, t_ps *a)
{
	long	r;
	int		i;
	int		sign;

	i = 0;
	r = 0;
	sign = 1;
	while (ft_isspace(nb[i]))
		i++;
	if (nb[i] == '-')
		sign = -1;
	if (nb[i] == '-' || nb[i] == '+')
		if (!(nb[++i] >= '0' && nb[i] <= '9'))
			a->error = 92;
	while (nb[i] >= '0' && nb[i] <= '9')
		r = (r * 10) + (nb[i++] - '0');
	a->skip = i + 1;
	if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '\0' && ft_isspace(nb[i] == 0))
		a->error = 7;
	if (numlen_base2(r) > 31 && r * sign != -2147483648)
		a->error = 12;
	return (r * sign);
}

long	*atol_split(char *input, t_ps *a, int i, int j)
{
	long	*ret;
	int		nums;
	int		len;

	nums = count_nums(input, a);
	ret = ft_calloc(nums + 1, sizeof(int));
	if (!ret)
		a->error = 1;
	len = ft_strlen(input);
	while (++i < len && j + 1 < nums)
	{
		ret[++j] = ps_atol(&*(input + i), a);
		if (ret[j] > INT_MAX || ret[j] < INT_MIN)
			a->error = 3;
		while (*(input + i) && a->skip-- > 1)
			i++;
		if (!(*(input + i) >= '0' && *(input + i) <= '9'))
			if (ft_isspace(*(input + i)) == 0 && *(input + i) != '\0')
				a->error = 42;
	}
	a->len = j + 1;
	return (ret);
}
