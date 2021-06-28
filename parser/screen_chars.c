#include "../headers/parse.h"

char	*cut_char(char *str, int char_pos)
{
	char *cutted_str;

	cutted_str = malloc(ft_strlen(str));
	if (!cutted_str)
		return (NULL);
	ft_memmove(cutted_str, str, ft_strlen(str));
	ft_memmove(&cutted_str[char_pos], \
		&str[char_pos +1],ft_strlen(&str[char_pos + 1]));
	cutted_str[ft_strlen(str) - 1] = 0;
	free(str);
	return (cutted_str);
}


int	find_open_quote(char *str, int pos, char quote)
{
	if (pos <= 0)
		return (-1);
	while (str[--pos] >= 0)
	{
		if (str[pos] == quote && str[pos - 1] != '\\')
			return (pos);
	}
	return (-1);
}

char *screen_chars(char *str, int open_quote, int *i, t_parse_lst *pars_lst)
{
	int close_quote;

	close_quote = find_next_quote(str, *i, '\"');
	if (open_quote > -1 && close_quote > -1)
	{
		while (*i < close_quote && str[*i] != '\0')
		{
			if (str[*i] == '$' && (*i == 0 || str[*i - 1] != '\\') && 
			(ft_isalpha(str[*i + 1]) || str[*i + 1] == '?'))
			{
				str = get_var_mean(str, pars_lst, i);
				close_quote = find_next_quote(str, *i, '\"');
			}
			else if (str[*i] == '\\' && (str[*i + 1] == '\\' || \
				str[*i + 1] == '\"' || str[*i + 1] == '$'))
			{
					str = cut_char(str, *i);
					if (!str)
						return (NULL);
					close_quote = find_next_quote(str, *i, '\"');
					(*i) ++;
			}
			else 
				(*i)++;
		}
	}
	*i = close_quote;
	return (str);
}