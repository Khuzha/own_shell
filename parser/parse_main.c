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
	fill_lst(*str, pars_lst);
	return (1);
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
	parse_str(str, *pars_lst);
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