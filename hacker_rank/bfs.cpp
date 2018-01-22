#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Graph {
    public:
        
        int V;
        list <int> *adj;
    
        Graph(int n) {
            this->V = n;
            adj = new list <int>[n];
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {

            // initialize every distance as -1 so that disconnected nodes
            // have a distance of -1
            vector <int> distances(V, -1);
            queue <int> node_q;
            bool visited[V];
            for (int i = 0; i < V; i++) {
                visited[i] = false;
            }
            
            // adding the start node to the node_q
            node_q.push(start);
            distances[start] = 0;
            visited[start] = true;
            
            // starting the search
            while(!node_q.empty()) {
                int current_node = node_q.front();
                node_q.pop();
                // for every node in adj for the curr node
                for (auto node : adj[current_node]) {
                    if (visited[node] == false) {
                        visited[node] = true;
                        distances[node] = distances[current_node] + 6;
                        // cout << "the curr node is : " << node << endl;
                        node_q.push(node);
                    }
                }
            }
            return distances;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
