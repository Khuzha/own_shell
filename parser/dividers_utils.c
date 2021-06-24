#include "../headers/parse.h"

static t_deviders	*lstnew_devide(int pos, t_found devider_type)
{
	t_deviders *new_list;

	new_list = malloc(sizeof(t_deviders));
	if (!new_list)
		return (NULL);
	new_list->pos_in_str = pos;
    new_list->type = devider_type;
	new_list->next = NULL;
	return (new_list);
}

static void	lstadd_back_devide(t_deviders **lst, t_deviders *new)
{
	t_deviders *temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_deviders *get_deviders_list(char *str)
{
	int			i;
	int			count;
	t_deviders	*deviders;

	i = 0;
	count = 0;
	deviders = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
			lstadd_back_devide(&deviders, lstnew_devide(i, pipe_is_next));
		else if (str[i] == '>')
			lstadd_back_devide(&deviders, lstnew_devide(i, redir_is_next));
		else if (str[i] == '<')
			lstadd_back_devide(&deviders, lstnew_devide(i, back_redir_is_next));
		else if (str[i] == '>' && str[i + 1] == '>')
		{
			lstadd_back_devide(&deviders, lstnew_devide(i, pipe_is_next));
			i++;
		}
		i++;
	}
	return (deviders);
}
