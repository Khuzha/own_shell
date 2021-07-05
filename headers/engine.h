#ifndef ENGINE_HEADER_H
# define ENGINE_HEADER_H

#define BUFFER_SIZE 21
#define TERM_TITLE "xterm-256color"

# include "./common.h"
# include "./parse.h"
# include "./keys.h"

# include "term.h"

# include "term.h"
# include <readline/readline.h>
# include <readline/history.h>

// utils
void	parse_env();
void	call_parser(char *line, t_parse_lst **lst);
void	call_function(t_parse_lst *lst);
void	find_function(t_parse_lst *lst);

// Builtins
#define COMMAND_ECHO "echo"
#define COMMAND_CD "cd"
#define COMMAND_PWD "pwd"
#define COMMAND_EXPORT "export"
#define COMMAND_UNSET "unset"
#define COMMAND_ENV "env"
#define COMMAND_EXIT "exit"

#endif

