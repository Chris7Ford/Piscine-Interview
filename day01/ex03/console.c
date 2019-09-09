#include <string.h> //strlen, strcmp, bzero
#include <stdio.h> //scanf, printf
#include <stdlib.h> //malloc
#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;
	stack = malloc(sizeof(struct s_stack));
	stack->item = 0;
	return (stack);
}	


struct s_item	*create_item(int idx)
{
	struct s_item	*new;

	new = malloc(sizeof(struct s_item));
	new->idx = idx;
	new->next = 0;
	return (new);
}

void	push(struct s_stack *stack, int idx)
{
	struct s_item	*elem;

	if (stack == 0)
		return;
	if (stack->item == 0)
	{
		stack->item = create_item(idx);
		return ;
	}
	else
	{
		elem = create_item(idx);
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

char	*console(void)
{
	struct s_stack	*stack;
	struct s_item	*elem;
	char	buff[257];
	char	*str;
	int		length;
	int		prev;

	str = malloc(sizeof(char) * (257));
	bzero(str, 257);
	stack = stackInit();
	while (1)
	{
		printf("?: ");
		scanf("%s\n", &buff);
		if (strcmp(buff, "SEND") == 0)
			return (str);
		else if (strcmp(buff, "UNDO") == 0)
		{
			elem = (struct s_item *)pop(stack);
			if (stack->item)
				prev = stack->item->idx;
			else
				prev = 0;
			for (int i = elem->idx; i < prev; i--)
				str[i] = '\0';
		}
		else
		{
			length = strlen(buff);
			if (stack->item)
				prev = stack->item->idx;
			else
				prev = 0;
			push(stack, prev + length);
			for (int i = 0; i < length; i++)
				str[prev + i] = buff[i];
		}
		printf("%s\n\n", str);
		bzero(buff, 257);
	}
	return (str);
}
