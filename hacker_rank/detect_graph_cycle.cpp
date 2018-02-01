// A C++ Program to detect cycle in an undirected graph
#include<iostream>
#include <list>
#include <limits.h>
#include <vector>
using namespace std;

// Class for an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle
	bool checkCycle(int, vector<bool>&, int);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Add v to w’s list.
}

bool Graph :: checkCycle(int start_node, vector<bool>& visited, int parent) {
    visited[start_node] = true;
    for (auto node : adj[start_node]) {
        if (!visited[node]) {
            // cout << "the visited node is : " << node << endl;
            if (checkCycle(node, visited, start_node))
                return true;
            // return checkCycle(node, visited, start_node);
        }
        else if (visited[node] && node!=parent) return true;
    }
    return false;
}

bool Graph :: isCyclic()
{
    vector<bool>visited(V, false);
    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            // cout << "the val of u is : " << u << endl;
            return checkCycle(u, visited, -1);
        }
    }
}

// Driver program to test above functions
int main()
{
	Graph g1(10);
	g1.addEdge(1, 0);
	g1.addEdge(1, 8);
	g1.addEdge(2, 8);
	g1.addEdge(2, 5);
	g1.addEdge(5, 4);
	g1.addEdge(3, 5);
	g1.addEdge(3, 7);
	g1.addEdge(8, 3);
	g1.isCyclic()? cout << "Graph contains cycle\n":
				cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic()? cout << "Graph contains cycle\n":
				cout << "Graph doesn't contain cycle\n";

	return 0;
}
