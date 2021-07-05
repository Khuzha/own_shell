#include "../../headers/engine.h"

char	*find_file(char *path, char *function)
{
	
}

char	*find_function_path_in_div(char *path, char *function)
{
	char	**div_colons;
	char	*response;

	div_colons = ft_split(path, ':');
	while (div_colons && *div_colons)
	{

	}
}

char	*find_function_path(char *path, char *function)
{
	char	**div_spaces;
	char	*response;

	div_spaces = ft_split(path, ' ');
	while (div_spaces && *div_spaces)
	{
		response = find_function_path_in_div(div_spaces, function);
		if (response)
			return (response);
		*div_spaces++;
	}
	return (NULL);
}

void	find_function(t_parse_lst *lst)
{
	char	*path;

	path = getenv("PATH");
	printf("PATH = %s\n", path);
	find_function_path(path, lst->command);
}
