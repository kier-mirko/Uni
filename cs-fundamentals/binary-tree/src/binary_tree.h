#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>
#include <stdbool.h>
#include "str_builder.h"

typedef struct Node Node;

Node* new_tree(int const value);
void binary_tree_add_child(Node* node, int const val, size_t const child_pos);
const char *traverse_preorder(Node* root);
void traverse_nodes(str_builder_t *sb, const char *pad, const char *pointer, Node* node, bool has_right);
int tree_height(Node* root);
bool tree_is_balanced(Node* root);
bool tree_is_full(Node* root);
bool tree_is_bst(Node* root);

#endif
