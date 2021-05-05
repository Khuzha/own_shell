#include "../headers/parse_header.h"

static int	find_close(char *str, int i)
{
	 while (str[i] != '\0')
	 {
		if (str[i] == '\"' && str[i - 1] != '\\')
			return (i);
		i++;
	 }
	 return (-1);
}

static char *cut_quotes(char **str, int open, int close)
{
	char	*cut_str;
	char	*tmp;
	int		str_len;

	str_len = ft_strlen(*str);
	(*str)[open] = 0;
	ft_memmove(&(*str)[close], &(*str)[close + 1], ft_strlen(&(*str)[open + 1]));
	ft_memmove(&(*str)[open],&(*str)[open + 1], ft_strlen(&(*str)[open + 1]));
	(*str)[str_len - 2] = 0;
	cut_str = ft_strdup(*str);
	free(*str);
	return (cut_str);
}

char	*relese_quoutes_main(char *str)
{
	int i;
	int open_quotes;
	int close_quotes;
	
	 i = -1;
	 open_quotes = -1;
	 close_quotes = -1;
	 while (str[++i] != '\0')
	 {
		 if (str[i] == '\"' && (i == 0 || str[i - 1] != '\\'))
		 {
			open_quotes = i;
			close_quotes = find_close(str, i + 1);
			str = cut_quotes(&str, open_quotes, close_quotes);
		 }

	 }
}