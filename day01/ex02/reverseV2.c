#include "header.h"
#include <stdio.h> //printf

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;
	stack = malloc(sizeof(struct s_stack));
	stack->item = 0;
	return (stack);
}	


struct s_item	*create_item(char *str)
{
	struct s_item	*new;

	new = malloc(sizeof(struct s_item));
	new->word = str;
	new->next = 0;
	return (new);
}

void	push(struct s_stack *stack, char *word)
{
	struct s_item	*elem;

	if (stack == 0)
		return;
	if (stack->item == 0)
	{
		stack->item = create_item(word);
		return ;
	}
	else
	{
		elem = create_item(word);
		elem->next = stack->item;
		stack->item = elem;
	}
}

void	*pop(struct s_stack *stack)
{
	struct s_item	*elem;

	if (stack && stack->item)
	{
		elem = stack->item;
		stack->item = stack->item->next;
	}
	else
		elem = 0;
	return (elem);
}

void	printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;
	struct s_item	*item;

	stack = stackInit(); 
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		item = (struct s_item *)pop(stack);
		printf("%s", item->word);
		if (stack->item)
			printf(" ");
	}
	printf("\n");
}
