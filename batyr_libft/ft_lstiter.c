/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:45:28 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/09 15:11:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list *temp;
	t_list *buff;

	if (lst == NULL)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		buff = temp->next;
		f(temp->content);
		temp = buff;
	}
	return ;
}
