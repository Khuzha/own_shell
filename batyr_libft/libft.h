/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:38:52 by bdomitil          #+#    #+#             */
/*   Updated: 2021/05/02 15:42:03 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char			**ft_split(const char *str, char c);
char			*ft_substr(const char *str, unsigned int start, size_t len);
char			*ft_strtrim(const char *str, const char *set);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strchr(const char *str, int q);
char			*ft_strrchr(const char *str, int q);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *dst, const char *what, size_t size);
char			*ft_strdup(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int q);
int				ft_isalpha(int q);
int				ft_isupper(int q);
int				ft_islower(int q);
int				ft_isprint(int q);
int				ft_space(int q);
int				ft_isascii(int q);
int				ft_isalnum(int q);
int				ft_toupper(int q);
int				ft_tolower(int q);
int				ft_atoi(const char *str);
int				ft_char_index(const char *str, char q);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void(*del)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void(*del)(void*));
int				ft_lstsize(t_list *lst);
void			ft_lstprint_bonus(t_list **lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				get_next_line(int fd, char **line);
int				ft_isempty_str(char *str);
long long int	ft_atoi_long(const char *str);
int				ft_all_numeric(char *str);
char			*ft_strcpy(char *dst, char *src);

#endif
