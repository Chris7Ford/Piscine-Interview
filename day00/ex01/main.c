#include "header.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <string.h>

struct s_test
{
	char	*name;
	int		result;
};

void sortArts(struct s_art **arts);

int		count_art(char *filename)
{
	int		count = 0;
	FILE 	*fp = fopen(filename, "r");
	char 	buffer[1024];

	if (fp == 0)
		return -1;
	while (fgets(buffer, sizeof(buffer), fp) != 0)
		count++;
	fclose(fp);
	return (count);
}

int		get_index_of_split(char *str, char split)
{
	int i = 0;
	while (str[i] != split && str[i] != '\0')
		i++;
	return (i);
}

struct s_art	*create_node(char *title, int price)
{
	struct s_art	*elem;

	elem = malloc(sizeof(struct s_art));
	elem->name = title;
	elem->price = price;
	return (elem);
}

void	fill_array(struct s_art **arr, int works_count, char *filename)
{
	FILE 			*fp = fopen(filename, "r");
	char 			buffer[1024];
	char			*art;
	int				price;
	int				split_index;

	if (fp == 0)
		return ;
	//longest art work is 789 characters long
	for (int i = 0; i < works_count; i++)
	{
		fgets(buffer, sizeof(buffer), fp);
		buffer[strlen(buffer) - 1] = '\0';
		split_index = get_index_of_split(buffer, '=');
		art = strndup(buffer, split_index - 1);
		price = atoi(buffer + split_index + 3);
		arr[i] = create_node(art, price);
	}
	fclose(fp);
}

void	print_array(struct s_art **arr, int works_count)
{
	for (int i = 0; i < works_count; i++)
		printf("Artpiece: %s, price: %d\n", arr[i]->name, arr[i]->price);
}

void	free_it(struct s_art ***arr)
{
	for (int i = 0; (*arr)[i]; i++)
		free((*arr)[i]);
	free(*arr);
}

void	test_sort(struct s_art **arr)
{
	int		error = 0;
	int		i;

	for (i = 0; arr[i + 1]; i++)
	{
		if (strcmp(arr[i]->name, arr[i + 1]->name) > 0)
		{
			printf("Break on %s and %s", arr[i]->name, arr[i + 1]->name);
			error = 1;
			break ;
		}
	}
	if (error)
		printf("The array is not sorted at index %d. art #1 = %s and art #2 = %s\n", i, arr[i]->name, arr[i + 1]->name);
	else
		printf("Array successfully sorted by Ascii value!\n");

}

int		main(int argc, char **argv)
{
	struct s_art	**arr;

	if (argc == 2)
	{
		int works_count = count_art(argv[1]);
		arr = malloc(sizeof(struct s_art *) * (works_count + 1));
		fill_array(arr, works_count, argv[1]);
		arr[works_count] = 0;
//		print_array(arr, works_count);
		sortArts(arr);
		print_array(arr, works_count);
		test_sort(arr);
		free_it(&arr);
	}
	return (0);
}
