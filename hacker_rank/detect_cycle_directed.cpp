// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <limits.h>
#include <vector>

using namespace std;

struct Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool checkCycle(int, vector<bool>&, vector<bool>& ); // used by isCyclic()
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::checkCycle(int start_node, vector<bool>& visited, vector<bool>& rec_stack) {
    if (!visited[start_node]) {
        visited[start_node] = true;
        rec_stack[start_node] = true;
        for (auto node : adj[start_node]) {
            if (!visited[node]) {
                if (checkCycle(node, visited, rec_stack)) return true;
            }
            else if (rec_stack[node]) return true;
        }
    }
    rec_stack[start_node] = false;
    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(V, false);
    vector<bool> rec_stack(V, false);

    for (int u = 0; u < V; u++) {
        if (checkCycle(u, visited, rec_stack)) return true;
    }
    return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g1(9);
	g1.addEdge(1, 0);
	g1.addEdge(1, 8);
	g1.addEdge(2, 8);
	g1.addEdge(2, 5);
	g1.addEdge(5, 4);
	g1.addEdge(3, 5);
	g1.addEdge(3, 7);
	g1.addEdge(8, 3);
	g1.addEdge(3, 8);
	g1.isCyclic()? cout << "Graph contains cycle\n":
				cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic()? cout << "Graph contains cycle\n":
				cout << "Graph doesn't contain cycle\n";
	return 0;
}
