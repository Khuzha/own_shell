/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:06:37 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 23:39:21 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp_next;

	size = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		temp_next = lst->next;
		lst = temp_next;
		size++;
	}
	return (size);
}
