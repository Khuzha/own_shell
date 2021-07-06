#include "../../headers/engine.h"

char	*find_file(char *path, char *function)
{
	DIR *dir = opendir(path);
	struct dirent *entity;

	printf("find_file bef loop, path = %s\n", path);
	while ((entity = readdir(dir)))
	{
		printf("find_file in loop\n");
		printf("filename = %s\n", entity->d_name);
		if (!strcmp(entity->d_name, function))
			return entity->d_name;
	}
	return (NULL);
}

char	*find_function_path_in_div(char *path, char *function)
{
	char	**div_colons;
	char	*response;

	div_colons = ft_split(path, ':');
	while (div_colons && *div_colons)
	{
		printf("div_colons = %s\n", *div_colons);
		response = find_file(*div_colons, function);
		if (response)
			return (response);
		(*div_colons)++;
	}
	return (NULL);
}

char	*find_function_path(char *path, char *function)
{
	char	**div_spaces;
	char	*response;

	div_spaces = ft_split(path, ' ');
	while (div_spaces && *div_spaces)
	{
		printf("div_spaces = %s\n", *div_spaces);
		response = find_function_path_in_div(*div_spaces, function);
		if (response)
			return (response);
		(*div_spaces)++;
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
