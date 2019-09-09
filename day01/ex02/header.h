#include <stdlib.h> //malloc

struct s_item {
	char *word;
	struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

struct s_node {
	char			*word;
	struct s_node	*next;
};

struct s_stack *stackInit(void);
void *pop(struct s_stack *stack);
void push(struct s_stack *stack, char *word);
void printReverseV2(struct s_node *lst);
