/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:38:11 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 20:03:26 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != EOF)
		i++;
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, int len)
{
	char				*to_ret;
	int					size;
	int					i;

	size = 0;
	if (len < 0)
		len = gnl_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[size] != '\0')
		size++;
	to_ret = malloc(len * sizeof(char) + 1);
	if (!to_ret)
		return (NULL);
	while (start < (size_t)size && i < len)
	{
		to_ret[i] = s[start];
		start++;
		i++;
	}
	to_ret[i] = '\0';
	return (to_ret);
}

int		ft_slash(char *str)
{
	unsigned long long i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		pos;
	char	*to_ret;

	i = 0;
	pos = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	to_ret = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!to_ret)
		return (NULL);
	else
	{
		while (s1 != NULL && s1[i] != '\0' && s1[i] != EOF)
			to_ret[pos++] = s1[i++];
		i = 0;
		while (s2 != NULL && s2[i] != '\0' && s2[i] != EOF)
		{
			to_ret[pos] = s2[i++];
			pos++;
		}
		to_ret[pos] = '\0';
	}
	return (to_ret);
}
