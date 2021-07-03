/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 03:21:41 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 11:28:52 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *where, const char *what, size_t size)
{
	size_t	i;
	char	word[size];
	char	temp[ft_strlen(what)];

	ft_strlcpy(word, (char*)where, size + 1);
	ft_strlen(where);
	i = 0;
	while (i <= ft_strlen(word))
	{
		ft_strlcpy(temp, &word[i], ft_strlen(what) + 1);
		if (ft_strcmp(temp, what) == 0)
			return ((char *)&where[i]);
		i++;
	}
	return (NULL);
}
