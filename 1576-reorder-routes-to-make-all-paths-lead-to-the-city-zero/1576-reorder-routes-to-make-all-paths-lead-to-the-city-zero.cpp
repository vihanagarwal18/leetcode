#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    void dfs(int& result, vector<vector<pair<int, int>>>& adj, int node, vector<int>& visited) {
        visited[node] = 1;
        for (auto& p : adj[node]) {
            if (!visited[p.first]) {
                if (p.second == -1) result++; // Count the reverse edge that needs to be reordered
                dfs(result, adj, p.first, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& p : connections) {
            adj[p[0]].push_back({p[1], -1}); // -1 means reverse edge (needs reorder)
            adj[p[1]].push_back({p[0], 1});  // 1 means correct edge
        }
        int result = 0;
        vector<int> visited(n, 0);
        dfs(result, adj, 0, visited);
        return result;
    }
};
