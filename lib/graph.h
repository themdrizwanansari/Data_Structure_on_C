#ifndef GRAPH_H
#define GRAPH_H

// ---------- x ----------

#include "./node.h"
#include "./stack.h"
#include "./queue.h"

// ---------- x ----------

typedef Node Vertex;

typedef struct EDGE {
	String* name;
	Vertex* vertex1;
	Vertex* vertex2;
	Data* weight;
} Edge;

typedef struct ROUTE {
	Data* data;
	Vertex* vertex;
} Route;

typedef struct GRAPH {
	Vertex* any_vertex;		// any one node address of the graph as the start point
	List* vertex_list;
	List* edge_list;
} Graph;

// ---------- x ----------

Graph* create_graph (void);
void delete_graph (Graph **graph_address);
void display_graph (Graph *graph);
void export_graph (Graph *graph);
void add_vertex_to_graph (Graph *graph, Vertex *vertex);
Edge* create_edge_for_graph (Graph *graph, Vertex *vertex1, Vertex *vertex2, Data *weight);
void display_edge (Edge *edge);
void display_edge_list (List *edge_list);
Route* create_route_data (Data *data, Vertex *vertex);
void add_edge_to_graph (Graph *graph, Vertex *vertex1, Vertex *vertex2, Data *weight);
void display_graph (Graph *graph);
void display_graph_details (Graph *graph);
Vertex* get_vertex_by_id_from_graph (Graph *graph, int id);

#endif