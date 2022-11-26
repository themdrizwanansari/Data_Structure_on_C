#include "../lib/list.h"

int main (int argc, char *argv[]) {
	String *string1 = create_string (5, "Hello");
	String *string2 = create_string (5, "World");

	List *list = create_list (0);
	int x = 100;

	Data *data = create_data (DT_Integer, sizeof (int), &x);
	//display_data_properties (data);
	add_to_list (list, data);
	delete_data (data);

	data = create_data (DT_String, string1 -> length, string1 -> address);
	//display_data_properties (data);
	add_to_list (list, data);
	delete_data (data);

	data = create_data (DT_String, string2 -> length, string2 -> address);
	//display_data_properties (data);
	add_to_list (list, data);
	delete_data (data);

//	display_string (string1);
//	display_string (string2);
	display_list (list);
	//delete_list (list);

	//printf ("%d\n", are_strings_equal (string1, string2));

	delete_string (string1);
	delete_string (string2);

	return 0;
}