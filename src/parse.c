#include "helper.h"

// ########## ########## ########## ########## ##########

#define TAG_MAX 100
#define CONTENT_MAX 1000

typedef enum PROCESS_STATUS {
	None
	, Comment_Starts
	, Comment_Ends
	, Container_Name_Starts
	, Container_Starts
	, Container_Name_Ends
	, Container_Ends
	, Tag_Starts
	, Self_Closing_Starts
	, Self_Closing_Ends
	, Inside_Tag
	, Tag_Ends
} Process_Status;

// ########## ########## ########## ########## ##########

BYTE state_transition (BYTE, BYTE);

Process_Status process_state (Process_Status, int, int, char);

char tag_buffer [TAG_MAX];
int tag_length = 0;
char content_buffer [CONTENT_MAX];
int content_length = 0;

/*
	State Transition Table:
		+---+---+---+---+---+---+---+---+---+---+
		| <	| !	| -	| /	| > | A	| S	| E	| "	| x |
	+---+---+---+---+---+---+---+---+---+---+---+
	| 0	| 1   0   0   0   0   0   0   0   0   0	|
	+---+									 	+
	| 1	| 0   2   0   9   0   6   0   0   0	  0 |
	+---+										+
	| 2	| 0   0   3   0   0   0   0   0   0	  0 |
	+---+										+
	| 3	| 3   3   4   3   3   3   3   3   3	  3 |
	+---+										+
	| 4	| 3   3   5   3   3   3   3   3   3	  3 |
	+---+										+
	| 5	| 3   3   3   3   x   3   3   3   3	  3 |
	+---+										+
	| 6	| 6   6   6   8   x   6   7   7   0	  6 |
	+---+										+
	| 7	| 7   7   7   8   x   7   7   7   7	  7 |
	+---+										+
	| 8	| 7   7   7   7   x   7   7   7   7	  7 |
	+---+										+
	| 9	| 0   0   0   0   x   9   0   0   0	  0 |
	+---+---------------------------------------+
*/

BYTE transition_table [10][10] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	, {0, 2, 0, 9, 0, 6, 0, 0, 0, 0}
	, {0, 0, 3, 0, 0, 0, 0, 0, 0, 0}
	, {3, 3, 4, 3, 3, 3, 3, 3, 3, 3}
	, {3, 3, 5, 3, 3, 3, 3, 3, 3, 3}
	, {3, 3, 3, 3, 10, 3, 3, 3, 3, 3}
	, {6, 6, 6, 8, 10, 6, 7, 7, 0, 6}
	, {7, 7, 7, 8, 10, 7, 7, 7, 7, 7}
	, {7, 7, 7, 7, 10, 7, 7, 7, 7, 7}
	, {0, 0, 0, 0, 10, 9, 0, 0, 0, 0}
};

// ########## ########## ########## ########## ########## ########## ########## ########## ########## ##########

int main (int argc, char *argv[]) {
	if (argc < 3) {
		perror ("File not specified!\n");
		exit (1);
	}

	BYTE c;
	FILE *fpi = fopen (argv[1], "rb+");

	if (fpi == NULL) {
		perror ("Can't open input file!\n");
		exit (1);
	}

	FILE *fpo = fopen (argv[2], "wb+");

	if (fpo == NULL) {
		perror ("Can't open output file!\n");
		exit (1);
	}

	fseek (fpi, 1, SEEK_END);
	// unsigned long f_ic = 0;		// File Index Counter
	long f_sz = ftell (fpi);	// File SiZe
	//printf ("File Size: %ld bytes.\n", f_sz);
	rewind (fpi);

	long i;
	BYTE state = 0, previous_state;
	ssize_t sz;
	bool flag_copy = false;
	Process_Status process_status;
	Stack *stack = create_stack (0);
	Node *node;

	for (i = 0; i < f_sz; i++) {
		sz = fread (&c, 1, 1, fpi);
		previous_state = state;
		state = state_transition (state, c);
		// fprintf (fpo, "%d %c %d\n", previous_state, c, state);

		process_status = process_state (process_status, previous_state, state, c);

		if (process_status == Container_Starts && is_self_closing_tag (tag_buffer)) {
			process_status = Self_Closing_Ends;
		}

		switch (process_status) {
			case Container_Starts:
				fprintf (fpo, "<%s>\n", tag_buffer);
				push (stack, create_node (create_string (tag_buffer)));
				break;
			case Container_Ends:
				fprintf (fpo, "</%s>\n", tag_buffer);
				if (are_string_equal (tag_buffer, stack -> first_node -> name)) {
					node = pop (stack);
				}
				// push (stack, create_node (create_string (tag_buffer)));
				break;
			case Self_Closing_Ends:
				fprintf (fpo, "<%s/>\n", tag_buffer);
				// push (stack, create_node (create_string (tag_buffer)));
				break;
			default:
				break;
		}

		if (state == 10) {
			state = 0;
		}

		if (state == 8) {
			flag_copy = !flag_copy;
		}

		if (flag_copy) {
		//	fwrite (&c, 1, 1, fpo);
		}
	}

	display_stack (stack);
	//delete_stack (stack);

	fclose (fpo);
	fclose (fpi);

	return 0;
}

BYTE state_transition (BYTE current_state, BYTE symbol) {
	BYTE next_state = 0;
	BYTE symbol_index = 0;

	switch (symbol) {
		case '<':
			symbol_index = 0;
			break;
		case '!':
			symbol_index = 1;
			break;
		case '-':
			symbol_index = 2;
			break;
		case '/':
			symbol_index = 3;
			break;
		case '>':
			symbol_index = 4;
			break;
		case 'a':
			symbol_index = 5;
			break;
		case ' ':
			symbol_index = 6;
			break;
		case '\n':
			symbol_index = 7;
			break;
		case '"':
			symbol_index = 8;
			break;
		default:
			symbol_index = 9;		 // x = 10 (- 1)
			break;
	}

	if (isalnum (symbol)) {
		symbol_index = 5;
	}

	next_state = transition_table [current_state][symbol_index];

	return next_state;
}

Process_Status process_state (Process_Status old_status, int previous_state, int current_state, char symbol) {
	Process_Status new_status = None;

	if (previous_state == 1 && current_state == 3) { // comment tag starts
		content_buffer [content_length ++] = symbol;
		new_status = Comment_Starts;
	}

	if (previous_state == 5 && current_state == 10) { // comment tag ends
		content_length = 0;
		new_status = Comment_Ends;
	}

	if ((previous_state == 1 || previous_state == 6) && current_state == 6) { // container tag starts
		tag_buffer [tag_length ++] = symbol;

		/*if (strcmp (create_string (tag_length, tag_buffer), "aside") == 0) {
			printf ("found\n");
		}*/
		new_status = Container_Name_Starts;
	}

	if ((previous_state == 6 || previous_state == 7) && current_state == 10) { // container tag ends
		tag_buffer [tag_length ++] = symbol;
		// print_string (tag_length, tag_buffer);
/*
		if (strcmp (create_string (tag_length, tag_buffer), "aside>") == 0) {
			printf ("found\n");
		}
*/
		tag_buffer [tag_length - 1] = '\0';
		tag_length = 0;
		new_status = Container_Name_Starts;
	}

	if (previous_state == 9 && current_state == 9) {
		tag_buffer [tag_length ++] = symbol;
		new_status = Container_Name_Starts;
	}

	if (previous_state == 9 && current_state == 10) {
		tag_buffer [tag_length] = '\0';
		tag_length = 0;
		new_status = Container_Name_Ends;
	}

	if (previous_state == 8 && current_state == 10) {
		tag_buffer [tag_length] = '\0';
		tag_length = 0;
		new_status = Self_Closing_Starts;
	}

	if (current_state == 10) {
		tag_length = 0;
		content_length = 0;

		switch (new_status) {
			case Container_Name_Starts:
				new_status = Container_Starts;
				break;
			case Container_Name_Ends:
				new_status = Container_Ends;
				break;
			case Self_Closing_Starts:
				new_status = Self_Closing_Ends;
				break;
			default:
				break;
		}
	}

	return new_status;
}