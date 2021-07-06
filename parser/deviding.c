#include "../headers/parse.h"

void	tmp(t_parse_lst *current_pars, char **command_params,\
	t_deviders *dev_lst, t_found prev_type)
{
	t_args      *new_args;

	if (!dev_lst)
	{
		current_pars->command = *command_params;
		command_params++;
	}
	else if (prev_type == none || prev_type == pipe_is_next)
	{
		current_pars->command = *command_params;
		command_params++;
	}
	else
	{
		current_pars->file_fd = get_redir_fd(dev_lst->type, current_pars,\
			current_pars->command);
		command_params++;
	}
	while (*command_params)
	{
		new_args = init_arg_lst();
		new_args->arg = *command_params;
		ft_args_lst_add_back(current_pars, new_args);
		command_params++;
	}
}

char	*cut_str_by_devider(char *str, t_deviders *dev_lst, char ***command_params,\
	t_parse_lst *pars_lst)
{
	t_parse_lst *new_pars;
	str[dev_lst->pos_in_str] = '\0';
	*command_params = split_out_quotes(str, ' ');
	new_pars = init_pars_lst();
	ft_shell_lst_add_back(pars_lst, new_pars);
	if (new_pars->previous)
		new_pars->previous->type_of_next_command = dev_lst->type;
	if (dev_lst->type == double_redir_is_next)
		return (&str[dev_lst->pos_in_str + 2]);
	else
		return (&str[dev_lst->pos_in_str + 1]);
}

int fill_lst(char *str, t_parse_lst *pars_lst)
{
	t_deviders  *dev_lst;
	t_deviders  *temp;
	t_parse_lst *current_pars;
	char        **command_params;
	t_found		prev_type;

	command_params = NULL;
	dev_lst = get_deviders_list(str);
	current_pars = pars_lst;
	prev_type = none;
	while (dev_lst)
	{
		str = cut_str_by_devider(str, dev_lst, &command_params, pars_lst);
		temp = dev_lst;
		tmp(current_pars, command_params, dev_lst, prev_type);
		if (dev_lst->type == none || dev_lst->type == pipe_is_next)
			current_pars = current_pars->tail;
		if (current_pars->previous)
			prev_type = (current_pars->previous)->type_of_next_command;
		dev_lst  = dev_lst->next;
		free(temp);
	}
	command_params = split_out_quotes(str, ' ');
	tmp(current_pars, command_params, dev_lst, prev_type);

	return (1);
}