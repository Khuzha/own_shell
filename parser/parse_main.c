#include "../headers/parse_header.h"

int parser(char *str, t_parse_lst **pars_lst)
{
	static int first_call;

	first_call = 1;
	if (!str)
		return (-1);
	if (first_call)
	{
		str = ft_strdup(str);
		first_call = 0;
	}
	*pars_lst = malloc(sizeof(t_parse_lst));
	if (!*pars_lst)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	not_ending_string(str);
	str = relese_quoutes_main(str);
	
	return (1);
}