#include "../headers/parse.h"

void print_pars_lst(t_parse_lst **lst)
{
	int i = 1;
	t_parse_lst *pars_tmp = *lst;
	t_args		*arg_temp;
	char *types[] = { "pipe","redir", "back_redir", "double redir", "double back", "none"};
	while (pars_tmp)
	{
		arg_temp = pars_tmp->args;
		printf("command = ||%s||     type = ||%s|| \n ", pars_tmp->command, types[pars_tmp->type_of_next_command]);
		while (arg_temp)
		{
			printf("%d arg = ||%s||\n", i, arg_temp->arg);
			arg_temp = arg_temp->next;
			i++;
		}
		pars_tmp = pars_tmp->next;
		printf("\n__________________\n");
		i = 1;
	}
}

void print_main_list(t_parse_lst *lst)
{
	int i = 0;
	int j = 0;
	while (lst)
	{
		while (lst->args)
		{
			printf("%s\n", lst->args->arg);
			lst->args = lst->args->next;
			j++;
		}
		lst = lst->next;
		i++;
		j = 0;
	}
}