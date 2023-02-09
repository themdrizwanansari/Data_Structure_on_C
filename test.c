#include "./lib/tree.h"
#include "./lib/graph.h"


int main (int argc, char *argv[]) {
/*	String *string1 = create_string (5, "Hello");
	String *string2 = create_string (5, "World");
	display_string (string1);
	delete_string (&string1);
	printf ("%p\n", string1);
*/
/*	List *list = create_list (0);
	int x = 100;

	Data *data = create_data (DT_Integer, sizeof (int), &x);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (&data);

	data = create_data (DT_String, string1 -> length, string1 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (&data);

	data = create_data (DT_String, string2 -> length, string2 -> address);
	//display_data_properties (data);
	add_to_list (list, data, true);
//	display_list_addresses (list);
	delete_data (&data);

//	display_string (string1);
//	display_string (string2);
	//display_list (list);
	delete_list (&list);
*/
	//printf ("%d\n", are_strings_equal (string1, string2));
/*
	Linked_List *linked_list = create_linked_list ();
	display_linked_list (linked_list);
	Stack *stack = create_stack ();
	Queue *queue = create_queue ();

	Node *node = create_node (N_LinkedList);
	set_node_name (node, 5, "node1");
//	*(node -> address_list -> item_addresses + 1) = duplicate_string (string1);
//	display_node_details (node);

//	Node *node2 = duplicate_node (node);
//	display_node_details (node2);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (&node);
//	display_linked_list (linked_list);

	node = create_node (N_LinkedList);
	set_node_name (node, 5, "node2");
//	display_node_details (node);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (&node);
//	display_linked_list (linked_list);

	node = create_node (N_LinkedList);
	set_node_name (node, 5, "node3");
	//display_node (node);
	push (stack, node);
	enqueue (queue, node);
	attach_node_at_last (linked_list, node);
	delete_node (&node);
//	display_linked_list (linked_list);

	//display_linked_list (linked_list);

	//detach_node_from_last (linked_list, true);
	//display_linked_list (linked_list);
//	detach_node_from_first (linked_list, true);
//	display_linked_list (linked_list);
	//detach_node_from_first (linked_list, true);
	//detach_node_from_last (linked_list, true);
	//display_linked_list (linked_list);
	//detach_node_from_last (linked_list, true);
	//display_linked_list (linked_list);

	display_linked_list (linked_list);
	//delete_linked_list (&linked_list);
	delete_linked_list (&linked_list);
	display_linked_list (linked_list);
//	printf ("%p\n", linked_list);
//	printf ("%p\n", linked_list);

	display_stack (stack);
	Node *node1 = pop (stack);
	display_stack (stack);
	node1 = pop (stack);
	display_stack (stack);
	node1 = pop (stack);
	display_stack (stack);
	delete_stack (&stack);


	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);
	node1 = dequeue (queue);
	display_queue (queue);

	delete_queue (&queue);

	delete_node (&node1);
*/
/*
	Node *node;
	Node *p_node, *root_node;
	//printf ("gotcha\n");
	Tree *tree = create_tree ();

	node = create_node (N_Tree);
	set_node_name (node, 4, "root");
	set_root_node (tree, node);
	delete_node (&node);

	root_node = get_root_node (tree);
	p_node = root_node;

	node = create_node (N_Tree);
	set_node_name (node, 1, "A");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	node = create_node (N_Tree);
	set_node_name (node, 1, "B");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	p_node = get_Nth_child_node (p_node, 1);

	node = create_node (N_Tree);
	set_node_name (node, 1, "C");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	node = create_node (N_Tree);
	set_node_name (node, 1, "D");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	p_node = get_Nth_child_node (root_node, 2);

	node = create_node (N_Tree);
	set_node_name (node, 1, "E");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	node = create_node (N_Tree);
	set_node_name (node, 1, "F");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	p_node = get_Nth_child_node (p_node, 1);

	node = create_node (N_Tree);
	set_node_name (node, 1, "G");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	node = create_node (N_Tree);
	set_node_name (node, 1, "H");
	append_child_node (tree, p_node, node);
	delete_node (&node);

	//display_tree (tree);
	delete_tree (&tree);
*/

	Graph *graph = create_graph ();
	Vertex *vertex1 = NULL, *vertex2 = NULL, *vertex3 = NULL;

	vertex1 = create_node (N_Graph);
	add_vertex_to_graph (graph, vertex1);
	delete_node (&vertex1);

	vertex2 = create_node (N_Graph);
	add_vertex_to_graph (graph, vertex2);
	delete_node (&vertex2);

	vertex3 = create_node (N_Graph);
	add_vertex_to_graph (graph, vertex3);
	delete_node (&vertex3);

	vertex1 = get_vertex_by_id_from_graph (graph, 1); // id => index starting with 1 -- alternate will be get vertex by name string
	vertex2 = get_vertex_by_id_from_graph (graph, 2);
	vertex3 = get_vertex_by_id_from_graph (graph, 3);

	int x = 10;
	Data *weight = NULL;

	x = 10;
	weight = create_data (DT_Integer, sizeof (int), &x);
	add_edge_to_graph (graph, vertex1, vertex2, weight);
	delete_data (&weight);

	x = 20;
	weight = create_data (DT_Integer, sizeof (int), &x);
	add_edge_to_graph (graph, vertex2, vertex3, weight);
	delete_data (&weight);

	x = 30;
	weight = create_data (DT_Integer, sizeof (int), &x);
	add_edge_to_graph (graph, vertex1, vertex3, weight);
	delete_data (&weight);

	display_graph_details (graph);
	export_graph (graph);

	delete_graph (&graph);

	return 0;
}