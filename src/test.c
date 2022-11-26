#include "../lib/data.h"

int main (int argc, char *argv[]) {
	String *string1 = create_string (5, "Hello");
	String *string2 = create_string (5, "Hello");

	int n = 10;
	Data *data = create_data (DT_Integer, sizeof (int), &n);

	display_string (string1);
	display_string (string2);

	printf ("%d\n", are_strings_equal (string1, string2));

	delete_string (string1);
	delete_string (string2);

	return 0;
}