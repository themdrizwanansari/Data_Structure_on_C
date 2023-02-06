#ifndef DATA_H
#define DATA_H

// ---------- x ----------

#include "./string.h"

// ---------- x ----------

typedef enum DATA_TYPE {
	DT_Undefined
	, DT_Binary
	, DT_Character
	, DT_Integer
	, DT_String
	, DT_Address
	, DT_Range
} Data_Type;

typedef struct DATA {
	Data_Type type;
	int size;
	void* address;
} Data;

// ---------- x ----------

Data* create_data (Data_Type data_type, int block_size, void *address);
Data* duplicate_data (Data *data);
void delete_data (Data **data_address);
void forget_data (Data **data_address);
void display_data (Data *data);
void display_data_properties (Data *data);
void display_binary_data (int size, BYTE *address);
Data* create_range_data (int start, int end);
void display_range_data (Data *data);
bool are_data_equal (Data *data1, Data *data2);

#endif