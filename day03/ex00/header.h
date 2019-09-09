# define COUNT 10

#include <stdio.h> //printf
#include <stdlib.h> //malloc

struct s_node {
	int value;
	struct s_node *left;
	struct s_node *right;
};

struct s_info {
	int min;
	int max;
	int elements;
	int height;
	int isBST;
	int isBalanced;
};

struct s_info		getInfo(struct s_node *root);
