#include "../lib/tree.h"

Tree* create_tree () {
	Tree *tree = (Tree*) malloc (sizeof (Tree));

	if (tree != NULL) {
		tree -> root_node = NULL;
		tree -> node_count = 0;
		tree -> breadth = 0;
		tree -> depth = 0;
	}

	return tree;
}

Tree* duplicate_tree (Tree *tree) {
	/*Tree *new_tree = create_tree ();
	return new_tree;*/
	return tree;
}

void delete_tree (Tree **tree_address) {
	if (*tree_address == NULL) {
		perror ("Tree does not exists to delete!");
		return;
	}

	Tree *tree = *tree_address;
	tree = NULL;
	ERASE (tree_address);
}

void display_tree (Tree *tree) {
	if (tree == NULL) {
		perror ("Tree does not exist to display");
		return;
	}

	if (tree -> node_count == 0) {
		perror ("Tree does not have any node to display");
		return;
	}

	Stack *stack = create_stack ();
	Node *node = get_root_node (tree);
	//int level = 0;
	int i;
	//display_node_details (node);
	//push (stack, node);
	display_node_details (node);
	display_node_details (*(node -> address_list -> item_addresses + 2));
	display_node_details (*(node -> address_list -> item_addresses + 1));
	//push (stack, *(node -> address_list -> item_addresses + 2));
	//push (stack, *(node -> address_list -> item_addresses + 1));
	//display_stack (stack);


	//while (stack -> size != 0) {
	//	node = pop (stack);
		//display_node_details (node);

		if (node == NULL) {
			//continue;
		}
		//display_node_details (node);
		i = node -> address_list -> item_count;
		//printf ("%d addresses\n", i);

		if (i <= 1) {
			//continue;
		}

		while (--i) {	// (i = 0) => parent address - will be ignored
			//display_node_details (*(node -> address_list -> item_addresses + i));
			//push (stack, *(node -> address_list -> item_addresses + i));
		}

		
	//}

	node = NULL;
	delete_stack (&stack);
}

void set_root_node (Tree *tree, Node *node) {
	if (tree == NULL) {
		perror ("Tree does not exist to add Root!");
		return;
	}

	if (node == NULL) {
		perror ("Node does not exist to add Root!");
		return;
	}

	if (tree -> root_node != NULL) {
		perror ("Tree already have root node!");
		return;
	}

	tree -> root_node = duplicate_node (node);
	*(tree -> root_node -> address_list -> item_addresses + 0) = NULL;
	++ tree -> node_count;
}

Node* get_root_node (Tree *tree) {
	if (tree == NULL) {
		perror ("Tree does not exist to add Root!");
		return NULL;
	}

	return tree -> root_node;
}

Node* get_Nth_child_node (Node *parent_node, int n) {
	Node *child_node = NULL;

	if (parent_node -> address_list -> item_count > n) {
		child_node = *(parent_node -> address_list -> item_addresses + n);
	}

	return child_node;
}

Node* get_parent_node (Node *node) {
	return NULL;
}

void append_child_node (Node *parent_node, Node *child_node) {
	if (parent_node == NULL) {
		perror ("Parent Node does not Exist to add child node!");
		return;
	}

	if (child_node == NULL) {
		perror ("Child Node does not Exist to add child node!");
		return;
	}

	child_node = duplicate_node (child_node);
	*(child_node -> address_list -> item_addresses + 0) = parent_node;
	add_to_list (parent_node -> address_list, child_node, false);
}