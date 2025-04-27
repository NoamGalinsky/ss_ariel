# ReadMe
in this file i will explain all my function in my project
## data_structure

Declared in `data_structure.hpp`. `DynamicList` and `Pair` are fully implemented in the header due to template usage.

### DynamicList

A dynamic array-based list of type `T`.
implemented by dinamic array of T.

- `resize()` – Doubles the array size when full.
- **Constructor** – Initializes an array of size 10.
- `operator=` – Copies components from another `DynamicList`.
- `add()` – Appends a new element.
- `getNumOfElements()` – Returns the number of stored elements.
- `remove()` – Removes the last element.
- `remove(index)` – Removes the element at a given index.
- `get(index)` – Returns reference to the element at index.
- `isEmpty()` – Checks if the list is empty.

### Pair

A basic key-value structure with getter and setter functions.

### Edge

Represents a edge:  
`origin`, `destination`, and `weight`.

- `get()` and `set()` – Access or modify fields.
- `operator=` / `operator==` – Copy or compare edges.
- `relax()` – For Dijkstra's algorithm. Updates destination if a shorter path is found.

### MyQueue

A simplified queue implementation.

- `put()` – Adds an element at the end.
- `get()` – Retrieves and removes the front element.
- `empty()` – Returns `true` if empty.

### MyStack

A minimal stack.

- `push()` – Adds an element to the top.
- `peek()` – Views the top element.
- `remove()` – Removes the top element.
- `empty()` – Checks if stack is empty.

### PriorityQueue

A priority queue for vertex, sorted by weight.
origin is the vertex number, and weight is disstance from start.

- `add()`, `empty()`, `getSize()` – Basic operations.
- `extractMin()` – Removes and returns the vertex with the smallest weight.

### UnionFind

Union-Find structure using `Pair`.

- `add()` – Adds an element with a unique group.
- `find()` – Returns the group of a vertex.
- `makeUnion()` – Merges two groups.

## graph

Graph is represented using an array of `DynamicList`.  
Each index `i` represents the neighbors of vertex `i`.

- **Constructor / Copy Constructor** – Initializes graph with a given number of vertices.
- `addEdge()` – Adds a sorted edge to the vertex list.
- `edgeExist()` – Checks if an edge exists.
- `removeEdge()` – Deletes a specific edge.
- `printGraph()` – Outputs graph structure.
- `getNumVertix()` – Returns number of vertices.
- `findEdge()` – Finds and returns an edge, or `Edge(-1, -1, -1)` if not found.

## algorithms

Algorithms are implemented based on the *Algorithms 1* university course.

## main

The `main` function is interactive and lets the user add a graph and test algorithms.

### input1.txt

A file with a sample graph. Can be run with `Main_with_input1`.

### input2.txt

Another test file with a disconnected graph. Can be run with `Main_with_input2`.

## test_function

Includes unit tests for the project's major features.

- `strPrint()` – Converts graphs to string format for easy comparison.
  
## 🛠 makefile

Includes standard and extended targets:

- `test` – Runs unit tests.
- `Main` – Compiles and runs the main program.
- `valgrind` – Checks for memory issues.
- `clean` – Removes compiled files.
- `Main_with_input1` – Runs main with `input1.txt`.
- `Main_with_input2` – Runs main with `input2.txt`.

## AI
i am using AI to edit the readme file and make him more comfortable for reading.
you can see the first version in the first commit in project 1.

