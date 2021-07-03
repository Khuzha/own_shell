/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:55:41 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 11:25:42 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*mdst;
	unsigned char	*msrc;

	i = 0;
	msrc = (unsigned char*)src;
	mdst = (unsigned char*)dst;
	if (mdst == NULL && msrc == NULL)
		return (NULL);
	while (i < (int)n)
	{
		mdst[i] = msrc[i];
		i++;
	}
	return (dst);
}
