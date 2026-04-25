#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to check if a component is bipartite using BFS
bool isBipartite(int start, int V, vector<int> adj[], vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring the first node with color 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // If the neighbor has not been colored yet
            if (color[v] == -1) {
                color[v] = 1 - color[u]; // Color it with the opposite color (0 -> 1 or 1 -> 0)
                q.push(v);
            } 
            // If the neighbor has the same color as the current node, it's not bipartite
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true; // If we finish BFS without conflicts, this component is bipartite
}

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Example 1: A Square (Bipartite)
    // 0 -- 1
    // |    |
    // 3 -- 2
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[3].push_back(0); adj[0].push_back(3);

    // Initialize color array with -1 (uncolored)
    vector<int> color(V, -1);
    bool bipartite = true;

    // Loop through all nodes to handle disconnected components
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartite(i, V, adj, color)) {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite) cout << "The Graph is Bipartite" << endl;
    else cout << "The Graph is NOT Bipartite" << endl;

    return 0;
}