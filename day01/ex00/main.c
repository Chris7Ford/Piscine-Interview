#include "header.h"
#include <stdio.h> //printf
#include <stdlib.h> //malloc, atoi

int		*create_array(char **str, int size)
{
	int		*arr;

	arr = malloc(sizeof(int) * (size));
	for (int i = 0; i < size; i++)
		arr[i] = atoi(str[i + 1]);
	return (arr);
}

int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	*arr = create_array(argv, argc - 1);
//		print_arr(arr, argc - 1);
		printf("%s\n", precious(arr, argc - 1));
	}
	return (0);
}
