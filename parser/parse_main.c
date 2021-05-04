#include "../headers/parse_header.h"

int parser(char *str, t_parse_lst **pars_lst)
{
	if (!str)
		return (-1);
	*pars_lst = malloc(sizeof(t_parse_lst));
	if (!*pars_lst)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	not_ending_string(str);


	return (1);
}