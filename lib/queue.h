#ifndef QUEUE_H
#define QUEUE_H

// ---------- x ----------

#include "./linked_list.h"

// ---------- x ----------

typedef Linked_List Queue;

// ---------- x ----------

Queue* create_queue ();
void delete_queue (Queue*);
void display_queue (Queue*);
void enqueue (Queue*, Node*);
Node* dequeue (Queue*);

#endif