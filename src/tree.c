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
	List *list = create_list (tree -> node_count);
	int i, list_index = 0;
	Node *node, *child_node, *x_node;
	Stack *stack = create_stack ();

	node = get_root_node (tree);
	push_tree_node_to_stack (stack, node);

	while (stack -> size > 0) {
		x_node = pop (stack);
		node = x_node -> data -> address;

		*(list -> item_addresses + list_index++) = node;

		forget_data (&(x_node -> data));
		forget_list (&(x_node -> address_list));
		delete_node (&x_node);

		i = node -> address_list -> item_count;

		while (--i) {
			if (i < 0) {
				break;
			}

			child_node = *(node -> address_list -> item_addresses + i);
			push_tree_node_to_stack (stack, child_node);
		}
	}

	delete_stack (&stack);

	for (i = 0; i < list -> item_count; i++) {
		node = *(list -> item_addresses + i);
		forget_list (&(node -> address_list));
		delete_node (&node);
	}

	forget_list (&list);
	delete_list (&list);

	node = NULL;
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

	int i, child_count;
	int depth = 0, *x;
	Node *node, *child_node, *x_node;
	Node *depth_node;
	Stack *stack = create_stack ();
	Stack *depth_stack = create_stack ();

	stack -> name = create_string (10, "Node Stack");
	depth_stack -> name = create_string (11, "Depth Stack");

	node = get_root_node (tree);
	push_tree_node_to_stack (stack, node);
	push_depth_to_stack (depth_stack, 0);

	while (stack -> size > 0) {
		x_node = pop (stack);
		node = x_node -> data -> address;

		if (depth != 0) {
			for (i = 1; i < depth; i++) {
				printf ("\t|");
			}

			printf ("\n");

			for (i = 2; i < depth; i++) {
				printf ("\t|");
			}

			printf ("\t+--->");
		}

		display_node (node);
		printf ("\n");

		forget_data (&(x_node -> data));
		forget_list (&(x_node -> address_list));
		delete_node (&x_node);

		x = depth_stack -> first_node -> data -> address;
		-- *x;

		i = node -> address_list -> item_count;
		child_count = i - 1;

		if (*x <= 0 && child_count == 0) {
			depth_node = pop (depth_stack);
			forget_data (&(depth_node -> data));
			forget_list (&(depth_node -> address_list));
			delete_node (&depth_node);
		}

		depth = depth_stack -> size;

		if (child_count > 0) {
			push_depth_to_stack (depth_stack, child_count);
			depth = depth_stack -> size;
		}

		while (--i) {
			if (i < 0) {
				break;
			}

			child_node = *(node -> address_list -> item_addresses + i);
			push_tree_node_to_stack (stack, child_node);
		}
	}

	node = NULL;
	delete_stack (&depth_stack);
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

void append_child_node (Tree *tree, Node *parent_node, Node *child_node) {
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
	++ (tree -> node_count);
}

void push_tree_node_to_stack (Stack *stack, Node *node) {
	Node *stack_node = create_node (N_Stack);
	stack_node -> name = duplicate_string (node -> name);
	stack_node -> data = create_data (DT_Address, sizeof (void*), node);

	push (stack, stack_node);
	forget_data (&(stack_node -> data));
	delete_node (&stack_node);
}

void push_depth_to_stack (Stack *depth_stack, int child_count) {
	Node *depth_node = create_node (N_Stack);
	depth_node -> data = create_data (DT_Integer, sizeof (int), &child_count);

	push (depth_stack, depth_node);
	forget_data (&(depth_node -> data));
	delete_node (&depth_node);
}