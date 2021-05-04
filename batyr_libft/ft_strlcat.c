/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 01:51:42 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/18 18:29:59 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dpos;
	size_t	spos;
	size_t	res;

	i = 0;
	dpos = ft_strlen(dst);
	spos = ft_strlen(src);
	if (size < ft_strlen(dst))
		res = size + spos;
	else
		res = spos + dpos;
	while (src[i] != '\0' && dpos + 1 < size)
	{
		dst[dpos] = src[i];
		i++;
		dpos++;
	}
	dst[dpos] = '\0';
	return (res);
}
