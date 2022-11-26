#include "../lib/list.h"

List *create_list (int size) {
	List *list = (List*) malloc (sizeof (List));

	if (list != NULL) {
		list -> item_count = 0;
		list -> item_addresses = NULL;

		while (size--) {
			add_to_list (list, NULL, false);
		}
	}

	return list;
}

List* duplicate_list (List *old_list) {
	List *new_list = create_list (old_list -> item_count);

	if (new_list != NULL) {
		for (int i = 0; i < new_list -> item_count; i++) {
			*(new_list -> item_addresses + i) = *(old_list -> item_addresses + i);
		}
	}

	return new_list;
}

void delete_list (List *list) {
	Data *data;
	int i;

	for (i = 0; i < list -> item_count; i++) {
		data = *(list -> item_addresses + i);
		delete_data (data);
	}

	if (list != NULL) {
		free (list);
	}
}

void add_to_list (List *list, Data *data, bool data_copy_needed) {
	if (list == NULL) {
		perror ("List not created\n");
		exit (1);
	}

	list -> item_addresses = (void**) realloc (list -> item_addresses, (list -> item_count + 1) * sizeof (void*));
	
	if (data_copy_needed) {
		*(list -> item_addresses + list -> item_count) = duplicate_data (data);
	} else {
		*(list -> item_addresses + list -> item_count) = data;
	}

	++ list -> item_count;
}

void display_list (List *list) {
	if (list -> item_count == 0) {
		printf ("List is Empty!\n");
		exit (1);
	}

	int i;
	Data *data;

	printf ("<List> (%d) := [", list -> item_count);

	for (i = 0; i < list -> item_count; i++) {
		data = *(list -> item_addresses + i);

		if (i != 0) {
			printf (", ");
		}

		display_data (data);
	}

	printf ("]\n");
}