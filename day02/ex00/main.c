#include "header.h"
#include <stdlib.h>// malloc
#include <stdio.h>//printf

struct s_stone	*create_stone(int size)
{
	struct s_stone	*new;

	new = malloc(sizeof(struct s_stone));
	new->size = size;
	new->next = 0;
	return (new);
}

void	push_list(struct s_stone **head, int size)
{
	struct s_stone	*elem;

	if (head == 0)
		return ;
	if (*head == 0)
	{
		*head = create_stone(size);
		return ;
	}
	elem = *head;
	while (elem->next)
		elem = elem->next;
	elem->next = create_stone(size);
}

void	print_list(struct s_stone *head)
{
	while (head)
	{
		printf("%d\n", head->size);
		head = head->next;
	}
}

void	free_list(struct s_stone *head)
{
	struct s_stone *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

int		main(void)
{
	struct s_stone	*head;
	head = 0;
	push_list(&head, 5);
	push_list(&head, 5);
	push_list(&head, 1);
	push_list(&head, 1);
	push_list(&head, 6);
	push_list(&head, 2);
	push_list(&head, 2);
	push_list(&head, 2);
	push_list(&head, 2);
	printf("Unsorted:\n");
	print_list(head);
	sortStones(&head);
	printf("\nSorted:\n");
	print_list(head);
	free_list(head);

	head = 0;
	push_list(&head, 5);
	push_list(&head, 5);
	push_list(&head, 11100);
	push_list(&head, 11100);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	push_list(&head, 50);
	printf("Unsorted:\n");
	print_list(head);
	sortStones(&head);
	printf("\nSorted:\n");
	print_list(head);
	free_list(head);
	return (0);
}
