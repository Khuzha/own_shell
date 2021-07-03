#include "../headers/parse.h"

void	init_main_lists(t_parse_lst *main_list) //init lists and it's fields fell by 0
{
	if (!main_list)
	{
		exit(errno);
	}
	main_list->head = NULL;
	main_list->tail = NULL;
	main_list->next = NULL;
	main_list->previous = NULL;
	main_list->type_of_next_command = none;
	main_list->args = malloc(sizeof(t_args));
	if (!main_list->args)
	{
		exit(errno);
	}
	main_list->args->head = NULL;
	main_list->args->tail = NULL;
	main_list->args->next = NULL;
	main_list->args->previous = NULL;
}