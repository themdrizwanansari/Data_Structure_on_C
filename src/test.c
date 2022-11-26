#include "../lib/stack.h"

#include "../lib/queue.h"

int main (int argc, char *argv[]) {
	String *string1 = create_string (5, "Hello");
	String *string2 = create_string (5, "World");

/*	List *list = create_list (0);
	int x = 100;

	Data *data = create_data (DT_Integer, sizeof (int), &x);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (data);

	data = create_data (DT_String, string1 -> length, string1 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (data);

	data = create_data (DT_String, string2 -> length, string2 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (data);

//	display_string (string1);
//	display_string (string2);
	//display_list (list);
	delete_list (list);
*/
	//printf ("%d\n", are_strings_equal (string1, string2));

	Linked_List *linked_list = create_linked_list ();
//	display_linked_list (linked_list);
	Stack *stack = create_stack ();
	Queue *queue = create_queue ();

	Node *node = create_node (N_LinkedList);
	set_node_name (node, 5, "node1");
	//*(node -> address_list -> item_addresses + 1) = duplicate_string (string1);
//	display_node_details (node);

//	Node *node2 = duplicate_node (node);
//	display_node_details (node2);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (node);
//	display_linked_list (linked_list);

	node = create_node (N_LinkedList);
	set_node_name (node, 5, "node2");
//	display_node_details (node);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (node);
//	display_linked_list (linked_list);

	node = create_node (N_LinkedList);
	set_node_name (node, 5, "node3");
	//display_node (node);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (node);
//	display_linked_list (linked_list);

	delete_string (string1);
	delete_string (string2);

	//display_linked_list (linked_list);

	detach_node_from_last (linked_list, true);
	display_linked_list (linked_list);
//	detach_node_from_first (linked_list, true);
//	display_linked_list (linked_list);
	//detach_node_from_first (linked_list, true);
	detach_node_from_last (linked_list, true);
	display_linked_list (linked_list);
	detach_node_from_last (linked_list, true);
	display_linked_list (linked_list);

	delete_linked_list (linked_list);

	display_stack (stack);
	Node *node1 = pop (stack);
	display_stack (stack);
	node1 = pop (stack);
	display_stack (stack);
	node1 = pop (stack);
	display_stack (stack);
	delete_stack (stack);


	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);

	delete_queue (queue);

	return 0;
}