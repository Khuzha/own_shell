#include "../headers/parse.h"

char	*get_var_mean(char *str, t_parse_lst *pars_lst)
{
	char	*temp;
	char	*var;
	char	*new_str;
	int		end_pos;
	int		i;

	i = 0;
	new_str = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && (i == 0 || str[i - 1] != '\\') && 
			(ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
		{
			end_pos = i + 1;
			while (ft_isalpha(str[end_pos]) || str[end_pos] == '_')
					end_pos++;
			end_pos = end_pos - i - 1;
			temp = ft_substr(str, i + 1, end_pos);
			var = getenv(temp);
			if (!var && str[i + 1] != '?')
			{
				ft_memmove(&str[i], &str[end_pos + i + 1], ft_strlen(&str[end_pos + i]));

			}
			else if (var || str[i + 1] == '?')
			{
				if (str[i + 1] == '?')
				{
					if (pars_lst->tail == NULL)
						var = ft_strdup("0");
					else
						var = ft_itoa(pars_lst->tail->exit_status);
				}
				else
					var = ft_strdup(var);
				str[i] = 0;
				new_str = malloc(ft_strlen(var) + ft_strlen(&str[end_pos + i + 1]) + ft_strlen(str));
				ft_memmove(new_str, str, ft_strlen(str));
				ft_memmove(&new_str[i], var, ft_strlen(var));
				ft_memmove(&new_str[i + ft_strlen(var)],  &str[i + end_pos + 1], ft_strlen(&str[i + end_pos]));
				// ft_strcpy(&new_str[i + ft_strlen(var)], &str[i + end_pos + 1]);
				free(str);
				free(var);
				str = new_str;
			}
			free(temp);
		}
		i++;
	}
	return(str);
}