struct s_item {
	int				idx;
	struct s_item	*next;
};

struct s_stack {
	struct s_item *item;
};

struct s_stack *stackInit(void);
void *pop(struct s_stack *stack);
void push(struct s_stack *stack, int idx);
char	*console(void);
