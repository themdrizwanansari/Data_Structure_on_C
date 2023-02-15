let details = document .getElementById ("details");
//var raw_node_list = [];
var node_list = [];
var edge_list = [];
var node_list_by_level = [];
var stack = [];

class Coordinate {
	constructor (x = 0, y = 0) {
		this .x = x;
		this .y = y;
	}
}

class Node {
	constructor (id = "", index = 0, parent_node_index = new Node, child_node_indexes = [], position = new Coordinate) {
		this .id = id;
		this .index = index;
		this .parent_node_index = parent_node_index;
		this .child_node_indexes = child_node_indexes;
		this .position = position;
		this .level = 0;
	}
}

class Edge {
	constructor (id = "", index = 0, node1_index = 0, node2_index = 0, data = null) {
		this .id = id;
		this .index = index;
		this .node1_index = node1_index;
		this .node2_index = node2_index;
		this .data = data;
	}
}

function init () {
	pre_process_data ();
	draw_graph ();
}

function pre_process_data () {
	var i;

	for (i = 0; i < tree_node_list .length; i++) {
		node_list .push (new Node (
			tree_node_list [i][0]
			, i
			, get_node_index_by_id (tree_node_list [i][1])
			, []
			, new Coordinate (0, 0)
		));

		for (var j = 0; j < tree_node_list [i][2] .length; j++) {
			node_list [i] .child_node_indexes .push (get_node_index_by_id (tree_node_list [i][2][j]));
		}
	}

	for (i = 0; i < node_list .length; i++) {
		for (var j = 0; j < node_list [i] .child_node_indexes .length; j++) {
			node_list [node_list [i] .child_node_indexes [j]] .level = node_list [i] .level + 1;
		}
	}

	var max_level = 0;

	for (i = 0; i < node_list .length; i++) {
		if (max_level < node_list [i] .level) {
			max_level = node_list [i] .level;
		}
	}

	for (i = 0; i < max_level + 1; i++) {
		node_list_by_level [i] = [];
	}

	for (i = 0; i < node_list .length; i++) {
		node_list_by_level [node_list [i] .level] .push (i);
	}

	var x = 100;
	var y = 100;

	for (i = 0; i < node_list_by_level .length; i++) {
		level = node_list_by_level [i];

		x = 100;
		y += 100;

		for (var j = 0; j < level .length; j++) {
			x += 100;
			node_list [level [j]] .position .x = x;
			node_list [level [j]] .position .y = y;
		}
	}

	
	var edge_counter = 0;
	// first update edge list on the base of node indexes
	for (var i = 0; i < node_list .length; i++) {
		node = node_list [i];
		console .log (node .child_node_indexes);

		for (var j = 0; j < node .child_node_indexes .length; j++) {
			edge_list .push (new Edge (
				"E" + edge_counter
				, edge_counter ++
				, i
				, node .child_node_indexes [j]
				, null
			));
		}
	}
}

function get_node_index_by_id (id) {
	var i;

	for (i = 0; i < tree_node_list .length; i++) {
		if (tree_node_list [i][0] == id) {
			break;
		}
	}

	if (id == null || i >= tree_node_list .length) {
		i = -1;
	}

	return i;
}

function draw_graph () {
	let container = document .getElementById ("container");

	for (i = 0; i < edge_list .length; i++) {
		draw_edge (container, edge_list [i]);
	}

	for (i = 0; i < node_list .length; i++) {
		draw_node (container, node_list [i]);
	}
}

function draw_edge (container, edge = new Edge) {
	edge_diagram = document .createElementNS ("http://www.w3.org/2000/svg", "line");
	edge_diagram .setAttribute ("id", "E" + edge .index + "_diagram");
	edge_diagram .setAttribute ("class", "edge");
	edge_diagram .setAttribute ("x1", node_list [edge .node1_index] .position .x + "px");
	edge_diagram .setAttribute ("y1", node_list [edge .node1_index] .position .y + "px");
	edge_diagram .setAttribute ("x2", node_list [edge .node2_index] .position .x + "px");
	edge_diagram .setAttribute ("y2", node_list [edge .node2_index] .position .y + "px");
	set_edge_event_listeners (edge_diagram);
	container .appendChild (edge_diagram);
}

function draw_node (container, node = new node) {
	node_diagram = document .createElementNS ("http://www.w3.org/2000/svg", "circle");
	node_diagram .setAttribute ("id", "V" + node .index + "_diagram");
	node_diagram .setAttribute ("class", "node");
	node_diagram .setAttribute ("cx", node .position .x + "px");
	node_diagram .setAttribute ("cy", node .position .y + "px");
	node_diagram .setAttribute ("r", "20px");
	set_node_event_listeners (node_diagram);
	container .appendChild (node_diagram);
}

function set_node_event_listeners (node_diagram) {
	node_diagram .addEventListener ("mouseover", function (event) {
		event .target .style .stroke = "red";
		show_details (event .target);
	});

	node_diagram .addEventListener ("mouseout", function (event) {
		event .target .style .stroke = "black";
		hide_details ();
	});
}

function set_edge_event_listeners (edge_diagram) {
	edge_diagram .addEventListener ("mouseover", function (event) {
		event .target .style .stroke = "red";
		show_details (event .target);
	});

	edge_diagram .addEventListener ("mouseout", function (event) {
		event .target .style .stroke = "black";
		hide_details ();
	});
}

function show_details (element) {
	var hypertext = "";

	if (element .className .baseVal == "node") {
		let node = node_list [Number (element .id .substring (1, element .id .length - 8))];
		hypertext = "<h1>node</h1><h2>Index : " + node .index + "</h2><h2>Name : " + node .id + "</h2>";
	} else if (element .className .baseVal == "edge") {
		let edge = edge_list [Number (element .id .substring (1, element .id .length - 8))];
		hypertext = "<h1>Edge</h1><h2>Index : " + edge .index + "</h2><h2>Name : " + edge .id + "</h2>";
		hypertext += "<h2>"
						+ node_list [edge .node1_index] .id
						+ " -- ["
						+ ((edge .weight != null) ? edge .weight : "")
						+ "] -- "
						+ node_list [edge .node2_index] .id
						+ "</h2>";
	}

	document .getElementById ("details") .innerHTML = hypertext;
	document .getElementById ("details") .classList .remove ("hidden");
}

function hide_details () {
	document .getElementById ("details") .classList .add ("hidden");
	document .getElementById ("details") .innerHTML = "";
}