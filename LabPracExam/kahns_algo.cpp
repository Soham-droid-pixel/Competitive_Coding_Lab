#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V]; // Adjacency list
    
    // 1. Manually adding edges (Directed Acyclic Graph)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // 2. Array to store in-degree (number of incoming edges) for each vertex
    vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto neighbor : adj[i]) {
            in_degree[neighbor]++; // Increment in-degree for every destination node
        }
    }

    // 3. Queue to store vertices with 0 in-degree (ready to be processed)
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i); // Start with nodes that have no prerequisites
        }
    }

    vector<int> topo_order; // Vector to store the result
    int count = 0;          // Counter for visited nodes to detect cycles

    // 4. Process the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u); // Add node to the final sequence

        // 5. For each neighbor of the popped node, "remove" the edge
        for (auto v : adj[u]) {
            if (--in_degree[v] == 0) { // Decrease in-degree and check if it's now 0
                q.push(v);             // If 0, it's ready to be processed
            }
        }
        count++; // Keep track of how many nodes we've processed
    }

    // 6. Output logic
    if (count != V) {
        cout << "The graph contains a cycle! Topological sort is not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int node : topo_order) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}