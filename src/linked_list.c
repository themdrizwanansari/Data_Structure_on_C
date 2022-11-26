#include "../lib/linked_list.h"

Linked_List *create_linked_list () {
	Linked_List *linked_list = (Linked_List*) malloc (sizeof (Linked_List));

	if (linked_list != NULL) {
		linked_list -> size = 0;
		linked_list -> first_node = NULL;
		linked_list -> last_node = NULL;
	}

	return linked_list;
}

void delete_linked_list (Linked_List *linked_list) {
    if (linked_list != NULL) {
        free (linked_list);
    }
}

void attach_node_at_last (Linked_List *linked_list, Node *node) {
	if (node == NULL) {
		perror ("Empty node is given to add in Linked List\n");
		exit (1);
	}

	if (node -> address_list == NULL) { // fix node addresses
		node -> address_list = create_list (2);
		*(node -> address_list -> item_addresses + 0) = NULL;
		*(node -> address_list -> item_addresses + 1) = NULL;
	}

	if (linked_list -> first_node == NULL) {
		linked_list -> first_node = node;
		linked_list -> last_node = node;
	} else {
		*(linked_list -> last_node -> address_list -> item_addresses + 1) = node;
		*(node -> address_list -> item_addresses + 0) = linked_list -> last_node;
		linked_list -> last_node = node;
	}

	++ linked_list -> size;
}

void attach_node_at_first (Linked_List *linked_list, Node *node) {
	if (node == NULL) {
		perror ("Empty node is given to add in Linked List\n");
		exit (1);
	}

	if (node -> address_list == NULL) { // fix node addresses
		node -> address_list = create_list (2);
		*(node -> address_list -> item_addresses + 0) = NULL;
		*(node -> address_list -> item_addresses + 1) = NULL;
	}

	if (linked_list -> first_node == NULL) {
		linked_list -> first_node = node;
		linked_list -> last_node = node;
	} else {
		*(node -> address_list -> item_addresses + 1) = linked_list -> first_node;
		*(linked_list -> first_node -> address_list -> item_addresses + 0) = node;
		linked_list -> first_node = node;
	}

	++ linked_list -> size;
}

void display_linked_list (Linked_List *linked_list) {
	printf ("<Linked List>(%d) := ", linked_list -> size);

	Node *node = linked_list -> first_node;

	for (int i = 0; i < linked_list -> size; i++) {
		if (i != 0) {
			printf (" -> ");
		}

		display_node (node);
		node = *(node -> address_list -> item_addresses + 1);
	}

	printf ("\n");
}

void detach_node_from_first (Linked_List *linked_list, bool node_delete_needed) {
	Node *node;

	if (linked_list != NULL) {
		if (linked_list -> size > 0) {
			node = linked_list -> first_node;
			linked_list -> first_node = *(linked_list -> first_node -> address_list -> item_addresses + 1);
			-- linked_list -> size;

			if (node_delete_needed) {
				free (node);
			}
		}
	}
}

void detach_node_from_last (Linked_List *linked_list, bool node_delete_needed) {
	Node *node;

	if (linked_list != NULL) {
		if (linked_list -> size > 0) {
			node = linked_list -> last_node;
			linked_list -> last_node = *(linked_list -> last_node -> address_list -> item_addresses + 0);
			-- linked_list -> size;

			if (node_delete_needed) {
				free (node);
			}
		}
	}
}