#ifndef NODE_H
#define NODE_H

// ---------- x ----------

#include "./data.h"
#include "./list.h"

// ---------- x ----------

typedef struct NODE {
	String* name;
	List* address_list;
	Data* data;
} Node;

// ---------- x ----------

Node* create_node (String*);
void delete_node (Node*);
void display_node (Node*);

#endif