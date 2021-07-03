/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:02:29 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 12:08:26 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f) (unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*to_ret;

	if (!str || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	to_ret = malloc(size * sizeof(char) + 1);
	if (!to_ret)
		return (NULL);
	while (str[i] != '\0')
	{
		to_ret[i] = f(i, str[i]);
		i++;
	}
	to_ret[i] = '\0';
	return (to_ret);
}
