#include "../headers/parse.h"

void	init_arg_lst(t_args *args)
{
	if (!args)
		return ;
	args->next = NULL;
	args->previous = NULL;
	args->head = NULL;
	args->tail = NULL;
	args->arg = NULL;
}

void	init_lst(t_parse_lst *lst)
{
	if (!lst)
		return ;
	lst->head = NULL;
	lst->tail = NULL;
	lst->next = NULL;
	lst->previous = NULL;
	lst->args = NULL;
	lst->type_of_next_command = none;
	lst->exit_status = 0;
	lst->command = NULL;
}

