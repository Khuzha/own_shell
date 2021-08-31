/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:55:22 by zskeeter          #+#    #+#             */
/*   Updated: 2021/04/25 13:55:23 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_tolower(int c)
{
	return ((c >= 65 && c <= 90) ? c + 32 : c);
}