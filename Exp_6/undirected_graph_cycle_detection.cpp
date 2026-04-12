#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(int u, int p, vector<int> adj[], vector<bool>& vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u, adj, vis)) return true;
            } else if (v != p) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};

void runTest(string title, int V, vector<pair<int, int>> edges) {
    vector<int> adj[V];
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    Solution sol;
    cout << title << " -> " << (sol.hasCycle(V, adj) ? "CYCLE DETECTED" : "NO CYCLE") << endl;
}

int main() {
    runTest("Square Cycle (0-1-2-3-0)", 4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}});
    runTest("Linear Path (0-1-2-3)", 4, {{0, 1}, {1, 2}, {2, 3}});
    runTest("Disconnected with Cycle", 6, {{0, 1}, {2, 3}, {3, 4}, {4, 2}});
    runTest("Disconnected without Cycle", 6, {{0, 1}, {2, 3}, {4, 5}});
    runTest("Triangle Cycle (0-1-2-0)", 3, {{0, 1}, {1, 2}, {2, 0}});
    runTest("Single Node", 1, {});
    runTest("Self-Loop Cycle", 2, {{0, 1}, {1, 1}});

    return 0;
}