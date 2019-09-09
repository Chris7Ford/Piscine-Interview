#include "header.h"
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <string.h> //strdup

struct s_player	*create_player(char *name, int score, char *time)
{
	struct s_player	*new;
	new = malloc(sizeof(struct s_player));
	new->name = strdup(name);
	new->score = score;
	new->timeStamp = time;
	return (new);
}

void	print_arr(struct s_player **players)
{
	for (int i = 0; players[i]; i++)
		printf("%s: %d at %s\n", players[i]->name, players[i]->score, players[i]->timeStamp);
}

int		main(void)
{
	struct s_player	**players;
	int				size = 15;

	players = malloc(sizeof(struct s_player) * (size + 1));
	players[0] = create_player("player1", 55, "18:00");
	players[1] = create_player("player2", 512, "15:43");
	players[2] = create_player("player3", 12, "14:53");
	players[3] = create_player("player4", 75, "06:12");
	players[4] = create_player("player5", 11, "01:11");
	players[5] = create_player("player6", 3, "11:11");
	players[6] = create_player("player7", 642, "10:42");
	players[7] = create_player("player8", 92, "13:32");
	players[8] = create_player("player9", 62, "14:50");
	players[9] = create_player("player10", 15, "18:11");
	players[10] = create_player("player11", 59, "09:15");
	players[11] = create_player("player12", 155, "12:10");
	players[12] = create_player("player13", 821, "13:00");
	players[13] = create_player("player14", 24, "23:09");
	players[14] = create_player("player15", 92, "22:00");
	players[15] = 0;
	printf("Players unsorted:\n");
	print_arr(players);
	printf("\n\n");
	mergeSort(players);
	printf("Players Sorted:\n");
	print_arr(players);
	return (0);
}
