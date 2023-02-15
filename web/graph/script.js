let details = document .getElementById ("details");

class Coordinate {
	constructor (x = 0, y = 0) {
		this .x = x;
		this .y = y;
	}
}

class Vertex {
	constructor (id = "", index = 0, position = new Coordinate) {
		this .id = id;
		this .index = index;
		this .position = position;
	}
}

class Edge {
	constructor (id = "", index = 0, vertex1_index = 0, vertex2_index = 0, weight) {
		this .id = id;
		this .index = index;
		this .vertex1_index = vertex1_index;
		this .vertex2_index = vertex2_index;
		this .weight = weight;
	}
}

var vertices = [];
var edges = [];

function init () {
	pre_process_data ();
	draw_graph ();
}

function pre_process_data () {
	// first update edge list on the base of vertex indexes
	for (var i = 0; i < edge_list .length; i++) {
		edge_list [i] = new Edge (
			edge_list [i][0]
			, i
			, vertex_list .indexOf (edge_list [i][1])
			, vertex_list .indexOf (edge_list [i][2])
			, edge_list [i][3]
		);
	}

	// update vertex list with vertex objects
	let angle_step = (2 * Math .PI) / vertex_list .length;
	let radius = 50 + Math .floor ((vertex_list .length * 20) / Math .PI);
	let angle = -Math .PI;

	for (i = 0; i < vertex_list .length; i++) {
		var x = 600 + Math .floor (radius * Math .cos (angle));
		var y = 300 + Math .floor (radius * Math .sin (angle));
		vertex_list [i] = new Vertex (vertex_list [i], i, new Coordinate (x, y));
		angle += angle_step;
	}

	console .log (vertex_list);
	console .log (edge_list);
}

function draw_graph () {
	let container = document .getElementById ("container");

	for (i = 0; i < edge_list .length; i++) {
		draw_edge (container, edge_list [i]);
	}

	for (i = 0; i < vertex_list .length; i++) {
		draw_vertex (container, vertex_list [i]);
	}
}

function draw_edge (container, edge = new Edge) {
	edge_diagram = document .createElementNS ("http://www.w3.org/2000/svg", "line");
	edge_diagram .setAttribute ("id", "E" + edge .index + "_diagram");
	edge_diagram .setAttribute ("class", "edge");
	edge_diagram .setAttribute ("x1", vertex_list [edge .vertex1_index] .position .x + "px");
	edge_diagram .setAttribute ("y1", vertex_list [edge .vertex1_index] .position .y + "px");
	edge_diagram .setAttribute ("x2", vertex_list [edge .vertex2_index] .position .x + "px");
	edge_diagram .setAttribute ("y2", vertex_list [edge .vertex2_index] .position .y + "px");
	set_edge_event_listeners (edge_diagram);
	container .appendChild (edge_diagram);
}

function draw_vertex (container, vertex = new Vertex) {
	vertex_diagram = document .createElementNS ("http://www.w3.org/2000/svg", "circle");
	vertex_diagram .setAttribute ("id", "V" + vertex .index + "_diagram");
	vertex_diagram .setAttribute ("class", "vertex");
	vertex_diagram .setAttribute ("cx", vertex .position .x + "px");
	vertex_diagram .setAttribute ("cy", vertex .position .y + "px");
	vertex_diagram .setAttribute ("r", "20px");
	set_vertex_event_listeners (vertex_diagram);
	container .appendChild (vertex_diagram);
}

function set_vertex_event_listeners (vertex_diagram) {
	vertex_diagram .addEventListener ("mouseover", function (event) {
		event .target .style .stroke = "red";
		show_details (event .target);
	});

	vertex_diagram .addEventListener ("mouseout", function (event) {
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

	if (element .className .baseVal == "vertex") {
		let vertex = vertex_list [Number (element .id .substring (1, element .id .length - 8))];
		hypertext = "<h1>Vertex</h1><h2>Index : " + vertex .index + "</h2><h2>Name : " + vertex .id + "</h2>";
	} else if (element .className .baseVal == "edge") {
		let edge = edge_list [Number (element .id .substring (1, element .id .length - 8))];
		hypertext = "<h1>Edge</h1><h2>Index : " + edge .index + "</h2><h2>Name : " + edge .id + "</h2>";
		hypertext += "<h2>"
						+ vertex_list [edge .vertex1_index] .id
						+ " -- ["
						+ edge .weight
						+ "] -- "
						+ vertex_list [edge .vertex1_index] .id
						+ "</h2>";
	}

	document .getElementById ("details") .innerHTML = hypertext;
	document .getElementById ("details") .classList .remove ("hidden");
}

function hide_details () {
	document .getElementById ("details") .classList .add ("hidden");
	document .getElementById ("details") .innerHTML = "";
}