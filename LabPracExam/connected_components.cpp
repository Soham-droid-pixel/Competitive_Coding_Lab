#include <iostream>
#include <vector>

using namespace std;

// DFS function to visit all nodes in one connected component
void findComponent(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true; // Mark the current node as visited
    
    // Check all neighbors of the current node
    for (int v : adj[u]) {
        if (!visited[v]) { // If neighbor is not visited, go deeper
            findComponent(v, adj, visited);
        }
    }
}

int main() {
    int V = 7; // Total number of vertices
    vector<int> adj[V];

    // Component 1: Nodes 0, 1, 2
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);

    // Component 2: Nodes 3, 4
    adj[3].push_back(4); adj[4].push_back(3);

    // Component 3: Node 5 (Isolated)
    // Component 4: Node 6 (Isolated)

    vector<bool> visited(V, false); // Array to keep track of visited nodes
    int componentCount = 0;         // Variable to store the number of islands

    cout << "Starting Connected Components search..." << endl;

    // Iterate through every vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // If node 'i' hasn't been visited, it's a new component
            componentCount++; 
            cout << "Component " << componentCount << " starts at node: " << i << endl;
            findComponent(i, adj, visited); // Visit everything reachable from 'i'
        }
    }

    cout << "\nTotal Number of Connected Components: " << componentCount << endl;

    return 0;
}