#include "../headers/parse.h"

int	find_next_quote(char *str, int i, char quote)
{
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
	char	*cut_str;
	char	*tmp;
	int		str_len;


	str_len = ft_strlen(*str);
	(*str)[*open] = 0;
	ft_memmove(&(*str)[*close], &(*str)[*close + 1], ft_strlen(&(*str)[*open + 1]));
	ft_memmove(&(*str)[*open],&(*str)[*open + 1], ft_strlen(&(*str)[*open + 1]));
	(*str)[str_len - 2] = 0;
	cut_str = ft_strdup(*str);
	*open = -1;
	free(*str);
	return (cut_str);
}

char	*relese_quoutes_main(char *str)
{
	int i;
	int dq_open;
	int dq_close;
	int q_open;
	int q_close;
	
	i = -1;
	dq_close = -1;
	dq_open = -1;
	q_close = -1;
	q_open = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\') && dq_close == -1)
		{
			q_open = i;
			q_close = find_next_quote(str, i + 1, '\'');
			i = q_close;
			str = cut_quotes(&str, &q_open, &q_close);
		}
		else if (str[i] == '\"' && (i == 0 || str[i - 1] != '\\') && q_close == -1)
		{
			dq_open = i;
			dq_close = find_next_quote(str, i + 1, '\"');
			i = q_close;
			str = cut_quotes(&str, &dq_open, &dq_close);
		}
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