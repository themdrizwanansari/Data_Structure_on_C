#include "../lib/data.h"

Data *create_data (Data_Type data_type, int block_size, void *address) {
	Data *data = (Data*) malloc (sizeof (Data));

	if (data != NULL) {
		data -> type = DT_Undefined;
		data -> size = 0;
		data -> address = NULL;
	}

	if (data_type != DT_Undefined && block_size != 0) {
		data -> size = block_size;
		data -> address = malloc (data -> size);
		data -> address = memcpy (data -> address, address, data -> size);
	}

	return data;
}

void delete_data (Data *data) {
	if (data != NULL) {
		if (data -> address != NULL) {
			free (data -> address);
		}

		free (data);
	}
}

void display_data (Data *data) {
	if (data == NULL) {
		perror ("Data is empty");
		exit (1);
	}

	switch (data -> type) {
		case DT_Integer:
			printf ("%d", *((int*) data -> address));
			break;
		case DT_String:
			printf ("\"");
			print_string ((String*) data -> address);
			printf ("\"");
			break;
		case DT_Node:
			display_node (((Node*) data -> address));
			break;
		default:
			break;
	}
}

void display_data_properties (Data *data) {
	if (data == NULL) {
		perror ("Data is empty");
		exit (1);
	}

	switch (data -> type) {
		case DT_Integer:
			printf ("Data (Integer) : %d\n", *((int*) data -> address));
			break;
		case DT_String:
			printf ("Data (String) : ");
			display_string_properties (create_string (data -> size, data -> address));
			printf ("\n");
			break;
		case DT_Node:
			printf ("Data (Node) : ");
			display_node (((Node*) data -> address));
			printf ("\n");
			break;
		default:
			break;
	}
}