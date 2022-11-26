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
	, DT_Address
} Data_Type;

typedef struct DATA {
	Data_Type type;
	int size;
	void* address;
} Data;

// ---------- x ----------

Data* create_data (Data_Type, int, void*);
Data* duplicate_data (Data*);
void delete_data (Data**);
void forget_data (Data **);
void display_data (Data*);
void display_data_properties (Data*);
void display_binary_data (int, BYTE*);

#endif