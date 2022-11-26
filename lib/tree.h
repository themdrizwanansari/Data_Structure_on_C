#ifndef TREE_H
#define TREE_H

// ---------- x ----------

#include "./node.h"
#include "./stack.h"

// ---------- x ----------

typedef struct TREE {
	Node* root_node;
	int node_count;
	int breadth;
	int depth;
} Tree;

// ---------- x ----------

Tree* create_tree ();
Tree* duplicate_tree (Tree*);
void delete_tree (Tree**);
void display_tree (Tree*);
void set_root_node (Tree*, Node*);
Node* get_root_node (Tree*);
Node* get_Nth_child_node (Node*, int);
Node* get_parent_node (Node*);
void append_child_node (Node*, Node*);

#endif