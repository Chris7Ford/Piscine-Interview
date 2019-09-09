#include "header.h"
#include <stdlib.h> //malloc

struct s_arr {
	struct s_stone *begin;
	struct s_stone *tail;
};

void	get_max(struct s_stone *head, int *max)
{
	while (head)
	{
		if (head->size > *max)
			*max = head->size;
		head = head->next;
	}
}

struct s_arr *create_arr()
{
	struct s_arr *new;

	new = malloc(sizeof(struct s_arr));
	new->begin = 0;
	new->tail = 0;
	return (new);
}

void	init_arr(struct s_arr **arr, int max)
{
	for (int i = 0; i <= max; i++)
		arr[i] = create_arr();
}

void	fill_arr(struct s_arr **arr, struct s_stone *stone)
{
	int		temp;

	while (stone)
	{
		temp = stone->size;
		arr[temp]->begin = stone;
		while (stone && stone->size == temp)
		{
			arr[temp]->tail = stone;
			stone = stone->next;
		}
	}
}

void	reorder(struct s_arr **arr, struct s_stone **head, int max)
{
	struct s_stone	*tail;
	int				i = 0;

	while (i < max)
	{
		if (arr[i]->begin)
			break ;
		i++;
	}
	*head = arr[i]->begin;
	tail = arr[i]->tail;
	while (i <= max)
	{
		if (arr[i]->begin)
		{
			tail->next = arr[i]->begin;
			tail = arr[i]->tail;
		}
		i++;
	}
	tail->next = 0;
}

void	free_arr(struct s_arr **arr, int size)
{
	for (int i = 0; i <= size; i++)
	{
		free(arr[i]);
		arr[i] = 0;
	}
	free(arr);
}

void	sortStones(struct s_stone **stone)
{
	struct s_stone	*elem;
	struct s_arr	**arr;
	int				max;

	max = -2147483648;
	if (stone == 0)
		return ;
	elem = *stone;
	get_max(elem, &max);
	arr = malloc(sizeof(struct s_arr *) * (max + 1));
	init_arr(arr, max);
	fill_arr(arr, *stone);
	reorder(arr, stone,max);
	free_arr(arr, max);
}
