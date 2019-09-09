#include "header.h"
#include <stdlib.h> //malloc
#include <stdio.h> //printf

struct s_link {
	char	c;
	struct s_link	*next;
	struct s_link	*prev;
};

struct s_link	*create_link(struct s_link *prev, char c)
{
	struct s_link	*new;
	new = malloc(sizeof(struct s_link));
	new->c = c;
	new->next = 0;
	new->prev = prev;
	return (new);
}

struct s_link	*push_list(struct s_link **head, char c)
{
	struct s_link	*elem;

	if (*head == 0)
	{
		*head = create_link(0, c);
		return (0);
	}
	elem = *head;
	while (elem->next)
		elem = elem->next;
	elem->next = create_link(elem, c);
	return (elem->next);
}

/*void	print_list(struct s_link *head)
{
	while (head)
	{
		printf("%c", head->c);
		head = head->next;
	}
}
*/

char	*precious(int *text, int size)
{
	struct s_link	*head;
	struct s_link	*tail;
	struct s_link	*elem;
	char			*str;

	head = 0;
	for (int i = 0; CS[i]; i++)
		tail = push_list(&head, CS[i]);
	head->prev = tail;
//	print_list(head);
	tail->next = head;
	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	elem = head;
	for (int j = 0; j < size; j++)
	{
		if (text[j] > 0)
		{
			for (int k = 0; k < text[j]; k++)
				elem = elem->next;
		} else {
			for (int k = 0; k > text[j]; k--)
				elem = elem->prev;
		}
		str[j] = elem->c;
	}
	return (str);
}
