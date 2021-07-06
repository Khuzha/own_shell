#include "../headers/parse.h"

int	get_redir_fd(t_found type, t_parse_lst *curr_pars, char *filename)
{
	int fd;

	curr_pars->type_of_next_command = type;
	fd = 1;

	return (fd);
}