/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:20:51 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 23:02:01 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*to_ret;
	int					size;
	unsigned int		i;

	size = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[size] != '\0')
		size++;
	to_ret = malloc((len + 1) * sizeof(char));
	if (!to_ret)
		return (NULL);
	else
	{
		while (start < (size_t)size && i < len)
		{
			to_ret[i] = s[start];
			start++;
			i++;
		}
		to_ret[i] = '\0';
	}
	return (to_ret);
}
