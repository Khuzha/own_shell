#include "../headers/parse.h"

char	*get_var_mean(char *str, t_parse_lst *pars_lst)
{
	char	*temp;
	char	*var;
	char	*new_str;
	int		end_pos;
	int		str_len;
	int		i;

	i = 0;
	new_str = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && ft_isalpha(str[i + 1]))
		{
			end_pos = i + 1;
			str_len = ft_strlen(str);
			while (ft_isalpha(str[end_pos]) || str[end_pos] == '_')
					end_pos++;
			end_pos = end_pos - i - 1;
			temp = ft_substr(str, i + 1, end_pos);
			var = getenv(temp);
			if (!var || str[i + 1] == '?')
			{
				if (str[i + 1] == '?')
				{
					var = ft_itoa(pars_lst->tail->exit_status);
					ft_memmove(&str[i], &str[end_pos + i + 1], ft_strlen(&str[end_pos + i]));
					free(var);
				}
				else
					ft_memmove(&str[i], &str[end_pos + i + 1], ft_strlen(&str[end_pos + i]));
			}
			else
			{
				str[i] = 0;
				new_str = malloc(ft_strlen(var) + ft_strlen(&str[end_pos + i + 1]) + ft_strlen(str));
				ft_memmove(new_str, str, ft_strlen(str));
				ft_memmove(&new_str[i], var, ft_strlen(var));
				ft_memmove(&new_str[i + ft_strlen(var)],  &str[i + end_pos + 1], ft_strlen(&str[i + end_pos]));
				// ft_strcpy(&new_str[i + ft_strlen(var)], &str[i + end_pos + 1]);
				free(str);
				str = new_str;
			}
			free(temp);
			// free(var);
		}
		i++;
	}
	return(str);
}

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

char *screen_chars(char *str, int open_quote, int *i)
{
	int close_quote;

	close_quote = find_next_quote(str, *i, '\"');
	if (open_quote > -1 && close_quote > -1)
	{
		while (*i < close_quote && str[*i] != '\0')
		{
			if (str[*i] == '\\' && (str[*i + 1] == '\\' || \
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
	if (str[*i] == '\\' && str[*i + 1] != '\\')
		printf("\n\n\n not closing slash\n\n\n");
	*i = close_quote;
	return (str);
}