#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Graph {
public:
    void findShortestPaths(string testName, int V, vector<pair<int, int>> edges, int source) {
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        vector<int> dist(V, -1);
        queue<int> q;

        dist[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << "--- " << testName << " ---" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << (dist[i] == -1 ? "INF" : to_string(dist[i])) << endl;
        }
        cout << "-------------------------------" << endl;
    }
};

int main() {
    Graph g;

    g.findShortestPaths("Standard Connected Graph", 6, 
        {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {4, 5}}, 0);

    g.findShortestPaths("Disconnected Islands", 5, 
        {{0, 1}, {1, 2}, {3, 4}}, 0);

    g.findShortestPaths("Circular Graph", 4, 
        {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 0);

    g.findShortestPaths("Single Node", 1, {}, 0);

    g.findShortestPaths("Line Graph (Longest Path)", 4, 
        {{0, 1}, {1, 2}, {2, 3}}, 0);

    return 0;
}