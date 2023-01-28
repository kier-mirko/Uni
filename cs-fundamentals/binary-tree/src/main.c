#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

int syntax_correct(char *s);

int main(void) {
	size_t n = 0;
	int val = 0;
	char *binary_s = NULL;

	printf("Insert number of nodes: ");
	scanf("%zu", &n);
	getchar();

	binary_s = malloc((n+1)*sizeof(char));

	printf("Enter rappresentation of binary tree as a sequence "
		"of 0 and 1: ");
	fgets(binary_s, n+1, stdin);

	if(binary_s != NULL)
		binary_s[strcspn(binary_s, "\n")] = 0;
	if (binary_s[0] == '0') {
		printf("Error: can't create binary tree\n");
		return EXIT_FAILURE;
	} else if(syntax_correct(binary_s) == 0) {
		printf("Error: string format incorrect\n");
		return EXIT_FAILURE;
	}

	int value;
	printf("Enter root value: ");
	scanf("%d", &value);
	Node* root = new_tree(value);

	for (size_t i = 1; i < strlen(binary_s); i++) {
		if(binary_s[i] == '1') {
			printf("Enter child value: ");
			scanf("%d", &val);
			binary_tree_add_child(root, val, i+1);
		}
	}

	printf("Root value: %s\n", traverse_preorder(root));
	printf("Tree height: %d\n", tree_height(root));
	printf("Tree is balanced: %s\n", tree_is_balanced(root)
		? "true" : "false");
	printf("Tree is full: %s\n", tree_is_full(root)
		? "true" : "false");
	printf("BST: %s\n", tree_is_bst(root) ? "true" : "false");

	return EXIT_SUCCESS;
}

int syntax_correct(char *s) {
	char *p;

	if(s == NULL)
		return 0;
	for(p = s; *p != '\0' && (*p == '0' || *p == '1'); ++p)
		;
	return *p == '\0' ? 1 : 0;
}
