#ifndef DATA_H
#define DATA_H

// ---------- x ----------

#include <stdio.h>
#include <stdlib.h>

#include "./string.h"
#include "./node.h"
#include "./list.h"

// ---------- x ----------

typedef enum DATA_TYPE {
	DT_Undefined
	, DT_Data
	, DT_Character
	, DT_Integer
	, DT_String
	, DT_Node
	, DT_List
	, DT_Linked_List
	, DT_Stack
} Data_Type;

typedef struct DATA {
	Data_Type type;
	int size;
	void* address;
} Data;

// ---------- x ----------

Data* create_data (Data_Type, int, void*);
void delete_data (Data*);
void display_data (Data*);
void display_data_properties (Data*);

#endif