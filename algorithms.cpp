/*    noamgal46@gmail.com    */



#include "algorithms.hpp"

using namespace graph;

Graph Algorithms::bfs(int start, Graph& graph) {
    if ((start < 0 || start >= graph.getNumVertices())){
        throw std::invalid_argument("you put invalid argument");
    }
    int numVertices = graph.getNumVertices();
    Graph ansTree(numVertices);
    MyQueue queue;
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    visited[start] = true;
    queue.put(start);
    cout << "BFS starting from vertex " << start << ": ";
    while (!queue.empty()) {
        int current = queue.get(); // Get the front vertex from the queue
        cout << current << " "; // Print the current vertex

        // Traverse the adjacency list of the current vertex
        if (!graph.getAdjacencyList()[current].isEmpty()){
            for(int i = 0; i < graph.getAdjacencyList()[current].getNumOfElements(); i++){
                if (!visited[graph.getAdjacencyList()[current].get(i).getDestination()]){
                    visited[graph.getAdjacencyList()[current].get(i).getDestination()] = true;
                    queue.put(graph.getAdjacencyList()[current].get(i).getDestination());
                    ansTree.addEdge(current, graph.getAdjacencyList()[current].get(i).getDestination());
                }
            }
        }
    }

    cout << endl;
    delete[] visited; // Free the visited array memory
    return ansTree;
}

Graph Algorithms::dfs(int start, Graph& graph){
    if ((start < 0 || start >= graph.getNumVertices())){
        throw std::invalid_argument("you put invalid argument");
    }
    int numVertices = graph.getNumVertices();
    Graph ansTree(numVertices);
    MyStack stack; 
    bool* black = new bool[numVertices];
    bool* gray = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        black[i] = false;
        gray[i] = false;
    }
    stack.push(start);
    cout << "DFS starting from vertex " << start << ": ";   
    while (!stack.empty()) {
        int current = stack.peek();
        gray[current] = true;
        cout << current << " "; 
        bool haveWhiteChild = false;
        if (!graph.getAdjacencyList()[current].isEmpty()){
            for(int i = 0; i < graph.getAdjacencyList()[current].getNumOfElements(); i++){
                int destination = graph.getAdjacencyList()[current].get(i).getDestination();
                if (!gray[destination] && !black[destination]){
                    haveWhiteChild = true;
                    gray[destination] = true;
                    stack.push(destination);
                    ansTree.addEdge(current, destination);
                    break;
                }
            }
            if (!haveWhiteChild){
                black[current] = true;
                stack.remove();
            }

        }
        else{
            stack.remove();
        }
        if (stack.empty()){
            for(int i = 0; i < numVertices; i++){
                if(black[i] == false && gray[i] == false){
                    stack.push(i);
                    gray[i] = true;
                    break;
                }
            }
        }
    }

    cout << endl;
    delete[] black; // Free the visited array memory
    delete[] gray; // Free the visited array memory
    return ansTree;            
}
Graph Algorithms::dijkstra(int start, Graph& graph) {
    int numVertices = graph.getNumVertices();
    if (start < 0 || start >= numVertices) {
        throw std::invalid_argument("Invalid start vertex");
    }
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < graph.getAdjacencyList()[i].getNumOfElements(); j++) {
            if (graph.getAdjacencyList()[i].get(j).getWeight() < 0) {
                throw std::invalid_argument("Graph contains negative edge weight");
            }
        }
    }
    Graph ansTree(numVertices);
    PriorityQueue myPQ;
    int* distanceFromStart = new int[numVertices];
    int* pathFromStart = new int[numVertices];
    for (int i = 0; i < numVertices; i++) {
        distanceFromStart[i] = INT16_MAX;
        pathFromStart[i] = -1;
        myPQ.add(Edge(i, -1, INT16_MAX));
    }
    distanceFromStart[start] = 0;
    myPQ.get(start).setWeight(0);  
    while (!myPQ.empty()) {
        Edge currentVertex = myPQ.extractMin();
        int u = currentVertex.getOrigin();
        for (int i = 0; i < graph.getAdjacencyList()[u].getNumOfElements(); i++) {
            Edge neighborEdge = graph.getAdjacencyList()[u].get(i);
            int v = neighborEdge.getDestination();
            int weight = neighborEdge.getWeight();

            if (distanceFromStart[v] > distanceFromStart[u] + weight) {
                distanceFromStart[v] = distanceFromStart[u] + weight;
                pathFromStart[v] = u;
                for (int j = 0; j < myPQ.getSize(); j++) {
                    if (myPQ.get(j).getOrigin() == v) {
                        myPQ.get(j).setWeight(distanceFromStart[v]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < numVertices; i++) {
        if (pathFromStart[i] != -1) {
            int from = pathFromStart[i];
            int to = i;
            int weight = distanceFromStart[i];
            ansTree.addEdge(from, to, weight);
        }
    }
    delete[] distanceFromStart;
    delete[] pathFromStart;
    return ansTree;
}
Graph Algorithms::prim(Graph& graph){
    int numVertices = graph.getNumVertices();
    Graph check(1);
    check = bfs(0 , graph);
    for (int i = 0; i < check.getNumVertices(); i++) {
        if (check.getAdjacencyList()[i].isEmpty() && check.getNumVertices() != 1){
            throw std::invalid_argument("error: disconnected graph");
        }
    }
    Graph ansTree(numVertices);
    PriorityQueue myPQ; 
    int* distanceFromStart = new int[numVertices];
    int* pathFromStart = new int[numVertices];
    for (int i = 0; i < numVertices; i++) {
        myPQ.add(Edge(i, -1, INT16_MAX));
        distanceFromStart[i] = INT16_MAX; // suppose INT16_MAX is infinity
        pathFromStart[i] = -1;
    }
    distanceFromStart[0] = 0;
    myPQ.get(0).setWeight(0);

    while (!myPQ.empty()){
        Edge currentVertex = myPQ.extractMin();
        int u = currentVertex.getOrigin();
        for(int i = 0; i < graph.getAdjacencyList()[u].getNumOfElements(); i++){
            int v = graph.getAdjacencyList()[u].get(i).getDestination();
            int weight = graph.findEdge(u, v).getWeight();
            for (int j = 0; j < myPQ.getSize(); j++){
                if (myPQ.get(j).getOrigin() == v && weight < distanceFromStart[v]){
                    pathFromStart[v] = u;
                    distanceFromStart[v] = weight;
                    myPQ.get(j).setWeight(distanceFromStart[v]);

                    break;
                }
            }

        }

        
    }
    for (int i = 0; i < numVertices; i++) {
        if (pathFromStart[i] != -1) {
            int from = pathFromStart[i];
            int to = i;
            int weight = graph.findEdge(from, to).getWeight();
            ansTree.addEdge(from, to, weight);
        }
    }

    delete[] distanceFromStart;
    delete[] pathFromStart;
    return ansTree;
}
Graph Algorithms::kruskal(Graph& graph){
    int numVertices = graph.getNumVertices();
    Graph ansTree(numVertices);
    UnionFind unionFind;
    Graph check(1);
    check = bfs(0 , graph);
    for (int i = 0; i < check.getNumVertices(); i++) {
        if (check.getAdjacencyList()[i].isEmpty() && check.getNumVertices() != 1){
            throw std::invalid_argument("error: disconnected graph");
        }
    }
    for (int i = 0; i < numVertices; i++) {
        unionFind.add(Pair(i, i));
    }
    DynamicList<Edge> allEdges;
    for (int i = 0; i < numVertices; i++){
        for (int j = 0; j < graph.getAdjacencyList()[i].getNumOfElements(); j++){
            allEdges.add(graph.getAdjacencyList()[i].get(j));
        }
    }
    for(int i = 0; i < allEdges.getNumOfElements(); i++){
        for (int j = i + 1; j < allEdges.getNumOfElements(); j++){
            if (allEdges.get(i).getWeight() > allEdges.get(j).getWeight()){
                Edge temp = allEdges.get(j);
                allEdges.get(j) = allEdges.get(i);
                allEdges.get(i) = temp;
            }
        }
    }
    for(int i = 0; i < allEdges.getNumOfElements(); i++){
        if (unionFind.find(allEdges.get(i).getDestination()) != unionFind.find(allEdges.get(i).getOrigin())){
            unionFind.makeUnion(unionFind.find(allEdges.get(i).getDestination()), unionFind.find(allEdges.get(i).getOrigin()));
            ansTree.addEdge(allEdges.get(i).getOrigin(), allEdges.get(i).getDestination(), allEdges.get(i).getWeight());
        }
    }
    return ansTree;
} 