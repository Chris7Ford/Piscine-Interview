#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	for (int i = 0; arts[i]; i++)
	{
		if (strcmp(name, (arts[i])->name) == 0)
			return ((arts[i])->price);
	}
	return (-1);
}
