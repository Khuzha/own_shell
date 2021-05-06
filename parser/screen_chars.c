#include "../headers/parse.h"

char	*cut_slash(char *str, int slash_pos)
{
	char *cutted_str;

	cutted_str = malloc(ft_strlen(str));
	if (!cutted_str)
		return (NULL);
	ft_memmove(cutted_str, str, ft_strlen(str));
	ft_memmove(&cutted_str[slash_pos], \
		&str[slash_pos +1],ft_strlen(&str[slash_pos + 1]));
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

char *screen_chars(char *str, int *i)
{
	while (*i < find_next_quote(str, *i, '\"'))
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\\' || \
			str[*i + 1] == '\"'))
		{
				str = cut_slash(str, *i);
				if (!str)
					return (NULL);
		}
		(*i)++;
	}
	return (str);
}