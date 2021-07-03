/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:52:30 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/25 16:51:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "libft.h"
# include <fcntl.h>

int		ft_slash(char *str);
char	*gnl_substr(char const *s, unsigned int start, int len);
char	*gnl_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
size_t	gnl_strlen(const char *str);

#endif
