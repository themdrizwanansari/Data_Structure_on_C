#ifndef LIST_H
#define LIST_H

// ---------- x ----------

#include "./data.h"

// ---------- x ----------

typedef struct LIST {
	int item_count;
	void** item_addresses;	// addresses of Data pointers --default casting should be to Data** in functions
} List;

// ---------- x ----------

List* create_list (int);
List* duplicate_list (List*);
void forget_list (List**);
void delete_list (List**);
void add_to_list (List*, void*, bool);
void display_list (List*);
void list_append (List*, int, void*);
void display_list_addresses (List*);

#endif