#include "../headers/parse.h"

int fill_lst(char *str, t_parse_lst *pars_lst)
{
	t_deviders  *dev_lst;
	t_deviders  *temp;
	t_parse_lst *current_pars;
	t_args      *new_args;
	t_parse_lst *new_pars;
	char        **command_params;

	dev_lst = get_deviders_list(str);
	current_pars = pars_lst;
	command_params = NULL;
	while (dev_lst)
	{
		new_pars = malloc(sizeof(t_parse_lst));
		init_lst(new_pars);
		ft_shell_lst_add_back(pars_lst, new_pars);
		temp = dev_lst;
		str[dev_lst->pos_in_str] = '\0';
		command_params = split_out_quotes(str, ' ');
		if (dev_lst->type == double_redir_is_next)
			str = &str[dev_lst->pos_in_str + 2];
		else
			str = &str[dev_lst->pos_in_str + 1];
		current_pars->command = *command_params;
		current_pars->type_of_next_command = dev_lst->type;
		command_params++;
		while (*command_params)
		{
			new_args = malloc(sizeof(t_args));
			new_args->arg = *command_params;
			ft_args_lst_add_back(current_pars, new_args);
			command_params++;
		}
		dev_lst  = dev_lst->next;
		current_pars = current_pars->next;
		free(temp);
	}
	command_params = split_out_quotes(str, ' ');
	current_pars->command = *command_params;
	command_params++;
	while (*command_params)
	{
		new_args = malloc(sizeof(t_args));
		new_args->arg = *command_params;
		ft_args_lst_add_back(current_pars, new_args);
		command_params++;
	}

	return (1);
}