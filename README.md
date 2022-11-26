# Parser
To parse various languages

## Custom C Library Architecture

### Dependency Diagram =>

![Image](./xml/media/library_structure.png "Library Structure")

---

## Data Structures & Utility Functions

### **-: String.h :-**
[=> _to store bunch of characters together in memory_]

#### **Included Libraries**

![Image](./xml/media/string.png "String")

- Includes standard C library header files.
	- #include <stdio.h> => input / output
	- #include <stdlib.h> => dynamic memory allocation / de-allocation / re-allocation
	- #include <string.h> => memory copy 
	- #include <stdarg.h> => variable number of arguments
	- #include <stdbool.h> => true / false

#### **Data Structure**

- String has a length and a starting memory address

```
	typedef struct STRING {
		int length;
		char* address;
	} String;
```

| Data Type | Varable Name | Usage |
| :---: | :---: | :---: |
| Integer | Length | to store the length value or the number of characters of the string |
| Character Pointer | Address | to store the character type dynamic memory address of the string |

ERASE Macro (Pre-Processor) Function
	- Creating a univarsal alternative of freeing memory and assigning to NULL aka (void*)0
	- This is irrespective of input datatype

```
	#define ERASE(address) {\
		free (*address);\
		*address = NULL;\
	}
```

#### **Utility Functions**

- Create String
	- Takes
		1. length of the string
		2. Character Array or Pointer
	- Shows
		- Error if Empty string is given
	- Returns
		- Null if length is Zero
		- Pointer for String object

<br>

- Delete String
	- Takes
		1. Address of Pointer for String object
	- Shows
		- Error if Empty string is given
	- Returns
		- Nothing

<br>

- Display String
	- Takes
		1. Pointer for String object
	- Shows
		- Error if Empty string is given
		- Prints only char sequence
		- No new-line gets printed
	- Returns
		- Nothing

<br>

- Display Raw String
	- Takes
		1. Length
		2. Character Array or Pointer
	- Shows
	- Returns
		- Nothing

<br>

- Display String Properties
	- Takes
		1. Pointer for String object
	- Shows
	- Returns
		- Nothing

<br>

- Char Array To Pointer
	- Takes
		1. Length of Character Array
		2. Character Array
	- Shows
		- Nothing
	- Returns
		- Pointer for dynamic memory block

<br>

- Concatenate Strings
	- Takes
		1. Number of input string objects
		2. all the pointers for stgring objects (variable number of inputs)
	- Shows
		- Nothing
	- Returns
		- Pointer to the concatenated string object

<br>

- Are Strings Equal
	- Takes
		1. Pointer for first String object
		2. Pointer for second String object
	- Shows
		- Nothing
	- Returns
		- Boolean (True / False) value
___

### **-: Data.h :-**
[=> _to store any type of data in memory_]

#### **Included Libraries**

![Image](./xml/media/data.png "Data")

#### **Data Structure**

- Data has type, block size, and a starting memory address

```
	typedef enum DATA_TYPE {
		DT_Undefined
		, DT_Binary
		, DT_Character
		, DT_Integer
		, DT_String
		, DT_Address
	} Data_Type;

	typedef struct DATA {
		Data_Type type;
		int size;
		void* address;
	} Data;
```

| Data Type | Varable Name | Usage |
| :---: | :---: | :---: |
| Enumeration | Type | to store custom datatype for type casting memory block |
| Integer | Size | to store the data block size |
| Void Pointer | Address | to store starting address for the data block in memory |

#### **Utility Functions**

- Create Data
	- Takes
		1. datatype (enum) for data block
	- Shows
		- Nothing
	- Returns
		- Pointer for Data object

<br>

- Duplicate Data
	- Takes
		1. Pointer to Data object
	- Shows
		- Nothing
	- Returns
		- Pointer for a new Data object with same values

<br>

- Forget Data
	- Takes
		1. Address of the Pointer to Data object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Delete Data
	- Takes
		1. Address of the Pointer to Data object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display Data
	- Takes
		1. Pointer to Data object
	- Shows
		- Formatted data according to datatype
	- Returns
		- Nothing

<br>

- Display Data Properties
	- Takes
		1. Pointer to Data object
	- Shows
		- Formatted data according to datatype
	- Returns
		- Nothing

<br>

- Display Binary Data
	- Takes
		1. Pointer to Data object
	- Shows
		- Data bytes in hexadecimal format value
	- Returns
		- Nothing

<br>

___

### **-: List.h :-**
[=> _to store list of any data in memory_]

#### **Included Libraries**

![Image](./xml/media/list.png "List")

#### **Data Structure**

- List has item count, item addresses

```
	typedef struct LIST {
		int item_count;
		void** item_addresses;
	} List;
```

| Data Type | Varable Name | Usage |
| :---: | :---: | :---: |
| Integer | Item Count | to store number of items in the list |
| Void Pointer of Pointers | Item Addresses | to store addresses of each data block in memory |

#### **Utility Functions**

- Create List
	- Takes
		1. Number of items
	- Shows
		- Nothing
	- Returns
		- Pointer to List object

<br>

- Duplicate List
	- Takes
		1. Pointer to List object
	- Shows
		- Nothing
	- Returns
		- New Pointer to copied List object

<br>

- Forget List
	- Takes
		1. Address of Pointer to List object
	- Shows
		- Nothing
	- Returns
		- New Pointer to copied List object

<br>

- Delete List
	- Takes
		1. Address of Pointer to List object
	- Shows
		- Nothing
	- Returns
		- New Pointer to copied List object

<br>

- Add to List
	- Takes
		1. Pointer to List object
		2. Pointer to Data
		3. Is data copy needed or not
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display List
	- Takes
		1. Pointer to List object
	- Shows
		- Displays data for each item in the list
	- Returns
		- Nothing

<br>

- Display List Addresses
	- Takes
		1. Pointer to List object
	- Shows
		- Displays data address for each item in the list
	- Returns
		- Nothing

<br>

___

### **-: Node.h :-**
[=> _to store network node data in memory_]

#### **Included Libraries**

![Image](./xml/media/node.png "Node")

#### **Data Structure**

- Node has item count, item addresses

```
	typedef enum NODE_TYPE {
		N_Undefined
		, N_LinkedList
		, N_Stack
		, N_Queue
		, N_Tree
		, N_Graph
	} Node_Type;

	typedef struct NODE {
		Node_Type type;
		String* name;
		List* address_list;
		Data* data;
	} Node;
```

| Data Type | Varable Name | Usage |
| :---: | :---: | :---: |
| Enumeration | Node Type | to store Network type that the node belongs to |
| String Pointer | Name | to store name of the node |
| List Pointer | Address List | to store addresses of other linked nodes |
| Data Pointer | Data | to store any type of required data block |

#### **Utility Functions**

- Create Node
	- Takes
		1. Node type (enum) for Node block
	- Shows
		- Nothing
	- Returns
		- Pointer to Node object

<br>

- Duplicate Node
	- Takes
		1. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- New Pointer to copied Node object

<br>

- Delete Node
	- Takes
		1. Address of Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Set Node Name
	- Takes
		1. Pointer to Node object
		2. Length of String
		3. Address to character sequence
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display Node
	- Takes
		1. Pointer to Node object
	- Shows
		- Name of the Node
	- Returns
		- Nothing

<br>

- Display Node
	- Takes
		1. Pointer to Node object
	- Shows
		- Type, address, name, address-list, stored data of the Node
	- Returns
		- Nothing

<br>

___

### **-: Linked_List.h :-**
[=> _to store nodes as linked list format in memory_]

#### **Included Libraries**

![Image](./xml/media/linked_list.png "Linked List")

#### **Data Structure**

- Linked List has name, size, first node, last node

```
	typedef struct LINKED_LIST {
		String* name;
		int size;
		Node* first_node;
		Node* last_node;
	} Linked_List;
```

#### **Utility Functions**

- Create Linked List
	- Takes
		- Nothing
	- Shows
		- Nothing
	- Returns
		- Pointer to Linked List object

<br>

- Delete Linked List
	- Takes
		1. Address of Pointer to Linked List object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>


- Display Linked List
	- Takes
		1. Pointer to Linked List object
	- Shows
		- All the Nodes in the Linked List in linear fashion
	- Returns
		- Nothing

<br>

- Attach Node at first
	- Takes
		1. Pointer to Linked List object
		2. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Attach Node at last
	- Takes
		1. Pointer to Linked List object
		2. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Detach Node from first
	- Takes
		1. Pointer to Linked List object
	- Shows
		- Nothing
	- Returns
		- Pointer to copy of first Node object

<br>

- Detach Node from last
	- Takes
		1. Pointer to Linked List object
	- Shows
		- Nothing
	- Returns
		- Pointer to copy of last Node object

<br>

___

### **-: Stack.h :-**
[=> _to store nodes as stack format in memory_]

#### **Included Libraries**

![Image](./xml/media/stack.png "Stack")

#### **Data Structure**

- Stack has name, size, first node, last node

```
typedef Linked_List Stack;
```

#### **Utility Functions**

- Create Stack
	- Takes
		- Nothing
	- Shows
		- Nothing
	- Returns
		- Pointer to Stack object

<br>

- Delete Stack
	- Takes
		1. Pointer to Stack object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display Stack
	- Takes
		1. Pointer to Stack object
	- Shows
		- All the Nodes in the Stack
	- Returns
		- Nothing

<br>

- Push
	- Takes
		1. Pointer to Stack object
		2. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Pop
	- Takes
		1. Pointer to Stack object
	- Shows
		- Nothing
	- Returns
		- Pointer to copy of Node object

<br>

___

### **-: Queue.h :-**
[=> _to store nodes as queue format in memory_]

#### **Included Libraries**

![Image](./xml/media/queue.png "Queue")

#### **Data Structure**


- Queue has name, size, first node, last node

```
typedef Linked_List Queue;
```

#### **Utility Functions**

- Create Queue
	- Takes
		- Nothing
	- Shows
		- Nothing
	- Returns
		- Pointer to Queue object

<br>

- Delete Queue
	- Takes
		1. Pointer to Queue object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display Queue
	- Takes
		1. Pointer to Queue object
	- Shows
		- All Nodes in the Queue
	- Returns
		- Nothing

<br>

- Enqueue
	- Takes
		1. Pointer to Queue object
		2. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Dequeue
	- Takes
		1. Pointer to Queue object
	- Shows
		- Nothing
	- Returns
		- Pointer to copy of Node object

<br>

___

### **-: Tree.h :-**
[=> _to store nodes as tree format in memory_]

#### **Included Libraries**

![Image](./xml/media/tree.png "Tree")

#### **Data Structure**

- Linked List has name, size, first node, last node

```
	typedef struct TREE {
		Node* root_node;
		int node_count;
		int breadth;
		int depth;
	} Tree;
```

#### **Utility Functions**

- Create Tree
	- Takes
		- Nothing
	- Shows
		- Nothing
	- Returns
		- Pointer to Tree object

<br>

- Duplicate Tree
	- Takes
		1. Pointer to Tree object
	- Shows
		- Nothing
	- Returns
		- Pointer to copy of Tree object

<br>

- Delete Tree
	- Takes
		1. Address of Pointer to Tree object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Display Tree
	- Takes
		1. Pointer to Tree object
	- Shows
		- All the Nodes in the Tree
	- Returns
		- Nothing

<br>

- Set Root Node
	- Takes
		1. Pointer to Tree object
		2. Pointer to Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Get Root Node
	- Takes
		1. Pointer to Tree object
	- Shows
		- Nothing
	- Returns
		- Pointer to Root Node

<br>

- Get N th Child Node
	- Takes
		1. Pointer to Tree-Node object
		2. Index / Value of N
	- Shows
		- Nothing
	- Returns
		- Pointer to Tree-Node

<br>

- Get Parent Node
	- Takes
		1. Pointer to Tree-Node object
	- Shows
		- Nothing
	- Returns
		- Pointer to Parent Tree-Node object

<br>

- Append Child Node
	- Takes
		1. Pointer to Parent Tree-Node object
		2. Pointer to Child Tree-Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Push Tree-Node to Stack
	- Takes
		1. Pointer to Tree-Stack object
		2. Pointer to Tree-Node object
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

- Push Depth to Stack
	- Takes
		1. Pointer to Tree-Stack object
		2. Child node count
	- Shows
		- Nothing
	- Returns
		- Nothing

<br>

___

### **-: Graph.h :-**
[=> _to store nodes as graph format in memory_]

#### **Included Libraries**

![Image](./xml/media/graph.png "Graph")

#### **Data Structure**

#### **Utility Functions**

___