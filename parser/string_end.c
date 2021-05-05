#include "../headers/parse_header.h"

static int	ending_string_return(int quote, int pipe, int double_quote)
{
	if ((double_quote % 2 != 0 && double_quote > 0) \
		|| (quote > 0 && quote % 2 != 0) || pipe)
	{
		printf("Syntax error, not needed in subj\n");
		return (0);
	}
	return (1);
}

int	not_ending_string(char *str)
{
	int	quote;
	int	double_quote;
	int	pipe_in_end;
	int	i;

	quote = 0;
	double_quote = 0;
	pipe_in_end = 0;
	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '\"')
			double_quote++;
		else if (str[i] == '\"' && i > 0 && str[i - 1] != '\\')
			double_quote++;
		else if (double_quote % 2 == 0 && str[i] == '\'')
			quote++;
		else if (str[i] == '|' && (double_quote % 2 == 0 || quote % 2 == 0))
		{
			if (ft_isempty_str(&str[i + 1]))
				pipe_in_end++;
		}
	}
	return (ending_string_return(quote, pipe_in_end, double_quote));
}
