#include "../headers/parse.h"

int	parse_str(char *str)
{
	if (not_ending_string(str) == false)
	{
		printf("syntax error: unexpected end of file\n");
		return (-1);
	}
	*str = get_var_mean(str, *pars_lst);
	*str = relese_quoutes(*str);
}

int parser(char **str, t_parse_lst **pars_lst)
{
	if (!*pars_lst)
		*pars_lst = malloc(sizeof(t_parse_lst));
	if (!*pars_lst)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	init_lst(*pars_lst);
	/*
	TODO devide str by ';' and fill pars_lst
	*/

	if (not_ending_string(*str) == false)
	{
		printf("syntax error: unexpected end of file\n");
		return (-1);
	}
	*str = get_var_mean(*str, *pars_lst);
	*str = relese_quoutes(*str);
	free(*str);
	return (1);
}