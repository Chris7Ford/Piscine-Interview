#include "header.h"
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <string.h> //strdup

struct s_player	*create_player(char *name, int score)
{
	struct s_player	*new;
	new = malloc(sizeof(struct s_player));
	new->name = strdup(name);
	new->score = score;
	return (new);
}

void	print_arr(struct s_player **players)
{
	for (int i = 0; players[i]; i++)
		printf("%s: %d\n", players[i]->name, players[i]->score);
}

int		main(void)
{
	struct s_player	**players;
	int				size = 15;

	players = malloc(sizeof(struct s_player) * (size + 1));
	players[0] = create_player("player1", 55);
	players[1] = create_player("player2", 512);
	players[2] = create_player("player3", 12);
	players[3] = create_player("player4", 75);
	players[4] = create_player("player5", 11);
	players[5] = create_player("player6", 3);
	players[6] = create_player("player7", 642);
	players[7] = create_player("player8", 92);
	players[8] = create_player("player9", 62);
	players[9] = create_player("player10", 15);
	players[10] = create_player("player11", 59);
	players[11] = create_player("player12", 155);
	players[12] = create_player("player13", 821);
	players[13] = create_player("player14", 24);
	players[14] = create_player("player15", 92);
	players[15] = 0;
	printf("Players unsorted:\n");
	print_arr(players);
	printf("\n\n");
	quickSort(players);
	printf("Players Sorted:\n");
	print_arr(players);
	return (0);
}
