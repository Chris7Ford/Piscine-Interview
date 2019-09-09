#include "header.h"
#include <unistd.h>

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
	print_tree(head);
}

int				main(void)
{
	struct s_node	*head;
	int		*arr;
	int		size;

//	size = 21;
//	size = 11;  This is the one i have marked out
	size = 6;
	arr = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		arr[i] = i;
	head = createBST(arr, size);
	analyze_tree(head);
	return (0);
}
