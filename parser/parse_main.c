#include "../headers/parse.h"

void print_pars_lst(t_parse_lst *lst)
{
	int i = 1;
	t_parse_lst *pars_tmp = lst;
	t_args  *arg_temp;
	char *types[] = {"redir", "pipe", "back_redir", "double redir", "comma_point", "none"};

	printf("print_pars_lst\n");
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

int	parse_str(char **str, t_parse_lst *pars_lst)
{
	
	if (not_ending_string(str) == false)
	{
		printf("syntax error: unexpected end of file\n");
		return (-1);
	}
	*str = relese_quoutes(*str, pars_lst);
	return (1);
}

int parser(char **str, t_parse_lst **pars_lst)
{
	t_parse_lst *pars_tmp;
	t_args		*args_tmp;
	if (!*pars_lst)
		*pars_lst = malloc(sizeof(t_parse_lst));
	if (!*pars_lst)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}

	if (not_ending_string(str) == false)
	{
		printf("syntax error: unexpected end of file\n");
		return (-1);
	}
	init_lst(*pars_lst);
	fill_lst(*str, *pars_lst);
	pars_tmp = *pars_lst;
	args_tmp = pars_tmp->args;

	while (pars_tmp)
	{
		
		if (parse_str(&pars_tmp->command, pars_tmp) == -1)
			return (-1);
		while (args_tmp != NULL)
		{
			if (parse_str(&args_tmp->arg, pars_tmp) == -1)
				return (-1);
			args_tmp = args_tmp->next;
		}
		pars_tmp = pars_tmp->next;

	}

	// print_pars_lst(*pars_lst);  //delete it later
	return (1);
}