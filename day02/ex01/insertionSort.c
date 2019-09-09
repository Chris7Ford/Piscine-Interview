#include "header.h"

void	insertionSort(struct s_player **players)
{
	struct s_player		*temp;

	for (int i = 0; players[i]; i++)
	{
		for (int j = i; j > 0 && players[j]->score > players[j - 1]->score; j--)
		{
			temp = players[j];
			players[j] = players[j - 1];
			players[j - 1] = temp;
		}
	}
}
