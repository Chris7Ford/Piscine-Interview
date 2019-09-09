#include "header.h"
#include <string.h> //strcmp
#include <stdio.h> //printf

int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int		validate_bits(char *a, char *b)
{
	int		i;

	for (i = 0; i < 6; i++)
		if (!is_num(a[i]) || !is_num(b[i]))
			break;
	return (i == 6 && a[i] == '\0' && b[i] == '\0');
}

int		main(int argc, char **argv)
{
	char	*sum;

	if (argc == 4 && strcmp(argv[2], "+") == 0 && validate_bits(argv[1], argv[3]))
	{
		sum = getSum(argv[1], argv[3]);
		printf("%s (%d)\n", sum, toInt(sum));
	}
	return (0);
}
