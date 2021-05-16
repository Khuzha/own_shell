#ifndef PARSE_HEADER_H
# define PARSE_HEADER_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../batyr_libft/libft.h"
# include <stdbool.h>

typedef enum e_types_of_found
{
	redir_is_next,
	pipe_is_next,
	none
}				t_found;

typedef struct s_parsed_args
{
	struct s_parsed_args	*next;
	struct s_parsed_args	*previous;
	struct s_parsed_args	*head;
	struct s_parsed_args	*tail;
	char					*arg;
}				t_args;

typedef struct s_main_parse_list
{
	struct s_main_parse_list	*head;
	struct s_main_parse_list	*tail;
	struct s_main_parse_list	*next;
	struct s_main_parse_list	*previous;
	t_args						*args;
	t_found						type_of_next_command;
	int							exit_status;
	char						*command;

}		t_parse_lst;
//||
//init lists and it's fields fell by 0
void	init_main_lists(t_parse_lst *main_list);
//||
void	ft_shell_lst_add_back(t_parse_lst *lst, t_parse_lst *new_lst);
void	ft_args_lst_add_back(t_args *lst, t_args *new_lst);
int		parser(char **str, t_parse_lst **pars_lst);
int		not_ending_string(char *str);//looks if string ends with not valid symbol | or ' or " 
char	*relese_quoutes_main(char *str);
char	*screen_chars(char *str, int open_uquote, int *i);
int		find_next_quote(char *str, int i, char quote);
int		find_open_quote(char *str, int pos, char quote);
char	*get_var_mean(char *str, t_parse_lst *parse_lst);
char	*screen_chars_out_of_quotes(char *str);

#endif 