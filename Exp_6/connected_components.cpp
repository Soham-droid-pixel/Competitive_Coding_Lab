#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int countComponents(int V, vector<pair<int, int>> edges) {
        if (V <= 0) return 0;

        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        vector<bool> visited(V, false);
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return components;
    }
};

void runTest(string title, int V, vector<pair<int, int>> edges) {
    Solution sol;
    cout << title << ": " << sol.countComponents(V, edges) << " component(s)" << endl;
}

int main() {
    runTest("Standard Case (Two Islands)", 5, {{0, 1}, {1, 2}, {3, 4}});
    runTest("Fully Connected Graph", 4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}});
    runTest("Fully Disconnected Nodes", 4, {});
    runTest("Complex Multiple Components", 6, {{0, 1}, {2, 3}, {4, 5}});
    runTest("Single Node", 1, {});
    runTest("Empty Graph", 0, {});

    return 0;
}