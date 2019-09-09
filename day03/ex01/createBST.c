#include "header.h"

int					get_height(struct s_node *root)
{
	if (root && root->left == 0 && root->right == 0)
		return (1);
	else if (root == 0)
		return (0);
	int left = get_height(root->left);
	int right = get_height(root->right);
	return (left > right ? left + 1 : right + 1);
}

struct s_node    *left_rotate(struct s_node *grand)
{
	struct s_node    *temp;

	if (grand->value == 8)
		printf("Made it all the way to left tree inbalance\n");
	temp = grand->right;
	grand->right = temp->left;
	temp->left = grand;
	return (temp);
}

struct s_node    *right_rotate(struct s_node *grand)
{
	struct s_node    *temp;

	temp = grand->left;
	grand->left = temp->right;
	temp->right = grand;
	return (temp);
}

void    handle_right_tree_inbalance(struct s_node **grand)
{
	int print = 0;
	if ((*grand)->value == 8)
		print = 1;

	if ((*grand)->right->left)
		(*grand)->right = right_rotate((*grand)->right);
	*grand = left_rotate(*grand);
	

	if (print)
	{
		printf("\n\nTHE VALUE AFTER ROTATION IS %d\n", (*grand)->value);
		printf("RIGHT IS %d AND LEFT is %d\n", (*grand)->right->value, (*grand)->left->value);
	}
}

void    handle_left_tree_inbalance(struct s_node **grand)
{
	if ((*grand)->left->right)
		(*grand)->left = left_rotate((*grand)->left);
	*grand = right_rotate(*grand);
}

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
	int	lenr = get_height((*head)->right);
	int	lenl = get_height((*head)->left);
	///
	if ((*head)->value >= 8)
		printf("Rightlen is %d and leftlen is %d Where node->val is %d and passed val is %d\n", lenr, lenl, (*head)->value, val);
	///
	if (lenl - lenr > 1)
		handle_left_tree_inbalance(head);
	else if(lenl - lenr < -1)
	{
		////
		int print = 0;
		if ((*head)->value == 8)
			printf("Going into solve the inbalance") && (print = 1);
		//////////////
		handle_right_tree_inbalance(head);
		if (print)
			printf("After fixing the inbalance, head is %d, r is %d, l is %d\n", (*head)->value, (*head)->right->value, (*head)->left->value);
		//////////////
	}
}

struct s_node	*createBST(int *arr, int n)
{
	struct s_node	*head;

	head = 0;
	for (int i = 0; i < n; i++)
		insert_node(&head, arr[i]);

	///
	//printf("Node->right->right->right->right = %d\n", head->right->right->right->right->value);
	///

	return (head);
}
