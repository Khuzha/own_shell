/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 02:42:07 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 11:19:44 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int q)
{
	size_t			i;
	char	const	*to_ret;

	i = 0;
	to_ret = NULL;
	while (i <= ft_strlen(str))
	{
		if (str[i] == q)
		{
			to_ret = &str[i];
			return ((char *)to_ret);
		}
		i++;
	}
	return ((char *)to_ret);
}
