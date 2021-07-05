#include "../../headers/engine.h"

void	call_parser(char *line, t_parse_lst **lst)
{
	char **splitted_str;

	printf("call_parser\n");
	splitted_str = split_out_quotes(line, ';');
	if (!*splitted_str)
		printf("\n\n______ERROR______\n\n");
	while (*splitted_str)
	{
		if (parser(splitted_str, lst) == -1 || *lst == NULL)
			printf("\n\n______ERROR______\n\n");
		splitted_str++;  
	}
}

void	call_function(t_parse_lst *lst)
{
	if (lst->command == COMMAND_ECHO)
		printf("echo\n");
	else
		find_function(lst);
}