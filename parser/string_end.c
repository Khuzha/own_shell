#include "../headers/parse.h"

int	not_ending_string(char *str)
{
	bool	pipe_in_end;
	int		i;
	int		next_quote;
	bool	opened;

	pipe_in_end = 0;
	next_quote = 0;
	i = -1;
	opened = false;
	while (str[++i])
	{
		if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\'))
		{
			next_quote = find_next_quote(str, i + 1, '\'');
			opened = true;
			if (next_quote != -1)
			{
				i = next_quote;
				opened = 0;
			}
		}
		else if (str[i] == '\"' && (i == 0 || str[i - 1] != '\\'))
		{
			next_quote = find_next_quote(str, i + 1, '\"');
			opened = true;
			if (next_quote != -1)
			{
				i = next_quote;
				next_quote = 0;
				opened = false;
			}
		}
		else if (str[i] == '|' && ft_isempty_str(&str[i + 1]))
				return (0);
		else if (str[i] == '\\' && str[i + 1] == '\0')
			return (0);
	}
	return (!opened);
}
