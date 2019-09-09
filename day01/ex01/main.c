#include "header.h"

struct s_node	*create_node(char *str)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	new->word = str;
	new->next = 0;
	return (new);
}

void			push_list(struct s_node **head, char *str)
{
	struct s_node	*elem;

	if (*head == 0)
	{
		*head = create_node(str);
		return ;
	}
	elem = *head;
	while (elem->next)
		elem = elem->next;
	elem->next = create_node(str);
}

int				main(int argc, char **argv)
{
	struct s_node	*head;

	head = 0;
	for (int i = 1; i < argc; i++)
		push_list(&head, argv[i]);
	printReverse(head);
	return (0);
}
