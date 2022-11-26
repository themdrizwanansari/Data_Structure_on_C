#ifndef LIST_H
#define LIST_H

// ---------- x ----------

#include "./data.h"

// ---------- x ----------

typedef struct LIST {
	int item_count;
	void** item_addresses;
} List;

// ---------- x ----------

List* create_list (int);
void add_to_list (List*, Data*);
void display_list (List*);
void delete_list (List*);
void list_append (List*, int, void*);

#endif