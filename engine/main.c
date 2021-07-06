#include "../headers/engine.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<readline/readline.h>
#include<readline/history.h>

int	main(int argc, const char **argv)
{
	char *line;
	while ((line = readline("bash: ")))
	{
		if (line && *line)
			add_history(line);
	}

	argc++;
	argv++;
	return (0);
}
