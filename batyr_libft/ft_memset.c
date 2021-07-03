/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:59:54 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 07:13:59 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int q, size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = s;
	while (i < size)
	{
		mem[i] = (char)q;
		i++;
	}
	return (s);
}
