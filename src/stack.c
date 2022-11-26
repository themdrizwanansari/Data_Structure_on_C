#include "../lib/stack.h"

Stack *create_stack () {
	return create_linked_list ();
}

void delete_stack (Stack **stack_address) {
	delete_linked_list (stack_address);
}

void display_stack (Stack *stack) {
	printf ("<Stack>(%d) :=\n", stack -> size);

	if (stack -> size == 0) {
		perror ("Stack is Empty!");
		return;
	}

	Node *node = stack -> first_node;

	for (int i = 0; i < stack -> size; i++) {
		if (i < stack -> size) {
			printf ("\t|__*__| => ");
		}

		display_node_details (node);
		node = *(node -> address_list -> item_addresses + 1);
	}

	printf ("\n");
}

void push (Stack *stack, Node *node) {
	attach_node_at_first (stack, node);
	stack -> first_node -> type = N_Stack;
}

Node *pop (Stack *stack) {
	Node *node = duplicate_node (stack -> first_node);
	detach_node_from_first (stack, true);
	return node;
}