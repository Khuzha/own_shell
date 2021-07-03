/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:42:38 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 23:04:29 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check(const char *set, char q)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (q == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *str, char const *set)
{
	int		pos;
	int		start;
	int		size;
	char	*to_ret;

	if (!str || !set)
		return (NULL);
	start = 0;
	pos = 0;
	size = ft_strlen(str) - 1;
	if (size == 0)
		return ("");
	while (check(set, str[start]))
		start++;
	while (check(set, str[size]) && size > start)
		size--;
	to_ret = malloc((size - start + 2) * sizeof(char));
	if (!to_ret)
		return (NULL);
	while (start <= size)
		to_ret[pos++] = str[start++];
	to_ret[pos] = '\0';
	return (to_ret);
}
