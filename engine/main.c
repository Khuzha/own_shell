#include "../headers/engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, const char **argv)
{
	char *line;
	char **splitted_str;
	while ((line = readline("bash: ")))
	{
		if (line && *line)
		{
			add_history(line);
			split_out_quotes(line, ';');
			if (!*splitted_str)
			printf("\n\n______ERROR______\n\n");
			while (*splitted_str)
			{
	
			if (parser(splitted_str, &lst) == -1 || lst == NULL)
			printf("\n\n______ERROR______\n\n");
			splitted_str++;  
			}
		}
	}

	argc++;
	argv++;
	return (0);
}
