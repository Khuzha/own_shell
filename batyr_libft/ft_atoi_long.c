/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:48:38 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 20:07:23 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sym(char q, int *sym)
{
	if (q == '-' || q == '+')
	{
		*sym += 1;
		return (1);
	}
	else
		return (0);
}

static int		enter(char q, int *sym, int to_ret)
{
	if (ft_isdigit(q) || (to_ret == 0 && (is_sym(q, sym) || ft_space(q))))
		return (1);
	else
		return (0);
}

long long int	ft_atoi_long(const char *str)
{
	long long int	to_ret;
	int				min;
	int				i;
	int				sym;

	to_ret = 0;
	min = 0;
	sym = 0;
	i = 0;
	while (enter(str[i], &sym, to_ret) && sym < 2)
	{
		if (str[i] == '-')
			min++;
		if (ft_isdigit((int)str[i]) == 1)
			to_ret = (to_ret * 10) + ((int)str[i] - 48);
		if ((i > 18 && min > 0))
			return (0);
		else if (i++ > 18)
			return (-1);
	}
	if (min > 0)
		return (to_ret * -1);
	return (to_ret);
}
