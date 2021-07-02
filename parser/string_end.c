#include "../headers/parse.h"

int	not_ending_string(char **str)
{
	bool	pipe_in_end;
	int		i;
	int		next_quote;
	int		slash;

	pipe_in_end = 0;
	next_quote = 0;
	i = -1;
	slash = 0;
	char *qq;
	while ((*str)[++i])
	{
		// if ((*str)[i] == '\\' && ((*str)[i + 1] != '\\' || (*str)[i + 1] != '$'\
		// || (*str)[i + 1] != '\"' || (*str)[i + 1] != '\''))
		// {
		// 	(*str) = cut_char((*str), i);
		// 	i++;
		// }
		if ((*str)[i] == '\\')
			slash++;
		if ((*str)[i] == '\'' && (i == 0 || (*str)[i - 1] != '\\'))
		{
			next_quote = find_next_quote((*str), i, '\'');
			if (next_quote == -1)
				return (false);
			else
				i = next_quote;
		}
		else if ((*str)[i] == '\"' && (i == 0 || (*str)[i - 1] != '\\'))
		{
			next_quote = find_next_quote((*str), i, '\"');
			if (next_quote == -1)
				return (false);
			else
				i = next_quote;
		}
		else if ((*str)[i] == '|' && ft_isempty_str(&(*str)[i]))
				return (false);
		else if ((slash % 2) != 0 && (*str)[i] == '\\' && (*str)[i + 1] == '\0')
			return (false);
	}
	return (true);
}
