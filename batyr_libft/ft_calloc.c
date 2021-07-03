/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 04:07:38 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 07:06:36 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *to_ret;

	to_ret = NULL;
	to_ret = malloc(nmemb * size);
	if (!to_ret)
		return (NULL);
	ft_bzero(to_ret, nmemb * size);
	return (to_ret);
}
