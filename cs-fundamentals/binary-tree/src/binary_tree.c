#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "binary_tree.h"

struct Node {
	int value;
	size_t pos;
	Node *left;
	Node *right;
};

Node*
new_tree(const int value)
{
	Node* root = malloc(sizeof(Node));
	if(root == (void*)0)
		exit(EXIT_FAILURE);
	*root = (Node) {.left = (void*)0, .right = (void*)0, .pos = 1, .value = value};
        return root;
}
void
binary_tree_add_child(Node* node, int const val, size_t const child_pos)
{
        if(node->left != (void*)0)
                binary_tree_add_child(node->left, val, child_pos);

        if(node->right != (void*)0)
                binary_tree_add_child(node->right, val, child_pos);

        if(child_pos == node->pos * 2) {
                Node *child = malloc(sizeof(Node));
                if(child == (void*)0)
                        exit(EXIT_FAILURE);

                *child = (Node) {.left = (void*)0, .right = (void*)0, .value = val,
                                 .pos = child_pos,};
		node->left = child;
	} else if(child_pos == node->pos * 2 + 1) {
		Node *child = malloc(sizeof(Node));
		if(child == (void*)0)
			exit(EXIT_FAILURE);
                *child = (Node) {.left = (void*)0, .right = (void*)0, .value = val,
                                 .pos = child_pos,};
		node->right = child;
	}
}

const char *
traverse_preorder(Node* root)
{
	if(root == (void*)0)
		return "";

	str_builder_t *sb;
	sb = str_builder_create();
	str_builder_add_int(sb,  root->value);

	const char *right_pointer = "└── Right value: ";
	const char *left_pointer = (root->right != (void*)0) ? "├── Left value:  "
		: "└── Left value:  ";
	traverse_nodes(sb, "", left_pointer, root->left, root->right != (void*)0);
	traverse_nodes(sb, "", right_pointer, root->right, false);

	return str_builder_peek(sb);
}

void
traverse_nodes(str_builder_t *sb, const char pad[static 1], const char pointer[static 1],
		Node* node, bool has_right)
{
	if(node != (void*)0) {
		str_builder_add_char(sb, '\n');
		str_builder_add_str(sb, pad, 0);
		str_builder_add_str(sb, pointer, 0);
		str_builder_add_int(sb, node->value);

		str_builder_t *pad_builder;
		pad_builder = str_builder_create();
		str_builder_add_str(pad_builder, pad, 0);

		if(has_right == 1) {
			str_builder_add_str(pad_builder, "│  ", 0);
		} else {
			str_builder_add_str(pad_builder, "   ", 0);
		}

		const char *right_pointer = "└── Right value: ";
		const char *left_pointer = (node->right != (void*)0)
			? "├── Left value:  " : "└── Left value:  ";

		traverse_nodes(sb, str_builder_peek(pad_builder), left_pointer,
			       node->left, node->right != (void*)0);
		traverse_nodes(sb, str_builder_peek(pad_builder), right_pointer,
			       node->right, false);
	}
}

int
tree_height(Node *root)
{
	int left_height = 0, right_height = 0;

	if(root == (void*)0)
		return 0;

	left_height = tree_height(root->left);
	right_height = tree_height(root->right);

	return (left_height >= right_height ? left_height : right_height) + 1;
}

bool
tree_is_balanced(Node* root)
{
	if(root == (void*)0)
		return 1;

	int height_l = tree_height(root->left);
	int height_r = tree_height(root->right);

	bool is_left_balanced = tree_is_balanced(root->left);
	bool is_right_balanced = tree_is_balanced(root->right);

	return ((height_l - height_r) <= 1 && is_left_balanced
		&& is_right_balanced) ? true : false;
}

bool
tree_is_full(Node* root)
{
	if(root == 0)
		return true;
	if(root->left == 0 && root->right == 0)
		return true;
	if(root->left && root->right)
		return tree_is_full(root->left) && tree_is_full(root->right);
	return false;
}

bool
tree_is_bst(Node* root)
{
	if(root == (void*)0)
		return true;
	if(root->left && root->left->value > root->value)
		return false;
	if(root->right && root->right->value < root->value)
		return false;
	return tree_is_bst(root->left) && tree_is_bst(root->right);
}
