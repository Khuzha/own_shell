#include "../headers/parse_header.h"

int not_ending_string(char *str)
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
	// printf("num of dub quotes = %d and %d\n", double_quote, double_quote % 2);
	// printf("num of quotes = %d and %d\n", quote, quote % 2);
	if ((double_quote % 2 != 0 && double_quote > 0) \
	|| (quote > 0 && quote % 2 != 0) || pipe_in_end)
	{
		printf("Syntax error, not needed in subj\n");
		return (-1);
	}

}