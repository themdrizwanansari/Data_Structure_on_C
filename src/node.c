#include "../lib/node.h"

Node *create_node (Node_Type type) {
	Node *node = (Node *) malloc (sizeof (Node));

	if (node != NULL) {
		node -> type = type;
		node -> name = NULL;
		node -> data = NULL;

		switch (node -> type) {		// setting up address count
			case
				N_Undefined:
				node -> address_list = NULL;
				break;
			case N_LinkedList:
			case N_Stack:
			case N_Queue:
			case N_Tree:
				node -> address_list = create_list (1);
				break;
			default:
				break;
		}
	}

	return node;
}

void delete_node (Node *node) {
	if (node != NULL) {
		delete_string (node -> name);
		delete_list (node -> address_list);
		delete_data (node -> data);
		free (node);
	}
}

void set_node_name (Node *node, int length, char *name) {
	if (node == NULL) {
		perror ("Error! => Node doesn't exist.\n");
		exit (1);
	}

	String *string = create_string (length, name);
	node -> name = string;
}

void display_node (Node *node) {
	printf ("*%s*", node -> name);
}