#include "../headers/parse.h"

void	ft_shell_lst_add_back(t_parse_lst *lst, t_parse_lst *new)
{
	if (!lst->next)
	{
		lst->next = new;
		lst->head = lst;
		lst->tail = new;
		return ;
	}
	new->head = lst;
 	while (lst->next)
	{
		lst->tail = new;
		lst = lst->next;
	}
	new->previous = lst;
	lst->tail = new;
	lst->next = new;
	return ;
}

void	ft_args_lst_add_back(t_args *lst, t_args *new)
{
		if (!lst->next)
	{
		lst->next = new;
		lst->head = lst;
		lst->tail = new;
		return ;
	}
	new->head = lst;
 	while (lst->next)
	{
		lst->tail = new;
		lst = lst->next;
	}
	new->previous = lst;
	lst->tail = new;
	lst->next = new;
	return ;
}