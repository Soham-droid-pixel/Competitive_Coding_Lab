#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int V, vector<pair<int, int>>& edges) {
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        vector<int> topoOrder;

        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);
            count++;

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (count != V) return {}; 

        return topoOrder;
    }
};

int main() {
    int V = 6;
    vector<pair<int, int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    Solution sol;
    vector<int> result = sol.findOrder(V, edges);

    if (result.empty()) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "Topological Sort Order: ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}