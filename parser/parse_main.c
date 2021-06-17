#include "../headers/parse.h"
//TODO add screening out of quotes
int parser(char **str, t_parse_lst **pars_lst)
{
	static int first_call;

	first_call = 1;
	if (!*str)
		return (-1);
	if (first_call)
	{
		*str = ft_strdup(*str);
		first_call = 0;
	}
	if (!*pars_lst)
		*pars_lst = malloc(sizeof(t_parse_lst));
	if (!*pars_lst)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
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