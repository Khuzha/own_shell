typedef enum type
{
	pipe, 
	redir
}	t_type;

typedef struct	s_commands
{
	char	*command;
	t_type	type;
	char	*params;
}				t_commands;
