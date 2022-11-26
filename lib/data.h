#ifndef DATA_H
#define DATA_H

// ---------- x ----------

#include "./string.h"

#define BYTE unsigned char

// ---------- x ----------

typedef enum DATA_TYPE {
	DT_Undefined
	, DT_Binary
	, DT_Character
	, DT_Integer
	, DT_String
} Data_Type;

typedef struct DATA {
	Data_Type type;
	int size;
	void* address;
} Data;

// ---------- x ----------

Data* create_data (Data_Type, int, void*);
Data* create_new_data_from_old_data (Data*);
void delete_data (Data*);
void display_data (Data*);
void display_data_properties (Data*);
void display_binary_data (int, BYTE*);

#endif