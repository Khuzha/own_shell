#include "../headers/engine.h"

int	main()
{
	char *line;
	t_parse_lst *lst;

	lst = NULL;
	while ((line = readline("mysh: ")))
	{
		if (line && *line)
		{
			add_history(line);
			call_parser(line, &lst);
			call_function(lst);
		}
	}
	return (0);
}
