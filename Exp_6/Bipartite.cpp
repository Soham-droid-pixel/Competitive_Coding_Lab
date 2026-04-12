#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

void runTest(string name, int V, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    Solution sol;
    cout << "TEST: " << name << " -> " << (sol.isBipartite(V, adj) ? "BIPARTITE" : "NOT BIPARTITE") << endl;
}

int main() {
    runTest("Linear Path (0-1-2-3)", 4, {{0, 1}, {1, 2}, {2, 3}});
    runTest("Even Cycle (Square)", 4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}});
    runTest("Odd Cycle (Triangle)", 3, {{0, 1}, {1, 2}, {2, 0}});
    runTest("Disconnected Bipartite", 6, {{0, 1}, {2, 3}, {4, 5}});
    runTest("Single Node", 1, {});

    return 0;
}