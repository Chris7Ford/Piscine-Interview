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

int		sort_players(struct s_player *a, struct s_player *b)
{
	if (a->score == b->score)
		return (strcmp(a->timeStamp, b->timeStamp) < 0 ? 1 : 0);
	else if (a->score > b->score)
		return (1);
	return (0);
}

void	merge(struct s_player **players, struct s_player **temp, int leftStart, int rightEnd)
{
	int		leftEnd = (rightEnd + leftStart) / 2;
	int		rightStart = leftEnd + 1;
	int		left = leftStart;
	int		right = rightStart;
	int		index = leftStart;

	while (index <= rightEnd)
	{
		if (left <= leftEnd && right <= rightEnd)
		{
			if (players[left]->score < players[right]->score)
				temp[index] = players[right++];
			else
				temp[index] = players[left++];
		}
		else if (left <= leftEnd)
		{
			temp[index] = players[left];
			left++;
		}
		else
		{
			temp[index] = players[right];
			right++;
		}
		index++;
	}
	while (leftStart < rightEnd)
	{
		players[leftStart] = temp[leftStart];
		leftStart++;
	}
	//memmove(&players[left], &temp[left], sizeof(struct s_player *) * (rightEnd - leftStart + 1));

/*	while (left <= leftEnd && right <= rightEnd)
	{
		if (cmp(players[left], players[right]))
		{
			temp[index] = players[left];
			left++;
		} else {
			temp[index] = players[right];
			right++;
		}
		index++;
	}
	while (left < leftEnd)
	{
		temp[index] = players[left];
		left++;
		index++;
	}
	while (right < rightEnd)
	{
		temp[index] = players[right];
		right++;
		index++;
	}
	while (leftStart < rightEnd)
	{
		players[leftStart] = temp[leftStart];
		leftStart++;
	}*/
}

void	ft_merge_sort(struct s_player **players, struct s_player **temp, int start, int end)
{
	int		middle;

	if (start >= end)
		return ;
	middle = (start + end) / 2;
	ft_merge_sort(players, temp, start, middle);
	ft_merge_sort(players, temp, middle + 1, end);
	merge(players, temp, start, end);
}

void		mergeSort(struct s_player **players)
{
	struct s_player	**temp;
	int 			size;

	size = 0;
	while (players[size])
		size++;
	temp = malloc(sizeof(struct s_player *) * (size + 1));
	temp[size] = 0;
	ft_merge_sort(players, temp, 0, size - 1);
	free(temp);
}
