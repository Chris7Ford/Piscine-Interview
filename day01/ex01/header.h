#include <stdlib.h> //malloc

struct s_node {
	char			*word;
	struct s_node	*next;
};

 void printReverse(struct s_node *lst);
