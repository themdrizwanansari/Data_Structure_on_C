#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

// ---------- x ----------

typedef struct STRING {
	int length;
	char* address;
} String;

// updated version of free to avoid dangling pointer
#define ERASE(address) {\
	free (*address);\
	*address = NULL;\
}

// ---------- x ----------

String* create_string (int, char*);					// creates string object // pass NULL as argument if empty string to be created
String* duplicate_string (String*);
void delete_string (String**);						// frees string object from memory
void display_string (String*);						// prints only string part
void display_raw_string (int, char*);				// prints string // takes length and address pointer
void display_string_properties (String*);			// prints whole description
char* char_array_to_pointer (int, char*);			// converts character array to string object
void concatenate_strings (int, ...);				// concatenates multiple string objects
bool are_strings_equal (String*, String*);			// checks if strings are same by value or not, does not check by address

#endif