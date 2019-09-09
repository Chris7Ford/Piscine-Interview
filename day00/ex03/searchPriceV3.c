#include "header.h"
#include <string.h> //strlen
#include <stdlib.h> //malloc

size_t	hash(char *input)
{
	size_t	res = 0;
	int		len;
	
	len = strlen(input);
	if (len > 3)
	{
		res += (input[len - 1] % 10) * 10000;
		res += (len % 10) * 1000;
		res += (input[0] % 10) * 100;
		res += (input[1] % 10) * 10;
		res += input[2] % 10;
	}
	return (res);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*new;
	new = malloc(sizeof(struct s_dict));
	new->items = malloc(sizeof(struct s_items *) * capacity);
	for (int i = 0; i < capacity; i++)
		new->items[i] = 0;
	new->capacity = capacity;
	return (new);
}

struct s_item	*create_item(char *key, struct s_art *value)
{
	struct s_item	*new;

	new = malloc(sizeof(struct s_item));
	new->value = value;
	new->key = key;
	new->next = 0;
	return (new);
}

void	push_list(struct s_item **head, char *key, struct s_art *value)
{
	struct s_item	*elem;

	if (head == 0)
		return ;
	if (*head == 0)
	{
		*head = create_item(key, value);
		return ;
	}
	elem = *head;
	while (elem->next)
		elem = elem->next;
	elem->next = create_item(key, value);
}

int		dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t	index;

	index = hash(key);
	if (dict && dict->items)
	{
		push_list(&(dict->items[index]), key, value);
	}
	return ((int) index);
	//Why am I returning an integer for an insert?
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*elem;
	size_t	index;

	index = hash(key);
	if (dict && dict->items)
	{
		elem = dict->items[index];
		while (elem)
		{
			if (strcmp(elem->key, key) == 0)
				return (elem->value);
			elem = elem->next;
		}
	}
	return (0);
}

int		searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*res;

	res = dictSearch(dict, name);
	if (res == 0)
		return (-1);
	return (res->price);
}
