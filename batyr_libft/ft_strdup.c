/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:12:49 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 06:56:31 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*to_ret;

	size = ft_strlen(str);
	to_ret = malloc(size + 1 * sizeof(char));
	if (!to_ret)
		return (NULL);
	ft_strlcpy(to_ret, str, size + 1);
	return (to_ret);
}
