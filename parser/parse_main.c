#include "../headers/parse.h"

int	parse_str(char **str, t_parse_lst *pars_lst)
{
	if (not_ending_string(*str) == false)
	{
		printf("syntax error: unexpected end of file\n");
		return (-1);
	}
	*str = relese_quoutes(*str);
	*str = get_var_mean(*str, pars_lst);
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
	if (not_ending_string(*str) == false)
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
		parse_str(&(pars_tmp)->command, *pars_lst);
		while (args_tmp)
		{
			parse_str(&args_tmp->arg, pars_tmp);
			args_tmp = args_tmp->next;
		}
		(pars_tmp) = (pars_tmp)->next;
	}
	// parse_str(str, *pars_lst);
	print_pars_lst(*pars_lst); 
	// if (not_ending_string(*str) == false)
	// {
	// 	printf("syntax error: unexpected end of file\n");
	// 	return (-1);
	// }
	// *str = relese_quoutes(*str);
	// *str = get_var_mean(*str, *pars_lst);
	// free(*str);
	return (1);
}