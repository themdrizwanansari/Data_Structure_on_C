#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// ---------- x ----------

#include "./node.h"

// ---------- x ----------

typedef struct LINKED_LIST {
	String* name;
	int size;
	Node* first_node;
	Node* last_node;
} Linked_List;

// ---------- x ----------

Linked_List* create_linked_list ();
void delete_linked_list (Linked_List**);
void display_linked_list (Linked_List*);
void attach_node_at_first (Linked_List*, Node*);
void attach_node_at_last (Linked_List*, Node*);
void detach_node_from_first (Linked_List*, bool);
void detach_node_from_last (Linked_List*, bool);

#endif