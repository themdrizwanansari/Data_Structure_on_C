#include "../lib/string.h"

String* create_string (int length, char *str) {
	String *string = (String*) malloc (sizeof (String));

	if (string != NULL) {
		string -> length = 0;
		string -> address = NULL;
	}

	if (length > 0 && str != NULL) {
		string -> length = length;
		string -> address = malloc (length);

		if (string -> address != NULL) {
			string -> address = char_array_to_pointer (length, str);
		}
	}

	return string;
}

void delete_string (String *string) {
	if (string != NULL) {
		if (string -> address != NULL) {
			free (string -> address);
		}

		free (string);
	}
}

void display_string_properties (String *string) {
	printf ("String [%d]: ", string -> length);
	display_string (string);
	printf ("\n");
}

void display_string (String *string) {
	for (int i = 0; i < string -> length; i++) {
		printf ("%c", *(string -> address + i));
	}
}

char* char_array_to_pointer (int length, char *str) {
	char *string = (char*) malloc (length);
	string = memcpy (string, str, length);
	return string;
}

void concatenate_strings (int count, ...) {}

bool are_strings_equal (String *string1, String *string2)  {
	bool result = true;
	int i;

	if (string1 -> length != string2 -> length) {
		result = false;
	} else {
		for (i = 0; i < string1 -> length; i++) {
			if (*(string1 -> address + i) != *(string2 -> address + i)) {
				result = false;
				break;
			}
		}
	}

	return result;
}