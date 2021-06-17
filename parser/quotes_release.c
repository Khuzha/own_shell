#include "../headers/parse.h"

size_t	ft_ft_strlen(const char *str)
{
	size_t	i;

	i = 1;
	while (*str++)
		i++;
	return (i);
}

int	find_next_quote(char *str, int i, char quote)
{
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == quote && str[i - 1] != '\\')
			return (i);
		i++;
	}
	 return (-1);
}

static char *cut_quotes(char **str, int *open, int *close)
{
	char	*tmp;
	int		str_len;


	(*str)[*open] = 0;
	(*str)[*close] = 0;
	ft_memmove(&(*str)[*close], &(*str)[*close + 1], ft_ft_strlen(&(*str)[*close + 1]));
	ft_memmove(&(*str)[*open],&(*str)[*open + 1], ft_ft_strlen(&(*str)[*open + 1]));
	*open = -1;
	return (*str);
}

char	*relese_quoutes(char *str)
{
	int i;
	int dq_open;
	int dq_close;
	int q_open;
	int q_close;
	
	i = 0;
	dq_close = -1;
	dq_open = -1;
	q_close = -1;
	q_open = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\') && dq_close == -1)
		{
			q_open = i;
			q_close = find_next_quote(str, i, '\'');
			i = q_close;
			str = cut_quotes(&str, &q_open, &q_close);
		}
		else if (str[i] == '\"' && (i == 0 || str[i - 1] != '\\') && q_close == -1)
		{
			dq_open = i;
			str = screen_chars(str, dq_open, &i);
			dq_close = i;
			// dq_close = find_next_quote(str, i, '\"');
			str = cut_quotes(&str, &dq_open, &dq_close);
		}
		else if (str[i] == '\\' && (str[i + 1] == '\\' || 
		str[i + 1] == '$' || str[i + 1] == '\'' || str[i + 1] == '\"'))
		{
			str = cut_char(str, i);
			i++;
		}
		else 
			i++;
	}
	return (str);
}






		// if (str[i] == '\'' && open_quotes == -1 && (i == 0 || str[i - 1] != '\\'))
		// {
		//  	one_quote = 1;
		// 	 i++;
		// }
		// if (str[i] == '\'' && open_quotes == -1 && 
		// (i == 0 || str[i - 1] != '\\') && one_quote)
		//  	one_quote = 0;
		// if (str[i] == '\"' && (i == 0 || str[i - 1] != '\\')  && !one_quote)
		// {
		// 	open_quotes = i;
		// 	close_quotes = find_close(str, i + 1);
		// 	str = cut_quotes(&str, open_quotes, close_quotes);
		// 	open_quotes = -1;
		// 	close_quotes = -1;
		// 	printf("str = %s\n", str);
		// 	i = -1;
		// }