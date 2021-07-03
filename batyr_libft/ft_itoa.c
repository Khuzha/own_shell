/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:06:12 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/18 18:06:01 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n, int *minus)
{
	size_t size;

	if (n == 0)
		return (1);
	if (n < 0)
		*minus = 1;
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*to_ret;
	size_t	size;
	int		minus;

	if (n == -2147483648)
		return ((to_ret = ft_strdup("-2147483648")));
	minus = 0;
	size = count_len(n, &minus);
	to_ret = malloc(size * sizeof(char) + 1 + minus);
	if (!to_ret)
		return (NULL);
	if (minus)
	{
		n *= -1;
		to_ret[0] = '-';
	}
	to_ret[size + minus] = '\0';
	while (size > 0)
	{
		to_ret[size - !minus] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (to_ret);
}
