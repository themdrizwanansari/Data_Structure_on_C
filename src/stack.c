#include "../lib/stack.h"

Stack *create_stack () {
	return create_linked_list ();
}

void delete_stack (Stack *stack) {
    delete_linked_list (stack);
}

void display_stack (Stack *stack) {
	printf ("<Stack>(%d) := ", stack -> size);

	Node *node = stack -> first_node;

	for (int i = 0; i < stack -> size; i++) {
		if (i != 0) {
			printf ("\n|__*__| => ");
		}

		display_node (node);
		node = *(node -> address_list -> item_addresses + 1);
	}

	printf ("\n");
}

void push (Stack *stack, Node *node) {
    attach_node_at_first (stack, node);
}

Node *pop (Stack *stack) {
    Node *node = stack -> first_node;
    detach_node_from_first (stack, false);
    return node;
}