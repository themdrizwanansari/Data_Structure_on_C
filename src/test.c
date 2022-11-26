#include "../lib/linked_list.h"

int main (int argc, char *argv[]) {
	String *string1 = create_string (5, "Hello");
	String *string2 = create_string (5, "World");

	List *list = create_list (0);
	int x = 100;

	Data *data = create_data (DT_Integer, sizeof (int), &x);
	//display_data_properties (data);
	add_to_list (list, data, true);
	delete_data (data);

	data = create_data (DT_String, string1 -> length, string1 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
	delete_data (data);

	data = create_data (DT_String, string2 -> length, string2 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
	delete_data (data);

//	display_string (string1);
//	display_string (string2);
	//display_list (list);
	delete_list (list);

	//printf ("%d\n", are_strings_equal (string1, string2));

	Linked_List *linked_list = create_linked_list ();

	Node *node = create_node (N_LinkedList);
	set_node_name (node, 5, "node1");
	//display_node (node);
	attach_node_at_last (linked_list, node);
//	delete_node (node);

	node = create_node (N_LinkedList);
	set_node_name (node, 5, "node2");
	//display_node (node);
	attach_node_at_last (linked_list, node);
//	delete_node (node);

	delete_string (string1);
	delete_string (string2);

	display_linked_list (linked_list);

	detach_node_from_first (linked_list, true);
	display_linked_list (linked_list);
	detach_node_from_first (linked_list, true);

	display_linked_list (linked_list);

	delete_linked_list (linked_list);

	return 0;
}