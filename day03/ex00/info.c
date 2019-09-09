#include "header.h"

void				get_max(int *max, struct s_node *root)
{
	if (root && root->left != 0)
		get_max(max, root->left);
	if (root && root->right != 0)
		get_max(max, root->right);
	if (root && root->value > *max)
		*max = root->value;
}

void				get_min(int *min, struct s_node *root)
{
	if (root->left != 0)
		get_min(min, root->left);
	if (root->right != 0)
		get_min(min, root->right);
	if (root->value < *min)
		*min = root->value;
}

void				get_elements(int *elements, struct s_node *root)
{
	if (root)
	{
		*elements += 1;
		get_elements(elements, root->right);
		get_elements(elements, root->left);
	}
}

int					get_height(struct s_node *root)
{
	if (root && root->left == 0 && root->right == 0)
		return (0);
	else if (root == 0)
		return (0);
	int left = get_height(root->left);
	int right = get_height(root->right);
	return (left > right ? left + 1 : right + 1);
}

int					is_bst(struct s_node *root)
{
	int		right = 0;
	int		left = 0;

	if (root == 0)
		return (1);
	if ((root->right && root->right->value > root->value) || root->right == 0)
		right = 1;
	if ((root->left && root->left->value <= root->value) || root->left == 0)
		left = 1;
	if (left && right)
		return (is_bst(root->right) && is_bst(root->left));
	return (0);
}

int					is_balanced(struct s_node *root)
{
	if (root == 0)
		return (1);
	int right = is_balanced(root->right);
	if (right)
	{
		int left = is_balanced(root->left);
		if (left)
		{
			int rightHeight = get_height(root->right);
			int leftHeight = get_height(root->left);
			int diff = rightHeight - leftHeight;
			return (diff >= -1 && diff <= 1);
		}
	}
	return (0);
}

struct s_info		getInfo(struct s_node *root)
{
	struct s_info	new;
	int				num;

//	if (root == 0)
//		return (0);
	new.height = (root ? get_height(root) : -1);
	new.isBalanced = is_balanced(root);
	new.isBST = is_bst(root);
	num = 0;
	get_elements(&num, root);
	new.elements = num;
	num = 2147483647;
	get_min(&num, root);
	new.min = num;
	num = -2147483648;
	get_max(&num, root);
	new.max = num;
	return (new);
}
