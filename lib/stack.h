#ifndef STACK_H
#define STACK_H

// ---------- x ----------

#include "./linked_list.h"

// ---------- x ----------

typedef Linked_List Stack;

// ---------- x ----------

Stack* create_stack ();
void delete_stack (Stack*);
void display_stack (Stack*);
void push (Stack*, Node*);
Node* pop (Stack*);

#endif