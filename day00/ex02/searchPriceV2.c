#include "header.h"
#include <string.h> //strcmp

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		begin;
	int		middle;
	int		end;
	int		res;


	begin = 0;
	end = n - 1;
	while (begin <= end)
	{
		middle = (begin + end) / 2;
		res = strcmp(arts[middle]->name, name);
		if (res == 0)
			return (arts[middle]->price);
		else if (res < 0)
			begin = middle + 1;
		else
			end = middle - 1;
	}
	return (-1);
}
