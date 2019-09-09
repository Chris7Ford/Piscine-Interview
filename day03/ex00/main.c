#include "header.h"
#include <unistd.h>

struct s_node	*create_node(int val)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	new->value = val;
	new->left = 0;
	new->right = 0;
	return (new);
}

void			insert_node(struct s_node **head, int val)
{
	if (head == 0)
		return;
	if (*head == 0)
	{
		*head = create_node(val);
		return ;
	}
	if (val > (*head)->value)
	{
		if ((*head)->right)
			insert_node(&((*head)->right), val);
		else
			(*head)->right = create_node(val);
	}
	else
	{
		if ((*head)->left)
			insert_node(&((*head)->left), val);
		else
			(*head)->left = create_node(val);
	}
}

void print2DUtil(struct s_node *root, int space) 
{ 
    if (root == NULL) 
        return; 
  
    space += COUNT; 
  
    print2DUtil(root->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->value); 
  
    print2DUtil(root->left, space); 
} 
  
void print_tree(struct s_node *root) 
{ 
	print2DUtil(root, 0); 
} 

void			analyze_tree(struct s_node *head)
{
	struct s_info	info;

	print_tree(head);
	info = getInfo(head);
	printf("Tree max is %d\n", info.max);
	printf("Tree min is %d\n", info.min);
	printf("Number of elements: %d\n", info.elements);
	printf("Tree height (number of edges): %d\n", info.height);
	//wrong
	printf("Is is a binary search tree? %s", info.isBST ? "Yes\n" : "Not quite\n");
	printf("Is it balanced? %s", info.isBalanced ? "Yes\n" : "Not quite\n");
}

int				main(void)
{
	struct s_node	*head;

	head = 0;
	insert_node(&head, 10);
	insert_node(&head, 15);
	insert_node(&head, 5);
	insert_node(&head, 7);
	insert_node(&head, 17);
	insert_node(&head, 20);
	analyze_tree(head);
	return (0);
}
