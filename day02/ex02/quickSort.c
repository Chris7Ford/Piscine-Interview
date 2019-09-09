#include "header.h"
#include <stdlib.h>
#include <string.h>

void	swap(struct s_player **players, int i, int j)
{
	struct s_player	*temp;

	temp = players[i];
	players[i] = players[j];
	players[j] = temp;
}

int		partition(struct s_player **players, int start, int end)
{
	int 			pindex;
	struct s_player	*pivot;

	pindex = start;
	pivot = players[end];
	for (int i = start; i < end; i++)
	{
		if (players[i]->score > pivot->score)
		{
			swap(players, i, pindex);
			pindex++;
		}
	}
	swap(players, pindex, end);
	return (pindex);
}

void	ft_qsort(struct s_player **players, int start, int end)
{
	int pindex;

	while (start < end)
	{
		pindex = partition(players, start, end);
		if (pindex - start < end- pindex)
		{
			ft_qsort(players, start, pindex - 1);
			start = pindex + 1;
		}
		else
		{
			ft_qsort(players, pindex + 1, end);
			end = pindex - 1;
		}
	}
}

void		quickSort(struct s_player **players)
{
	int size;

	size = 0;
	while (players[size])
		size++;
	ft_qsort(players, 0, size - 1);
}
