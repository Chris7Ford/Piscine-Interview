#include "header.h"
#include <stdlib.h>
#include <string.h>

void	swap(struct s_art **arts, int i, int j)
{
	struct s_art	*temp;

	temp = arts[i];
	arts[i] = arts[j];
	arts[j] = temp;
}

int		partition(struct s_art **arts, int start, int end)
{
	int 			pindex;
	struct s_art	*pivot;

	pindex = start;
	pivot = arts[end];
	for (int i = start; i < end; i++)
	{
		if (strcmp(arts[i]->name, pivot->name) < 0)
		{
			swap(arts, i, pindex);
			pindex++;
		}
	}
	swap(arts, pindex, end);
	return (pindex);
}

void	ft_qsort(struct s_art **arts, int start, int end)
{
	int pindex;

	while (start < end)
	{
		pindex = partition(arts, start, end);
		if (pindex - start < end- pindex)
		{
			ft_qsort(arts, start, pindex - 1);
			start = pindex + 1;
		}
		else
		{
			ft_qsort(arts, pindex + 1, end);
			end = pindex - 1;
		}
	}
}

void		sortArts(struct s_art **arts)
{
	int size;

	size = 0;
	while (arts[size])
		size++;
	ft_qsort(arts, 0, size - 1);
}
