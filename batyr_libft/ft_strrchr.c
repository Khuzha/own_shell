/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 02:42:07 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 07:01:32 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int q)
{
	int				i;
	char	const	*to_ret;

	i = ft_strlen(str);
	to_ret = NULL;
	while (i >= 0)
	{
		if (str[i] == q)
		{
			to_ret = &str[i];
			return ((char *)to_ret);
		}
		i--;
	}
	return ((char *)to_ret);
}
